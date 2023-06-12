/* 1234567 */

/*
  Módulo de definición de 'ColProductos'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/producto.h"
#include "../include/utils.h"
#include "../include/listaProductos.h"
#include "../include/colProductosPorNombre.h"

// Declaración del tipo 'TColProductosPorNombre'
struct rep_colproductospornombre{
  TListaProductos listaProds[CANTIDAD_PROD];
};

/*
  Devuelve un 'TColProductosPorNombre' vacío (sin elementos).
  El tiempo de ejecución debe ser O(n).
 */
TColProductosPorNombre crearColProductosPorNombre(){ return NULL; }

/*
  Libera la memoria asociada a 'colProd' y todos sus elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de
  'colProd'.
 */
void liberarColProductosPorNombre(TColProductosPorNombre& colProd){ }

/*
  Devuelve True si existe el Producto con nombre 'nombreProducto'.
  Si 'nombreProducto' no pertenece a 'colProd' devuelve false.
  El tiempo de ejecución debe ser O(1) promedio.
 */
bool existeProductoEnColProductosPorNombre(char* nombreProducto, TColProductosPorNombre colProd){ return false; }

/*
  Devuelve el Producto con nombre 'nombreProducto'.
  Si 'nombreProducto' no pertenece a 'colProd' devuelve NULL.
  El tiempo de ejecución debe ser O(1) promedio.
 */
Producto buscarProductoEnColProductosPorNombre(char* nombreProducto, TColProductosPorNombre colProd){ return NULL; }

/*
  Inserta 'dato' en 'colProd'. 
  Precondición: !existeProductoEnColProductosPorNombre()
  El tiempo de ejecución debe ser O(1) promedio.
 */
TColProductosPorNombre insertarEnColProductosPorNombre(Producto dato, TColProductosPorNombre colProd){ return NULL; }

/*
  Remueve de 'colProd' el elemento con nombre 'nombreProducto'.
  Devuelve 'colProd'.
  Precondición: existeProductoEnColProductosPorNombre()
  El tiempo de ejecución debe ser O(1) promedio.
 */
TColProductosPorNombre removerDeColProductosPorNombre(char* nombreProducto, TColProductosPorNombre colProd){ return NULL; }
