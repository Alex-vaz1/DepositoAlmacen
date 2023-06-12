/*
  Módulo de definición de 'TLista'.

  Los elementos de tipo TLista son Listas de elementos de tipo TInfo.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _LISTA_H
#define _LISTA_H

#include "utils.h"
#include "vencimiento.h"
#include "fecha.h"

// Representación de 'TLista'.
// Se debe definir en Lista.cpp.
// struct _rep_Lista;
// Declaración del tipo 'TLista'
typedef struct _rep_lista* TLista;

/*
  Devuelve una TLista vacía (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TLista crearLista();

/*
  Libera la memoria asignada a la TLista 'p' y la de todos sus elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de la TLista
  'p'.
 */
void liberarLista(TLista p);

/*
  Devuelve si la TLista 'p' es vacia.
  El tiempo de ejecución debe ser O(1).
 */
bool esVaciaLista(TLista p);

/*
  agregarALista 'venc' en 'p'-
  Devuelve 'p' con 'venc' insertado.
  La TLista resultado no comparte memoria con 'venc'.
  Si ya existe un vencimiento con f_venc se le aumenta cantidad a dicho elemento
  El tiempo de ejecución debe ser O(n).
 */
TLista agregarAListaOrdenado(TLista p, TFecha f_venc, nat cantidad);

/*
  Devuelve el elemento en 'p' con fecha mas antigua.
  Precondición: cantidadEnLista(p) > 0.
  El tiempo de ejecución debe ser O(1).
 */
Vencimiento obtenerMasViejo(TLista p);

TLista quitarMasViejo(TLista p);

/*
 Elimina 'cantidad' de vencimientos con fecha mas baja 
en la TLista 'p'
*/
TLista quitarDeLista(TLista p, nat cantidad);

void imprimirInfoLista(TLista p);

#endif
