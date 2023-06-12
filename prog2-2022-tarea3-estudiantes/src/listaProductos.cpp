/* 1234567 */

#include "../include/utils.h"
#include "../include/producto.h"
#include "../include/fecha.h"
#include "../include/listaProductos.h"

struct _rep_listaProductos{
  _rep_listaProductos* sig;
  Producto prod;
};

/*
  Devuelve una TListaProductos vacía (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TListaProductos crearListaProductos(){ return NULL; }

/*
  Libera la memoria asignada a la TListaProductos 'p' y la de todos sus elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de la TListaProductos
  'p'.
 */
void liberarListaProductos(TListaProductos &p){ }

/*
  Devuelve true si la TListaProductos 'p' es vacia.
  El tiempo de ejecución debe ser O(1).
 */
bool esVaciaListaProductos(TListaProductos p){ return false; }

/*
	Devuelve true si el producto cuyo nombre se pasa como parámetro en la variable 'nombreProducto'
	se encuentra en la lista 'p'.
*/
bool existeProductoListaProductos(TListaProductos p, char* nombreProducto){ return false; }

/*
  Agrega el producto 'prod' a la lista de productos 'p'. 
  Devuelve 'p' con 'prod' insertado.
  El tiempo de ejecución debe ser O(1).
 */
TListaProductos agregarAListaProductos(TListaProductos p, Producto prod){ return NULL; }

/*
  Devuelve el elemento en 'p' cuyo nombre coincide con el pasado por parámetro en la variable 'nombreProducto'.
  El tiempo de ejecución debe ser O(n).
 */
Producto obtenerProductoListaProductos(TListaProductos p, char* nombreProducto){ return NULL; }

/*
 Quita el elemento de 'p' cuyo nombre coincide con el pasado por parámetro en la variable 'nombreProducto'.
  El tiempo de ejecución debe ser O(n).
  Devuelve 'p' con el producto quitado.
*/
TListaProductos quitarDeListaProductos(TListaProductos p, char* nombreProducto){ return NULL; }
