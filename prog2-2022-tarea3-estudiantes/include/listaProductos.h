/*
  Módulo de definición de 'TLista'.

  Los elementos de tipo TLista son Listas de elementos de tipo TInfo.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _LISTAPRODUCTOS_H
#define _LISTAPRODUCTOS_H

#include "utils.h"
#include "producto.h"
#include "fecha.h"

// Declaración del tipo 'TLista'
// Se debe definir en ListaProductos.cpp.
// struct _rep_ListaProductos;
typedef struct _rep_listaProductos* TListaProductos;

/*
  Devuelve una TListaProductos vacía (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TListaProductos crearListaProductos();

/*
  Libera la memoria asignada a la TListaProductos 'p' y la de todos sus elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de la TListaProductos
  'p'.
 */
void liberarListaProductos(TListaProductos& p);

/*
  Devuelve true si la TListaProductos 'p' es vacia.
  El tiempo de ejecución debe ser O(1).
 */
bool esVaciaListaProductos(TListaProductos p);

/*
	Devuelve true si el producto cuyo nombre se pasa como parámetro en la variable 'nombreProducto'
	se encuentra en la lista 'p'.
*/
bool existeProductoListaProductos(TListaProductos p, char* nombreProducto);

/*
  Agrega el producto 'prod' a la lista de productos 'p'. 
  Devuelve 'p' con 'prod' insertado.
  El tiempo de ejecución debe ser O(1).
 */
TListaProductos agregarAListaProductos(TListaProductos p, Producto prod);

/*
  Devuelve el elemento en 'p' cuyo nombre coincide con el pasado por parámetro en la variable 'nombreProducto'.
  El tiempo de ejecución debe ser O(n).
 */
Producto obtenerProductoListaProductos(TListaProductos p, char* nombreProducto);

/*
 Quita el elemento de 'p' cuyo nombre coincide con el pasado por parámetro en la variable 'nombreProducto'.
  El tiempo de ejecución debe ser O(n).
  Devuelve 'p' con el producto quitado.
*/
TListaProductos quitarDeListaProductos(TListaProductos p, char* nombreProducto);

#endif
