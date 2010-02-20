#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"

typedef Edge **Vertex;

typedef struct {
  int size;
  Vertex *vertex;
} Graph;

/* graph_new -- cr�e un nouveau graphe non orient� (vide) pouvant
 * contenir au maximum size sommets.
 * Retourne l'adresse de ce nouveau graphe, ou NULL en cas d'�chec.
 * Complexit�: O(1)
 */
extern Graph *graph_new(int size);

/* graph_free -- d�truit un graphe et lib�re la m�moire qu'il occupait.
 * Complexit�: O(g->size^2) 
 */
extern void graph_free(Graph *g);

/* graph_empty -- d�termine si un graphe est vide (ie ne contient
 * aucun sommet).
 * Complexit�: O(g->size)
 */
extern int graph_empty(Graph *g);

/* graph_size -- d�termine la taille (ie le nombre de sommets) d'un
 * graphe.
 * Complexit�: O(g->size)
 */
extern int graph_size(Graph *g);

/* graph_max_size -- d�termine le nombre maximum de sommets qu'un
 * graphe peut contenir.
 * Complexit�: O(1)
 */
extern int graph_max_size(Graph *g);

/* graph_has_vertex -- d�termine si un graphe poss�de un certain
 * sommet v.
 * Complexit�: O(1)
 */
extern int graph_has_vertex(Graph *g, int v);

/* graph_has_edge -- d�termine si un graphe a une certaine arete (v1, v2)
 * Complexit�: O(1)
 */
extern int graph_has_edge(Graph *g, int v1, int v2);

/* graph_vertex_degree -- renvoie le degr� du sommet v.
 * Complexit�: O(g->size)
 */
extern int graph_vertex_degree(Graph *g, int v);

/* graph_get_edge -- renvoie un pointeur sur l'arete sp�cifi�e
 * ou NULL si elle n'existe pas.
 * Complexit�: O(1)
 */
extern Edge *graph_get_edge(Graph *g, int v1, int v2);

/* graph_first_edge -- retourne la premi�re arete de g,
 * ou NULL si g n'a pas d'arete.
 * Complexit�: O(g->size)
 */
extern Edge *graph_first_edge(Graph *g);

/* graph_next_edge -- retourne l'arete suivant e dans g, ou NULL
 * si e est la derni�re.
 * Les appels sucessifs ne renvoient jamais deux fois la meme arete.
 * Complexit�: O(g->size)
 */
extern Edge *graph_next_edge(Graph *g, Edge *e);

/* graph_add_vertex -- ajoute le sommet v au graphe g.
 * Ne fait rien si le sommet existe d�j�.
 * La valeur de retour indique si l'insertion s'est bien
 * pass�e.
 * Complexit�: O(1)
 */
extern int graph_add_vertex(Graph *g, int v);

/* graph_add_edge -- ajoute une arete reliant v1 et v2, avec le
 * poids w et l'attribut attr au graphe g.
 * La valeur de retour indique si l'op�ration s'est bien d�roul�e.
 * Complexit�: O(1)
 */
extern int graph_add_edge(Graph *g, int v1, int v2, float w, int attr);

/* graph_remove_vertex -- retire le sommet v du graph g.
 * La valeur de retour indique si l'op�ration s'est bien pass�e.
 * Complexit�: O(g->size)
 */
extern int graph_remove_vertex(Graph *g, int v);

/* graph_remove_edge -- retire l'arete (v1, v2) du graphe g.
 * La valeur de retour indique si l'op�ration s'est bien pass�e.
 * (une valeur 0 indique que l'arete n'existait pas)
 * Complexit�: O(1)
 */
extern int graph_remove_edge(Graph *g, int v1, int v2);

/* graph_ugly_print -- affiche le graphe � l'�cran (sous une forme
 * pas tr�s lisible).
 * Complexit�: O((g->size)^2)
 */
extern void graph_ugly_print(Graph *g);

#endif /* GRAPH_H */
