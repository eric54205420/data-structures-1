#ifndef HEAP_H
#define HEAP_H

#define heap_left_son(i) (2*((i)+1)-1)
#define heap_right_son(i) (2*((i)+1)+1-1)
#define heap_father(i) ((int) ((i)+1)/2-1) /* FAUX si i == 0 */

typedef int (*relation)(void *, void *);

typedef struct {
  int size;                     /* Taille effective du tas */
  int max;                      /* Taille maximum du tas */
  relation rel;                 /* Relation d'ordre utilis�e pour ordonner le tas */
  void **tab;                   /* Les donn�es contenues dans le tas */
} Heap;


/* heap_create -- cr�e un tas d'une taille maximale donn�e, ordonn� par
 * la relation rel.
 * Retourne un pointeur sur ce nouveau tas, ou NULL si la cr�ation
 * ne s'est pas bien pass�e.
 * Complexit�: O(1)
 */
extern Heap *heap_create(int max_size, relation rel);

/* heap_free -- d�truit un tas et lib�re la m�moire qu'il occupait.
 * Complexit�: O(1);
 */
extern void heap_free(Heap *h);

/* heap_root -- renvoie la racine du tas (ie son plus "petit" �l�ment).
 * Ne modifie PAS le tas.
 * Complexit�: O(1)
 */
extern void *heap_root(Heap *h);

/* heap_size -- renvoie la taille effective du tas (ie le nombre d'�l�ments
 * qu'il contient).
 * Complexit�: O(1);
 */
extern int heap_size(Heap *h);

/* heap_max_size -- renvoie le nombre maximum d'�l�ments qu'un tas peut
 * contenir.
 * Complexit�: O(1)
 */
extern int heap_max_size(Heap *h);

/* heap_extract_root -- retire le sommet du tas et renvoie sa valeur
 * (en fait un pointeur sur son contenu).
 * Complexit�: O(ln(heap_size(h)))
 */
extern void *heap_extract_root(Heap *h);

/* heap_insert -- ins�re un nouvel �l�ment dans le tas.
 * La valeur de retour indique si l'insertion s'est bien pass�e.
 * Complexit�: O(ln(heap_size(h)))
 */
extern int heap_insert(Heap *h, void *item);

/* heap_print -- affiche le tas � l'�cran. Affiche chacun des
 * �l�ments avec le function print_data.
 * Complexit�: O(heap_size(h))
 */
extern void heap_print(Heap *h, void (*print_data)(void *));

#endif /* HEAP_H */
