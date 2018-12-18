#include "triT.h"
//*####        TRI A BULLE      ####*//
/**
triBulleTableau : fonction pour faire le tri à bulle
*@param : tt, le tableau qui contient les chiffres à trier
*@return : rien (passage par adresse)
algo: on parcours le tableau en comparant deux à deux les élements
et en swichant ceux qui sont pas bien ordonnés on commencant par la fin
*/
void triBulleTableau(tt *t)
{
    int echange,i,j,stop=0; // i indice pour garder le debut // j pour commencer de la fin
    if(!stop){   // stop comme un boolien pour sortir dès que tout les elements sont triés
        for(i=0;i<t->indexlast;i++){ // Tant qu'il y a des elements dan le tableau
            stop = 1;  // stop = 1 pour sortir si le teste n'est pas validé
            for(j=t->indexlast;j>=i+1;j--){  // tant qu'on a pas arrivé à la position i+1 à partir de la fin
                if(t->tab[j] < t->tab[j-1]){ 
                    echange = t->tab[j];             // code pour switcher
                    t->tab[j] = t->tab[j-1];
                    t->tab[j-1] = echange;
                    stop=0;          // stop = 0 pour continuer le traitemet
                }
            }
            for(int ii=0;ii<=t->indexlast;ii++)     // code pour afficher le tableau
                printf(" %d ",t->tab[ii]);

            printf("\n");
            printf("\n");
        }
    }   
}
/**
insertValueTableau : fonction pour inserer une valeur dans un tableau
*@param : tt, int: le tableau et l'entier à ajouter
*@return : rien passage par adresse
*/
void insertValueTableau(tt *t, int x)
{
	t->indexlast++;
	t->tab[t->indexlast] = x;
}
/**
mainTriBulle : fonction main du tri à bulle à l'aide des tableaux
*@param void , rien
*@return void , rien
*/
void mainTriBulle(void)
{
    tt *t = malloc(sizeof(tt));
    t->indexlast = -1;
    int i,stop=1,x;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur dans le tableau vide par default \n");
        printf("\n 2:pour trier ce tableau avec un tri a bulle\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);
        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            insertValueTableau(t, x);
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printTable(*t);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            triBulleTableau(t);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
        if(i == 0){
            LeGrandMain();
        }
    }
}
/**
echange : fonction pour swicher deux valeur d'un tableau
*@param : int tt, les indices des 2 valeurs qu'on veut swicher et le tableau
*@return : void, rien passage par adresse
*/
void echange(tt *t, int x, int y)
{
    int echange;  // un entier de passage
    echange = t->tab[x];    
    t->tab[x] = t->tab[y];
    t->tab[y] = echange;
}
/**
printTable : fonction pour afficher le tableau
*@param : tt, le tableau à afficher
*@return : void, rien on veut juste afficher
*/
void printTable(tt t)
{
    printf("\n");
    for(int i=0;i<=t.indexlast;i++) // tant qu'il y a des elements dans le tableau on les affiche
        printf(" [%d] ",t.tab[i]);
    if(t.indexlast == -1) printf("[ ]");  // si le tableau est vide
    printf("\n");
}
// ######## Tri Rapide ####### //
/**
partition : fonction pour reourner le pivot du tableau
*@param : int, tt: indice de l'element le plus droit et le plus 
gauche, le tableau
*@return : int : le pivot oû on va diviser la liste en 2
pour un tableau le choix du pivot depant des indices i le pivot de départ et le j indice de la valeur
qu'on doit swicher avec celle de l'indice i, k pour l'itairation apres le i et le l apres le j 
*/
int partition(int a,int b,tt *t)
{
    int i,j=0,k=0,l=0,ind1,ind2,ind3,etat_k=1,etat_l=1,e;
    
    if(t->tab[a]<t->tab[a+1]) // le choix du pivot au debut de chaque itairation c'est le plus grand des 2 premiere valeur 
        i=a+1;
    else i=a;
    // tant qu' y a pas un element à swicher avec le pivot en commencant de la fin
    for(ind1=b;ind1>i;ind1--){  
        if(t->tab[ind1]<=t->tab[i]){
            j=ind1;                    
            for(ind2=j-1;ind2>i;ind2--){ //chercher l'element d'indice k
                if(t->tab[ind2]<=t->tab[j]){
                    k=ind2;
                    break;
                }
            }
            if(k==0) e=j;
            else e=k;

            for(ind3=i+1;ind3<e;ind3++){  // chercher l'element d'indice l
                if(t->tab[ind3]>=t->tab[i]){
                    l=ind3;
                    break;
                }
            }
            break;
        }
    }
    printf("\n i=%d , l=%d , k=%d ,j=%d \n",t->tab[i],t->tab[l],t->tab[k],t->tab[j]);
    if(j){
        echange(t,i,j);
        if( k && l){     // le cas ou j,k et l existe le pivot est l'indice k
            echange(t,l,k);
            return k;
        }
        if(k) // le cas ou k et j existe le pivot est l'indice k+1
            return k+1;
        if(l) // le cas ou k et l existe le pivot est l'indice l
            return l;
        return j;  // le cas oû seul j existe
    }
    else   // sinon 
        return i+1;
}
/**
triRapide : fonction qui fait le tri rapide
*@param
*@return
cette fonction prend comme pivot pour la 1ere itairation le plus grand des 2 valeurs au 2 premiere position
et cherche à le switcher avec la 1ere petite valeur en commençant par la fin puis elle choisie le bon pivot pour
diviser les valeurs du tableau en 2 (on remarque que les elements à gauche sont > au celles du droite) et on refait la meme chose
*/
void triRapide(int i, int j,tt *table)
{
    int s,etat=0;
// s = pivot, etat comme boolien pour voir si le tableau est trié ou non
    for(int i=0;i<=j-1;i++)
        if(table->tab[i+1]<table->tab[i])
            etat=1; // non trier
    if(etat)
    {
        s = partition(i,j,table);  // recuperer le bon pivot
        printTable(*table);
        printf("\n");
        triRapide(i,s-1,table);  // diviser le tableau et refaire le meme traitement du coté pivot à gauche
        triRapide(s,j,table);   // diviser le tableau et refaire le meme traitement du coté pivot à droit
    }
}
/**
mainTriRapile : fonction main qui fait le tri rapide 
*@param: void, rien
*@return: void, rien
*/
void mainTriRapile(void)
{
    tt *t = malloc(sizeof(tt));
    t->indexlast = -1;
    int i,stop=1,x,taille=0;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur dans le tableau vide par default \n");
        printf("\n 2:pour trier ce tableau avec un tri rapide\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);
        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            insertValueTableau(t, x);
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printTable(*t);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            triRapide(0, t->indexlast,t);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
         if(i == 0){
            LeGrandMain();
        }
    }
}
//*        FIN TRI RAPIDE       *//

//*#####       TRI PAR SELECTION     #####*//
/**
triParSelection : fonction pour faire le tri par selection
*@param : tt, le tableau
*@return: void, rien : passage par adresse  
on parcours le tableau et à chaque itiration l'element à la position i
est swiché avec l'élement le plus petit en commencant par i+1
*/
void triParSelection(tt *t)
{
    printf("\n****** AVANT ******\n");
    printTable(*t);
    printf("\n*******************\n");
    int minPos,minVal;  // la position // la valeur minimal
    for(int i=0;i<=t->indexlast;i++){  // Tant qu'il y a des elements à trier
        minVal = t->tab[i]; 
        minPos = i;
        for(int j=i+1;j<=t->indexlast;j++){  // parcours des elements jusqu'a trouver un element petit
            if(t->tab[j] <= minVal){ // le teste si cette valeur est inferieure à celle qu'on a supposé le plus petite
                minVal = t->tab[j];  // si oui cette valeur devient la plus petite
                minPos = j; // sa position devient la position la plus petite
            }
        }
        echange(t,i,minPos);  // faire l'echange
        printTable(*t);   // afficher le changement
    }
    printf("\n*****  APRES  *****\n");
    printTable(*t);  // afficher le resultat final
    printf("\n*******************\n");
}
/**
mainTriParSelection : fonction main qui fait le tri par selection
*@param : void , rien
*@return : void, rien
*/
void mainTriParSelection(void)
{
    tt *t = malloc(sizeof(tt));
    t->indexlast = -1;
    int i,stop=1,x;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur dans le tableau vide par default \n");
        printf("\n 2:pour trier ce tableau avec un tri par selection\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);
        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            insertValueTableau(t, x);
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printTable(*t);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            triParSelection(t);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
        if(i == 0){
            LeGrandMain();
        }
    }
}
//*        FIN TRI PAR SELECTION       *//

// ######## Tri insertion ####### //
/**
triParInsertion : fonction pour faire le tri par insertion
*@param: tableau: le tableau à trier 
*@return: void : rien : passage par adresse
on parcours le tableau on supposant qu'elle est trier à une position i-1
et quand l'ordre n'est pas validé à la position i on insert à la bonne 
place en echangant les valeurs
*/
void triParInsertion(tt *t)
{
    printf("\n****** AVANT ******\n");
    printTable(*t);
    printf("\n*******************\n");
    int j;
    for(int i=1;i<=t->indexlast;i++){   // tant qu'il y a des elements
        j=i;  // sauvgarder la position
        while(t->tab[j] < t->tab[j-1] && j>0) // si une valeur n'est pas bien placer on l'insert à la bonne place
        {
            echange(t,j,j-1);
            printTable(*t);
            j=j-1;
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printTable(*t);
    printf("\n*******************\n");
}
/**
mainTriParinsertion : fonction main qui fait le tri par insertion
*@param : void ,rien
*@return : void, rien
*/
void mainTriParinsertion(void)
{
    tt *t = malloc(sizeof(tt));
    t->indexlast = -1;
    int i,stop=1,x;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur dans le tableau vide par default \n");
        printf("\n 2:pour trier ce tableau avec un tri par selection\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);
        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            insertValueTableau(t, x);
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printTable(*t);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            triParInsertion(t);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
        if(i == 0){
            LeGrandMain();
        }
    }
}
//*        FIN TRI PAR INSERTION       *//


////////// PARTIE DES LISTES    ////////////////////

/**
tailleList : fonction pour retourner la taille de la liste 
*@param : list: la liste dont on veut voir la taille
*@return : int : la taille de la liste
*/
int tailleList(list *li)
{
    int taille=0;
    while(li != NULL){
        li = li->next;
        taille++;
    }
    return taille;
}
void printList(list *li)
{   // si la liste est vide
    if(!li) printf("\n[ ]");
    else{    // sinon
        while(li){       // tant qu'on a pas atteint la fin
            printf(" [%d] ",li->value); // on affiche
            li = li->next;
        }
    }
}
void echangeList(list *a, list *b)
{
    int tmp;
    if(!a || !b) return;

    tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}
/**
valList : fonction pour recuperer l'adresse de l'element
d'indice index.
*@param: list, int : la liste et l'indice dont on veut voir l'adresse
*@return : list* l'adresse memoire de l'element d'indice index
*/
list *valList(list *li, int index)
{
    //tester si l'indice est correct
    if(index >= tailleList(li) || index < 0)
        printf("\n L indice est invalide \n");

    /* l'indice est valide on parcours la liste
     pour touver le bon element*/
    while(li != NULL && index != 0){
        li = li->next;
        index--;
    }
    return li;
}
list *insertValue(list *li, int x)
{
    list *element,*tmp;
    element = malloc(sizeof(list));
    if(!element){printf("\nError\n"); exit(0);}
    
    element->value = x;
    element->next = NULL;

    if(!li) return element;

    tmp = li;
    while(tmp->next) tmp = tmp->next;

    tmp->next = element;

    return li;
}
/**
tri_bull : fonction pour faire un tri à bulle
*@param : list, taille : la liste et sa taille
*@return : rien : passage par adresse
on parcours la liste en comparant deux à deux les élements
et en swichant ceux qui sont pas bien ordonnés jusqu'a
la fin 
*/
void tri_bull(list *li, int taille)
{
    list *crt;  // un pointeur de type liste pour ne pas perdre
    crt = li;    // l'information
    int stop=0,i=1;  // stop comme un boolien pour sortir qu'on la liste est trié
    while(crt && !stop){ // tant qu'il y a des élements non trié
        stop = 1; // pour sortir de la boucle si on teste est non validé
        crt=li;
        for(int j=0;j<taille-i;j++){ // parcours deux à deux
            if(crt->value > crt->next->value){
                echangeList(crt,crt->next); // faire l'échange
                stop = 0; // stop = 0 pour continuer le traitement
            }
            crt = crt->next;
            printList(li);
            printf("\n");
        }
        i++;
        printf("\n");
    }
}
/**
mainTriBulleList : fonction main de ce tri
*@param : rien : on fait tous à l'intérieure
*@return : rien : on veut afficher le resultat
*/
void mainTriBulleList(void)
{
    list *li = malloc(sizeof(list));
    li = NULL;
    int i,stop=1,x,taille=0;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur a la liste vide par default \n");
        printf("\n 2:pour trier cette liste avec un tri a bulle\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);

        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            li = insertValue(li, x);
            taille++;
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printList(li);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            tri_bull(li, taille);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
        if(i == 0){
            LeGrandMain();
        }
    }
}
////////   fin partie tri à bulle   //////////////

/** Tri par insertion **/
/**
tri_Par_Insertion : fonction pour faire le tri par insertion
*@param: list, taille: la list à trier et la taille 
*@return: void : rien : passage par adresse
on parcours la liste on supposant qu'elle est trier à une position i-1
et quand l'ordre n'est pas validé à la position i on insert à la bonne 
place en echangant les valeurs
*/
void tri_Par_Insertion(list *li,int taille)
{
    int j;
    //pour les elements d'indice 1 à taille-1 faire
    for(int i=1; i<taille; i++){
        //Initialiser j
        j=i;
        /* Echanger tant qu'on ne respect pas l'ordre et il y a au moins 2
           elements dans la liste a trier */
        while (j>0 && (valList(li, j)->value < valList(li, j-1)->value)){
            echangeList(valList(li, j), valList(li, j-1));
            j--;
            //Afficher la nouvelle liste
            printList(li);
            printf("\n\n");
        }
    }
}
/**
mainTriInsertionList : fonction main de ce tri
*@param : rien 
*@return : rien
*/
void mainTriInsertionList(void)
{
    list *li = malloc(sizeof(list));
    li = NULL;
    int i,stop=1,x,taille=0;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur a la liste vide par default \n");
        printf("\n 2:pour trier cette liste avec un tri par insertion\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);

        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            li = insertValue(li, x);
            taille++;
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printList(li);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            tri_Par_Insertion(li,taille);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
        if(i == 0){
            LeGrandMain();
        }


    }
}
////////   fin partie tri par insertion   //////////////

/** Tri par selection **/
/**
tri_Par_Selection : fonction pour faire le tri par selection
*@param: list, int : la liste des elements et sa taille
*@return: void, rien : passage par adresse  
on parcours la liste et à chaque itiration l'element à la position i
est swiché avec l'élement le plus petit en commencant par i+1
*/
void tri_Par_Selection(list *li,int taille)
{
    int j,imin;
    //pour les elements d'indice 0 à taille-1 faire
    for(int i=0; i<taille-1; i++)
    {
        //On considere l'element  d'indice i est le minimum
        imin=i;
        //Trouver l'indice du minimum
        for(j=i+1; j<taille; j++)
            if(valList(li, j)->value < valList(li, imin)->value)
                imin=j;
        //Faire l'echange avec le minimum
        echangeList(valList(li, i), valList(li, imin));
        //Afficher la nouvelle liste
        printList(li);
        printf("\n\n");
    }
}
void mainTriSelectionList(void)
{
    list *li = malloc(sizeof(list));
    li = NULL;
    int i,stop=1,x,taille=0;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur a la liste vide par default \n");
        printf("\n 2:pour trier cette liste avec un tri par selection\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);

        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            li = insertValue(li, x);
            taille++;
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printList(li);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            tri_Par_Selection(li,taille);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
        if(i == 0){
            LeGrandMain();
        }
    }
}
////////   fin partie tri par selection   //////////////

/** Tri rapide **/
/**
tri_rapide: fonction qui fait le tri rapide
*@param : int ,list: l'indice du 1er et du dernier element de la liste et la liste
*@return : void , rien passage par adresse
on choisie le pivot au debut le sup des 2 premier element et on continue
à diviser la liste en des sous liste en les triants au niveau du pivot
trouver à l'aide de la fonction partition
*/
void tri_rapide(int i, int j, list *li)
{
    int s,p;
    /* Condition d'arrêt si l'indice gauche est superieur ou egale
       l'indice droit */
    if (i >= j) return;
    //Choisir le pivot : le maximum des deux premiers elements
    if ( valList(li,i)->value > valList(li,i+1)->value)
        p = i;
    else
        p = i+1;
    //Obtenir l'indice qui divise la liste en deux partitions
    s=Partition(i,j,valList(li,p)->value ,li);
    //Trier les deux partitions recursivement
    tri_rapide(i, s-1, li);
    tri_rapide(s, j, li);
}
/**
Partition : fonction pour reourner le pivot de la liste
*@param : int, list: indice de l'element le plus droit et le plus 
gauche, le pivot et la liste
*@return : int : le pivot oû on va diviser la liste en 2
*/
int Partition(int gauche, int droite, int pivot, list* li)
{
    //Tant que on a au minimum 2 elements dans la deuxieme partition
    while(gauche < droite)
    {
        /* Tant que la valeur du gauche de partition est inferieure
           strictement au valeur du pivot on incremente l'indice du
           gauche */
        while(valList(li,gauche)->value < pivot) gauche++;
        /* Tant que la valeur du droit de partition est superieure
           strictement au valeur du pivot on decremente l'indice du
           droit */
        while(valList(li,droite)->value > pivot) droite--;
        /* S'il reste au moins deux elements differents on fait l'echange
           entre le gauche et le droit et on incremente l'indice du gauche */
        if(gauche < droite)
        {
            echangeList(valList(li,gauche),valList(li,droite));
            gauche++;
            //printf("pivot=%d  gch=%d drt=%d\t",pivot, gauche, droite);
            printList(li);
            printf("\n\n");
        }
    }
    return gauche;
}
void mainTriRapideList(void)
{
    list *li = malloc(sizeof(list));
    li = NULL;
    int i,stop=1,x,tailleF=0;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur a la liste vide par default \n");
        printf("\n 2:pour trier cette liste avec un tri rapide\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);

        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            li = insertValue(li, x);
            tailleF++;
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printList(li);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            tri_rapide(0, tailleF-1, li);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
         if(i == 0){
            LeGrandMain();
        }
    }
}
////////   fin partie tri rapide   //////////////

//* Tri Extraction Heapsort  *//
/**
tri_heap : fonction pour cree le heap et faire le tri
*@param : list,int : la liste avec sa taille
*@return : void , passage par adresse
on considére la liste comme un arbre binaire en (n+1 et n+2), et met
l'element maximum au racine de l'arbre (l'element
d'indice 0) apres elle met cet element a la fin de la
liste et refait la même chose avec taille-1 element
*/
void tri_heap(list *li, int taille)
{
    int j;
    //Mettre premierement le maximum au racine
    for (j=(taille/2)-1; j >= 0; j--)
        descend(j, taille, li);
    /* on change la taille a taille-1 à chaque fois
       jusqu'a ce que la nouvelle taille egale 0 */
    for(j=taille-1; j >= 1; j--)
    {
        /* Au debut on echange la racine avec le dernier element de la liste
           Donc la fin de la liste est triee */
        echangeList(valList(li,0), valList(li,j));
        //Afficher la nouvelle liste
        printList(li);
        printf("\n\n");
        //On met le maximum au debut de la liste
        descend(0, j, li);
    }
}
/**
descend : fonction pour faire avancer le sup de fils vers le noeud
*@param int, list: taille de la liste , l'indice du racine et la liste
*@return : void , rien passage par adresse
on considére liste comme un arbre l'element un indice i a comme fils gauche l'element
d'indice 2*i+1 et comme fils droit l'element d'indice 2*i+2, Ici on
commence les indices a partir de 0, on compare les fils avec la racine si 
il est supp on le swich avec la racine jusqu'a avoir l'element le 
plud grand en racine
*/
void descend(int fils, int taille, list *li)
{
    int pere;
    pere=fils;
    fils=fils*2+1;
    //Tant que on n'a pas atteint la taille en parametre
    while(fils < taille)
    {
        //Si le fils gauche a un frere droit
        if (fils < taille-1)
            /* Et si la valeur de fils gauche est inferieure au fils droit
               donc on va prendre le fils droit comme fils pour bien mettre la valeur
               maximale a la racine */
            if (valList(li, fils)->value < valList(li, fils+1)->value)
                fils++;
        /* Si la racine a une valeur inferieure que son fils max, donc il faut faire
           l'echange et passer a voir le "sous-arbre" de son fils max */
        if (valList(li, pere)->value < valList(li, fils)->value)
        {
            echangeList(valList(li, fils), valList(li, pere));
            pere=fils;
            fils=fils*2+1;
            //Afficher la nouvelle liste
            printList(li);
            printf("\n\n");
        }
        //Sinon on arrete la boucle (on a deja le maximum a la racine)
        else break;
    }
}
/**
mainTriHeapList : fonction main qui fait le tri heapsort
*@param void, rien
*@return void, rien
*/
void mainTriHeapList(void)
{
    list *li = malloc(sizeof(list));
    li = NULL;
    int i,stop=1,x,taille=0;
    while(stop == 1){
        printf("\n 1:pour ajouter une valeur a la liste vide par default \n");
        printf("\n 2:pour trier cette liste avec un tri heapsort\n");
        printf("\n99:pour quitter\n");
        printf("\n 0:pour changer\n");
        printf("\n Votre choix  : ");    
        scanf("%d",&i);

        if(i == 1){
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n Entrez la valeur a ajoute  : ");
            scanf("%d",&x);
            li = insertValue(li, x);
            taille++;
            system("cls");
            printf("\n-------------------------------\n");
            printf("\n");
            printf("\n (%d) ajoute \n",x);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 2){
            system("cls");
            printf("\n---------Avant le tri-------------\n");
            printf("\n");
            printList(li);
            printf("\n");
            printf("\n-------------------------------\n");
            printf("\n");
            tri_heap(li,taille);
            printf("\n");
            printf("\n-------------------------------\n");
        }
        if(i == 99){
            printf("\nMerci\n");
            stop = 0;
        }
         if(i == 0){
            LeGrandMain();
        }
    }
}
////////   fin partie heapsort     //////////////
void triTableau(void)
{
    system("cls");
    int i;
    printf("\nEn tableau\n");
    printf("\n 1: pour tri a bulle \n");
    printf("\n 2: pour tri par insertion \n");
    printf("\n 3: pour tri par selection \n");
    printf("\n 4: pour tri rapide \n");
    printf("\n 77:pour voir le temps d execution des tri dans un tableau\n");

    printf("\nEntrez votre choix :  ");
    scanf("%d",&i);
    if(i == 1){
        system("cls");
        mainTriBulle();
    }
    if(i == 2){
        system("cls");
        mainTriParinsertion();
    }
    if(i == 3){
        system("cls");
        mainTriParSelection();
    }
    if(i == 4){
        system("cls");
        mainTriRapile();
    }
    if(i == 77){
        system("cls");
        tempsDexecutionTableau();
    }
}
void triListe(void)
{
    system("cls");
    int i;
    printf("\nEn liste\n");
    printf("\n 1: pour tri a bulle \n");
    printf("\n 2: pour tri par insertion \n");
    printf("\n 3: pour tri par selection \n");
    printf("\n 4: pour tri rapide \n");
    printf("\n 5: pour tri heapsort\n");
    printf("\n 77:pour voir le temps d execution des tri dans une liste \n");

    printf("\nEntrez votre choix :  ");
    scanf("%d",&i);
    if(i == 1){
        system("cls");
        mainTriBulleList();
    }
    if(i == 2){
        system("cls");
        mainTriInsertionList();
    }
    if(i == 3){
        system("cls");
        mainTriSelectionList();
    }
    if(i == 4){
        system("cls");
        mainTriRapideList();
    }
    if(i == 5){
        system("cls");
        mainTriHeapList();
    }
    if(i == 77){
        system("cls");
        tempsDexecutionList();
    }
}
void LeGrandMain(void)
{
    system("cls");
    int i;
    printf("\n 1: pour utiliser un tableau \n");
    printf("\n 2: pour utiliser une liste \n");
    printf("\nEntrez votre choix : ");
    scanf("%d",&i);

    if(i == 1)
        triTableau();
    if(i == 2)
        triListe();
}
void tempsDexecutionList(void)
{
    list *li = malloc(sizeof(list));
    int taille=0,i;
    li = NULL;
    float ts;
    clock_t t1,t2;
    printf("\n En liste \n");
    printf("\n 1: temps pour tri a bulle\n");
    printf("\n 2: temps pour tri par selection\n");
    printf("\n 3: temps pour tri par insertion\n");
    printf("\n 4: temps pour tri rapide\n");
    printf("\n 5: temps pour tri heapsort\n");
    printf("\n Entrez votre choix  : ");
    scanf("%d",&i);
    int randInt=0,nbelement;
    system("cls");
    printf("\n le nb d element pour tester : ");
    scanf("%d",&nbelement);
    for(int i=0;i<nbelement;i++){
        randInt = rand();
        li = insertValue(li, (randInt % nbelement)+1);
        taille++;
    }
    if(i == 1){
        system("cls");
        t1 = clock();
        tri_bull(li, taille);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
    if(i == 2){
        system("cls");
        t1 = clock();
        tri_Par_Selection(li, taille);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
    if(i == 3){
        system("cls");
        t1 = clock();
        tri_Par_Insertion(li, taille);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
    if(i == 4){
        system("cls");
        t1 = clock();
        tri_rapide(0, nbelement-1, li);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
    if(i == 5){
        system("cls");
        t1 = clock();
        tri_heap(li, taille);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
}
void tempsDexecutionTableau(void)
{
    tt *t = malloc(sizeof(tt));
    t->indexlast = -1;
    int taille=0,i;
    float ts;
    clock_t t1,t2;
    printf("\n En tableau \n");
    printf("\n 1: temps pour tri a bulle\n");
    printf("\n 2: temps pour tri par selection\n");
    printf("\n 3: temps pour tri par insertion\n");
    printf("\n 4: temps pour tri rapide\n");
    printf("\n Entrez votre choix  : ");
    scanf("%d",&i);
    int randInt=0,nbelement;
    system("cls");
    printf("\n le nb d element pour tester : ");
    scanf("%d",&nbelement);
    for(int i=0;i<nbelement;i++){
        randInt = rand();
        insertValueTableau(t, (randInt % nbelement)+1);
    }
    if(i == 1){
        system("cls");
        t1 = clock();
        triBulleTableau(t);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
    if(i == 2){
        system("cls");
        t1 = clock();
        triParSelection(t);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
    if(i == 3){
        system("cls");
        t1 = clock();
        triParInsertion(t);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
    if(i == 4){
        system("cls");
        t1 = clock();
        triRapide(0, t->indexlast,t);
        t2 = clock();
        ts = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("\n le temps d execution est %f \n",ts);
    }
}
