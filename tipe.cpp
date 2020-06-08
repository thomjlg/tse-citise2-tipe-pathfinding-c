#include <iostream>
using namespace std;
#include <math.h>
#include"tipe.h"

/////////////// INITIALISATION MATRICE AVEC 000 ///////////
void initialisation_matrice_0(unsigned int mat[50][50]) {
    unsigned int i, j;
    i = 0;
    while (i <= 49) {

        j = 0;
        while (j <= 49) {
            mat[i][j] = 0;
            j++;
        }
        i++;
    }
}
/////////////// FIN INITIALISATION MATRICE AVEC 000 ///////

////////////// FONCTION MENU //////////////////////////////
void choix(unsigned int matrice_adjacence[50][50], unsigned int rang) {
    unsigned int choix;
    unsigned int * ptr(0);
    ptr = new unsigned int;
    ptr = (unsigned int *)matrice_adjacence[50][50];
    unsigned int rang3;
    valeurs_a_retouner valeurs;
    unsigned int de, da; //sommets depart et arrivee
    
    cout << " ----------------------- MENU -----------------------" << endl;
    cout << " 1 -- Saisir une matrice d'adjacence\n 2 -- Modifier des valeurs de la matrice d'adjacence\n 3 -- Afficher matrice d'adjacence" << endl;
    cout << " 4 -- Changer la valeur du rang de la matrice" << endl;
    cout << " 5 -- Lancer algorithme pathfinding" << endl;
    cout << endl << " 666 -- QUITTER PROGRAMME" << endl;
    cout << " ----------------------- MENU -----------------------" << endl;
    cout << endl << "Votre choix : ";
    cin >> choix;
    // 1 saisie matrice
    // 2 modifier valeur matrice
    // 3 afficher matrice
    // 4
    // 5 lancer dijkstra
    

    if (choix == 1) {
        saisie_matrice(matrice_adjacence, rang);
        cout << endl << "Affichage de votre matrice : " << endl;
        afficher_matrice(matrice_adjacence, rang);
    }
    if (choix == 2) {
        modifier_matrice(matrice_adjacence,rang);
    }
    if (choix == 3) {
        afficher_matrice(matrice_adjacence, rang);
    }
    if (choix == 4) {
        rang = changer_rang(matrice_adjacence, rang);
        choix1(matrice_adjacence, rang);
    }
    if (choix == 5) {
        unsigned int puissance_tab[50][50];
        initialisation_matrice_0(puissance_tab);
        cout << "Saisir sommet depart : ";
        cin >> de;
        while(de > rang){
            cout << " ERREUR - Saisir sommet depart : ";
            cin >> de;
        }
        cout << "Saisir sommet d'arrivee : ";
        cin >> da;
        while(da > rang){
            cout << " ERREUR - Saisir sommet d'arrivee : ";
            cin >> da;
        }
        existence_chemin(matrice_adjacence, de, da, rang);
        //dijkstra(matrice_adjacence, de - 1, da - 1, rang);
        //choix1(matrice_adjacence, rang);
    }
    if (choix == 666) {
        exit(EXIT_SUCCESS);
    }
    if (choix != 1 || choix != 2 || choix != 3 || choix != 4 || choix != 5 || choix != 666) {
        cout << "ERREUR de saisie !\nVotre valeur ne correspond a aucune rubrique !" << endl << endl;
        choix1(matrice_adjacence,rang);
    }
}

void choix1(unsigned int matrice_adjacence[50][50], unsigned int rang){
    choix(matrice_adjacence, rang);
}
////////////// FIN FONCTION MENU //////////////////////////


////////////// FONCTION SAISIE MATRICE ////////////////////
void saisie_matrice(unsigned int matrice_adjacence[50][50], unsigned int rang) {
    unsigned int i = 0, j = 0, k, l, valeur;
    unsigned int * ptr;
    ptr = new unsigned int;
    ptr = (unsigned int *)matrice_adjacence[i][j];

    k = 0;
    while (k <= rang - 1) {//nb de valeurs tableau et indices allant de 0 à n-1
        l = 0;
        while (l <= rang - 1) {
            cout << "Saisir la valeur de la case " << k + 1 << "," << l + 1 << " : " << endl;
            cin >> valeur;
            while (valeur < 0 && valeur > 65000) {
                cout << " ERREUR, nombre negatif interdit !\n Merci de saisir une nouvelle valeur : ";
                cin >> valeur;
            }

            ptr = &matrice_adjacence[k][l];
            *ptr = valeur;
            l++;
        }
        k++;
    }
}
////////////// FIN FONCTION SAISIE MATRICE ////////////////


////////////// FONCTION MODIFIER MATRICE //////////////////
void modifier_matrice(unsigned int matrice_adjacence[50][50], unsigned int rang) {
    unsigned int i = 0, j = 0, nouvelle_valeur;
    char reponse;
    unsigned int * ptr;
    ptr = new unsigned int;
    ptr = (unsigned int *)matrice_adjacence[i][j];

    cout << " Quelle valeur de la matrice souhaitez-vous modifier ? \n Saisir la ligne : ";
    cin >> i;
    while (i == 0 || i > rang) {
        cout << " ERREUR,\n Saisir une ligne correcte : ";
        cin >> i;
    }
    cout << " Saisir la colonne : ";
    cin >> j;
    while (j == 0 || j > rang) {
        cout << " ERREUR,\n Saisir une colonne correcte : ";
        cin >> j;
    }
    cout << " \nSaisir la nouvelle valeur que vous souhaitez ecrire : ";
    cin >> nouvelle_valeur;

    ptr = &matrice_adjacence[i - 1][j - 1];
    *ptr = nouvelle_valeur;

    cout << " \nVoulez-vous modifier une autre valeur ? (o/n)";
    cin >> reponse;
    
    while (reponse == 'o' || reponse == 'O') {
        cout << " Quelle valeur de la matrice souhaitez-vous modifier ? \n Saisir la ligne : ";
        cin >> i;
        while (i == 0 || i > rang) {
            cout << " ERREUR,\n Saisir une ligne correcte : ";
            cin >> i;
        }
        cout << " Saisir la colonne : ";
        cin >> j;
        while (j == 0 || j > rang) {
            cout << " ERREUR,\n Saisir une colonne correcte : ";
            cin >> j;
        }
        cout << " \nSaisir la nouvelle valeur que vous souhaitez ecrire : ";
        cin >> nouvelle_valeur;

        ptr = &matrice_adjacence[i - 1][j - 1];
        *ptr = nouvelle_valeur;

        cout << " \nVoulez-vous modifier une autre valeur ? (o/n)";
        cin >> reponse;
    }
    if(reponse=='n'||reponse=='N'){
        cout << endl;
        afficher_matrice(matrice_adjacence, rang);
        choix(matrice_adjacence,rang);
    }
}
////////////// FIN FONCTION MODIFIER MATRICE //////////////


////////////// FONCTION AFFICHE MATRICE ///////////////////
void afficher_matrice(unsigned int matrice_adjacence[50][50], unsigned int rang) {
    unsigned int k, l;
    k = 0;
    cout << endl;
    cout << " M = " << endl;
    while (k <= rang - 1) {//nb de valeurs tableau et indices allant de 0 à n-1
        
        cout << "| ";
        l = 0;
        while (l <= rang - 1) {
            cout << matrice_adjacence[k][l] << " ";
            l++;
        }
        cout << "|" << '\0' << endl;
        k++;
    }
    cout << endl;
    choix(matrice_adjacence, rang);
}
////////////// FIN FONCTION AFFICHE MATRICE ///////////////


/////////////// CALCUL DE L'EXISTENCE D'UN CHEMIN ///////////////////////////////////////////////
void existence_chemin(unsigned int tab[50][50], unsigned int i, unsigned int j, unsigned int rang) {
    unsigned int n = 1;
    unsigned int r, s, ta; /* indices courants */
    unsigned int puissance_tab[50][50];
    initialisation_matrice_0(puissance_tab);
    unsigned int puissance_tab2[50][50];
    initialisation_matrice_0(puissance_tab2);
    unsigned int puissance_tab3[50][50];
    initialisation_matrice_0(puissance_tab3);

    if (tab[i - 1][j - 1] != 0) {
        cout << endl << " Chemin direct de poids "<< tab[i - 1][j - 1] <<" existant entre les sommets " << i << " et " << j << "." << endl;
        //afficher_matrice(tab, rang);
        n++;
        dijkstra(tab, i - 1, j - 1, rang);
    }
    else {    // (tab[i - 1][j - 1] == 0)
        cout << endl << " Chemin direct entre les sommets " << i << " et " << j << " inexistant.\n Poursuite des recherches en cours ..." << endl;
//              boucle 1
            unsigned int p, q, r;
            for (p = 0; p < rang; p++)
            {
                for (q = 0; q < rang; q++)
                {
                    for (r = 0; r < rang; r++)
                    {
                        puissance_tab[p][q] += tab[p][r] * tab[r][q];
                    }
                }
            }
            

        if (puissance_tab[i - 1][j - 1] != 0) {
            cout << " \nCONCLUSION :\n Chemin existant entre les sommets " << i << " et " << j << "." << endl;
            //cout << "\n\nAffichage de la matrice a l'ordre " << t - 1;
            //afficher_matrice(puissance_tab, rang);
            dijkstra(tab, i - 1, j - 1,rang);
        }
        else {
//            boucle 2
            unsigned int s, t, u;
            for (s = 0; s < rang; s++)
            {
                for (t = 0; t < rang; t++)
                {
                    for (u = 0; u < rang; u++)
                    {
                        puissance_tab2[s][t] += puissance_tab[s][u] * tab[u][t];
                    }
                }
            }

            if (puissance_tab2[i - 1][j - 1] != 0) {
                cout << " \nCONCLUSION :\n Chemin existant entre les sommets " << i << " et " << j << "." << endl;
                //cout << "\n\nAffichage de la matrice a l'ordre " << t - 1;
                //afficher_matrice(puissance_tab, rang);
                dijkstra(tab, i - 1, j - 1, rang);
            }
            else {
//            boucle 3
                unsigned int aaa, ttt, uuu;
                for (aaa = 0; aaa < rang; aaa++)
                {
                    for (ttt = 0; ttt < rang; ttt++)
                    {
                        for (uuu = 0; uuu < rang; uuu++)
                        {
                            puissance_tab3[aaa][ttt] += puissance_tab2[aaa][uuu] * puissance_tab[uuu][ttt];
                        }
                    }
                }

                if (puissance_tab3[i - 1][j - 1] != 0) {
                    cout << " \nCONCLUSION :\n Chemin existant entre les sommets " << i << " et " << j << "." << endl;
                    //cout << "\n\nAffichage de la matrice a l'ordre " << t - 1;
                    //afficher_matrice(puissance_tab, rang);
                    dijkstra(tab, i - 1, j - 1, rang);
                }
                else{
                    cout << " \nCONCLUSION :\n Aucun chemin n'existe donc entre les sommets " << i << " et " << j << " sur ce graphe." << endl;
                }
            }
        }
    }
    cout << endl;
    choix(tab,rang);
    
    
    
    
    
    
    
    unsigned int puissanceSuccessive[50][50];
    initialisation_matrice_0(puissanceSuccessive);
    
    puissanceSuccessive = rechercheLoop(tab[50][50],puissanceSuccessive[50][50], rang, i, j)
    while(puissanceSuccessive[i - 1][j - 1] == 0){
        puissanceSuccessive1[50][50] = rechercheLoop(tab[50][50], puissanceSuccessive[50][50], rang, i, j)
    }

    
    
    
    
}


unsigned int rechercheLoop(unsigned int tab1[50][50], unsigned int tab2[50][50], unsigned int rang, unsigned int i, unsigned int j){
    unsigned int successivePower[50][50];
    unsigned int s, t, u;
    
    for (s = 0; s < rang; s++) {
        for (t = 0; t < rang; t++) {
            for (u = 0; u < rang; u++) {
                successivePower[s][t] += tab1[s][u] * tab2[u][t];
            }
        }
    }
    return successivePower[50][50];
}







/////////////// FIN CALCUL DE L'EXISTENCE D'UN CHEMIN ///////////////////////////////////////////

/////////////// CHANGER RANG ///////////////////////////////////////////
unsigned int changer_rang(unsigned int matrice_adjacence[50][50], unsigned int rang) {
    unsigned int new_rang;
    cout << " Saisir le nouveau rang de la matrice d'adjacence : ";
    cin >> new_rang;
    while (new_rang == 0 || new_rang > 50) {
        cout << " ERREUR de saisie !\n Merci de saisir une valeur entre 1 et 50 : ";
        cin >> new_rang;
    }
    rang = new_rang;
    return rang;
}
/////////////// FIN CHANGER RANG ///////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////
////////////////////////////////   DIJKSTRA ////////////////////////////////
////////////////////////////////////////////////////////////////////////////

//fonctions pour dijstkra :

/////////////// minDISTANCE ////////////////////////////////////////////////
// min distance(distance deja acquise , un bool...) test pour savoir quelle sommet adjacent a le poinds d arretes le plus faible
unsigned int minDistance(unsigned int dist[], bool tabparcouru[],unsigned int rang)
{
    // Initialisation de la valeur de min
    unsigned int min = INT_MAX, min_index;
    //pour toutes arretes du sommmet
    for (unsigned int v = 0; v < rang ; v++)
        if (tabparcouru[v] == false && dist[v] <= min) // si nouveau sommets non parcouru et avec la plus petite distance
            min = dist[v], min_index = v; // on chagee la distance min par la nouvelle distance et on change le nom du sommet

    return min_index; // return le numéro du sommet
}
/////////////// FIN minDISTANCE ////////////////////////////////////////////

/////////////// Affichage_Sol //////////////////////////////////////////////
//cout du resultat :
void Affichage_Sol(unsigned int dist[], unsigned  int n, unsigned  int src, unsigned  int fn, unsigned int antecedant[])
{
    unsigned int i = 0;
    cout << endl << " Le chemin le plus court a un poids de ";
    cout << dist[fn] <<"." << endl;
    cout << " \nChemin parcouru : " << endl;
//affichage du chemin
    while (fn != src) {
        cout << " - On arrive au sommet numero " << fn + 1;
        cout << " en passant par le sommet numero " << antecedant[fn] + 1 << "." << endl;
        fn = antecedant[fn];
    }
}
/////////////// FIN Affichage_Sol //////////////////////////////////////////

/////////////// FONCTION DIJKSTRA //////////////////////////////////////////

void dijkstra(unsigned int graph[50][50], unsigned int src, unsigned  int fn, unsigned int rang)
{
    unsigned int antecedant[50];// tableau des atecedants

    unsigned int dist[50];     //tableau qui contient la plus courte distance de la source au sommet i

    bool tabparcouru[50]; // tableau de booléen qui nous renseigne si le sommet a déja été parcouru

                    // on iniatialise toutes les distances a l'INFINI et stpSet[] a false
    for (unsigned int i = 0; i < rang; i++)
        dist[i] = INT_MAX, tabparcouru[i] = false;

    // on commence forcément avec une distance de 0
    dist[src] = 0;

    //trouve le chemin le plus courts pour chaque sommet
    for (unsigned int so = 0; so < rang - 1; so++)
    {
        //trouve le sommet qui a le chemin le plus court de la source ou du sommet en cours
        unsigned int u = src;
        u = minDistance(dist, tabparcouru,rang);

        // on met le sommet en tant que déja parcouru
        tabparcouru[u] = true;

        // met a jour la nouvelle valeur de distance de la source au sommet u
        for (unsigned int v = 0; v < rang; v++)

            // met a jour dist[v] que si on est pas passé par ce sommet, si il y a une arretes entre u et v
            // , et si la dist entre src et v en passant par u est plus petit que dist[v]
            if (!tabparcouru[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                antecedant[v] = u;
            }
    }

    // cout de la sol
    Affichage_Sol(dist, rang, src, fn, antecedant);

}
/////////////// FIN FONCTION DIJKSTRA //////////////////////////////////////
