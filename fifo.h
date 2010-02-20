#ifndef FIFO_H
#define FIFO_H

typedef struct {
  int max_size;                 /* Nombre maximale d'�l�ments */
  int newest, oldest;           /* Pointeurs sur le plus r�cent et le plus ancien */
  /* oldest est l'indice de l'�l�ment le plus vieux du tableau
   * newest est l'indice de la premi�re case libre (et donc le plus r�cent est
   * dans la case pr�c�dente).
   */
  void **items;                 /* Tableau contenant les �l�ments */
} Fifo;

/* fifo_new -- cr�e une nouvelle file pouvant contenir au plus max_size
 * �l�ments.
 * Retourne un pointeur sur cette file, ou NULL si l'allocation n'a pas
 * pu se faire.
 * Complexit�: O(1)
 */

extern Fifo *fifo_new(int max_size);

/* fifo_free -- d�truit une file et lib�re la m�moire qu'elle occupait
 * Complecit�: O(1)
 */
extern void fifo_free(Fifo *fifo);

/* fifo_empty -- d�termine si une file est vide.
 * Complexit�: O(1)
 */
extern int fifo_empty(Fifo *fifo);

/* fifo_full -- d�termine si une liste est pleine (ie ne peut plus
 * contenir d'�l�ments suppl�mentaires).
 * Complexit�: O(1);
 */
extern int fifo_full(Fifo *fifo);

/* fifo_max_size -- retoune le nombre maximum d'�l�ments qu'une file
 * peut contenir.
 * Complexit�: O(1)
 */
extern int fifo_max_size(Fifo *fifo);

/* fifo_length -- retourne la longueur effective d'une file.
 * Complexit�: O(1)
 */
extern int fifo_length(Fifo *fifo);

/* fifo_put -- ins�re un nouvel �l�ment dans la file.
 * Ne fait rien si la file est pleine.
 * Complexit�: O(1)
 */
extern void fifo_put(Fifo *fifo, void *item);

/* fifo_get -- retire un �l�ment de la file et renvoie un pointeur
 * sur son contenu.
 * Retourne NULL si la file est vide.
 * Complexit�: O(1)
 */
extern void *fifo_get(Fifo *fifo);

/* fifo_print -- affiche une file � l'�cran. Chaque �l�ment est affich� en
 * faisant appel � print_item.
 * Complexit�: O(1)
 */
extern void fifo_print(Fifo *fifo, void (*print_item)(void *));

#endif /* FIFO_H */
