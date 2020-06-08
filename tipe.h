void initialisation_matrice_0(unsigned int mat[50][50]); //OK
void choix(unsigned int matrice_adjacence[50][50], unsigned int); //OK
void choix1(unsigned int matrice_adjacence[50][50], unsigned int); //OK
void modifier_matrice(unsigned int matrice_adjacence[50][50], unsigned int); //OK
void saisie_matrice(unsigned int matrice_adjacence[50][50], unsigned int); //OK
void afficher_matrice(unsigned int matrice_adjacence[50][50], unsigned int); //OK
unsigned int changer_rang(unsigned int matrice_adjacence[50][50], unsigned int);
void existence_chemin(unsigned int matrice_adjacence[50][50], unsigned int, unsigned int, unsigned int);
unsigned int minDistance(unsigned int dist[], bool sptSet[], unsigned int rang);
void Affichage_Sol(unsigned int dist[], unsigned  int n, unsigned  int src, unsigned  int fn, unsigned  int antecedant[]);
void dijkstra(unsigned int graph[50][50], unsigned  int src, unsigned  int fn, unsigned int rang);

struct valeurs_a_retouner {
    unsigned int n; //nb d'aretes du chemin possible
    unsigned int N; //nb de chemins possibles de longueur n
    unsigned int *tab;
};



unsigned int rechercheLoop(unsigned int tab1[50][50], unsigned int tab2[50][50], unsigned int, unsigned int, unsigned int);

