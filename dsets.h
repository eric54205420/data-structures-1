#ifndef DSETS_H
#define DSETS_H

typedef struct {
  int size;
  int *father;
  int *rank;
} DSets;

/* dsets_new -- cr�e une nouvelle collection d'ensembles disjoints
 * de size entiers (entre 0 et size - 1).
 * Renvoie un pointeur sur cette nouvelle collection, ou NULL
 * si la cr�ation n'a pas pu se faire.
 * Complexit�: O(size)
 */
extern DSets *dsets_new(int size);

/* dsets_free -- d�truit une collection d'ensembles et lib�re la
 * m�moire qu'elle occupait.
 * Complexit�: O(1)
 */
extern void dsets_free(DSets *ds);

/* dsets_max_size -- renvoie la taille maximale d'�l�ments que peut contenir
 * une collection.
 * Complexit�: O(1)
 */
extern int dsets_max_size(DSets *ds);

/* dsets_make_set -- cr�e un nouvel ensemble ne contenant que l'�l�ment n
 * dans la collection ds.
 * Complexit�: O(1)
 */
extern void dsets_make_set(DSets *ds, int n);

/* dsets_find_set -- renvoie le repr�sentant de l'ensemble auquel n appartient
 * dans ds.
 * Renvoie -1 si n n'est dans aucun ensemble.
 */
extern int dsets_find_set(DSets *ds, int n);

/* dsets_union -- r�uni les ensembles contenant n1 et n2
 * Complexit�: O(ln(dsets_max_size(ds)))
 */
extern void dsets_union(DSets *ds, int n1, int n2);

/* dsets_same_set -- d�termine si n1 et n2 font parti du meme ensemble
 */
extern int dsets_same_set(DSets *ds, int n1, int n2);

/* dsets_print -- affiche la liste des �l�ments de ds et de leurs p�res
 */
extern void dsets_print(DSets *ds);

#endif /* DSETS_H */
