#ifndef __BULLE__H__
#define __BULLE__H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 50
/** Tri en tableau **/
typedef struct
{
	int tab[max];
	int indexlast;
}tt;
/** Tri en liste **/
typedef struct listElement
{
	int value;
	struct listElement *next;
	//struct listElement *before;
}list;

//////////////  PARTIE DES TABLEAUX ////////////////////

//## Fonction pour l"ensemble du programme ##//
// fonction pour permuter les valeurs de 2 indice du tableau
void echange(tt *t, int x, int y);
// fonction pour afficher un tableau
void printTable(tt t);
void insertValueTableau(tt *t, int x);
//#################################################
/** Les prototypes des fonctions tri à bulle **/

// fonction du tri à bulle
void triBulleTableau(tt *t);
// main du tri à bulle
void mainTriBulle(void);
//#################################################

//#################################################
/** Les prototypes des fonctions tri rapide **/

// fonction qui retourne le pivote et fait l'échange
int partition(int pre, int der, tt *t);
// fonction pour trier le tableau
void triRapide(int i, int j, tt *t);
// main du tri rapide
void mainTriRapile(void);
//#################################################

//#################################################
/** Les prototypes des fonctions tri par sélection **/

// fonction du tri par sélection
void triParSelection(tt *t);
// main du tri par sélection
void mainTriParSelection(void);
//#################################################

//#################################################
/** Les prototypes des fonctions tri insertion **/

// fonction du tri par insertion
void triParInsertion(tt *t);
// main du tri par insertion
void mainTriParinsertion(void);
//#################################################

/* Les prototypes des fonctions de traitement des listes */
int tailleList(list *li);
void printList(list *li);
void echangeList(list *a, list *b);
list *insertValue(list *li, int x);
list *valList(list *li, int index);
//////////////  PARTIE DES LISTES ////////////////////

/** Tri à bulle par liste **/
void tri_bull(list *li, int taille);
void mainTriBulleList(void);
// fin //

/** Tri par insertion par liste **/
void tri_Par_Insertion(list *li,int N);
void mainTriInsertionList(void);
// fin //

/** Tri par selection par liste **/
void tri_Par_Selection(list *li,int N);
void mainTriSelectionList(void);
// fin //

/** Tri rapide par liste **/
void tri_rapide(int i, int j, list *li);
int Partition(int gauche, int droite, int pivot, list* li);
void mainTriRapideList(void);
// fin //

/** Tri heapsort par liste **/
void tri_heap(list *li, int taille);
void descend(int fils, int taille, list *li);
void mainTriHeapList(void);
// fin //

/*Menu général*/
void triTableau(void);
void triListe(void);
void LeGrandMain(void);
void tempsDexecutionList(void);
void tempsDexecutionTableau(void);
#endif