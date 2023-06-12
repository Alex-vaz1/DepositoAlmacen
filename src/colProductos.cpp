/* 1234567 */

/*
  Módulo de implementación de 'ColProductos'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/producto.h"
#include "../include/pila.h"
#include "../include/utils.h"
#include "../include/colProductos.h"

// Representación de 'ColProductos'.
// Declaración del tipo 'TColProductos'
struct rep_colproductos{
  Producto prod;
  rep_colproductos *izq, *der;
};

/*
  Devuelve un 'ColProductos' vacío (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TColProductos crearColProductos(){
  return NULL;
}

/*
  Libera la memoria asociada a 'colProd' pero no la de sus productos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de
  'colProd'.
 */
void liberarColProductos(TColProductos colProd){
  if(colProd != NULL){
    liberarColProductos(colProd->izq);
    liberarColProductos(colProd->der);
    delete colProd;
  }
}

/*
  Devuelve True si el Producto cuyo componente natural es 'idProd'.
  Si 'idProd' no pertenece a 'colProd', devuelve el árbol vacío.
  El tiempo de ejecución debe ser O(log(n)).
*/
bool existeProductoEnColProductos(nat idProd, TColProductos colProd){
  bool res = false;

    if(colProd != NULL){
	  nat idProdComp = obtenerIdentificadorDeProducto(colProd->prod);
      if(idProdComp == idProd){
        res = true;
      }else{
        if(idProdComp < idProd){
          res = existeProductoEnColProductos(idProd, colProd->der);
        }else{
          res = existeProductoEnColProductos(idProd, colProd->izq);
        }
      }
    }

    return res;
}

/*
  Devuelve el Producto cuyo componente natural es 'idProd'.
  Si 'idProd' no pertenece a 'colProd', devuelve el árbol vacío.
  El tiempo de ejecución debe ser O(log(n)).
 */
Producto buscarProductoEnColProductos(nat idProd, TColProductos colProd){
  Producto prod = NULL;

  if(colProd != NULL){
	nat idProdComp = obtenerIdentificadorDeProducto(colProd->prod);
    if(idProdComp == idProd){
      prod = colProd->prod;
    }else{
      if(idProdComp < idProd){
        prod = buscarProductoEnColProductos(idProd, colProd->der);
      }else{
        prod = buscarProductoEnColProductos(idProd, colProd->izq);
      }
    }
  }

  return prod;
}

/*
  Inserta 'dato' en 'colProd'. 
  Precondición: !existeProductoEnColProductos()
  El tiempo de ejecución debe ser O(log(n))
 */
TColProductos insertarEnColProductos(Producto dato, TColProductos colProd){
  if(colProd == NULL){
    colProd = new rep_colproductos;
    colProd->der = NULL;
    colProd->izq = NULL;
    colProd->prod = dato;
  }else{
    if(obtenerIdentificadorDeProducto(colProd->prod) < obtenerIdentificadorDeProducto(dato)){
      colProd->der = insertarEnColProductos(dato, colProd->der);
    }else{
      colProd->izq = insertarEnColProductos(dato, colProd->izq);
    }
  }

  return colProd;
}

/*
  Remueve de 'colProd' el elemento con identificador idProd.
  Devuelve 'colProd'.
  Precondición: existeProductoEnColProductos()
  El tiempo de ejecución debe ser O(log(n))
 */

//Función auxiliar utilizada en removerDeArbolProductos
Producto maxColProductos(TColProductos colProd){
  if(colProd->der == NULL){
    return colProd->prod;
  }else{
    return maxColProductos(colProd->der);
  }
}

TColProductos removerDeColProductos(nat idProd, TColProductos colProd){
  if(colProd != NULL){
    if(obtenerIdentificadorDeProducto(colProd->prod) == idProd){
      TColProductos aux = colProd;
      if(colProd->izq == NULL){
        colProd = colProd->der;
        delete aux;
      }else if(colProd->der == NULL){
        colProd = colProd->izq;
        delete aux;
      }else{
        Producto maxIzq = maxColProductos(colProd->izq);
        colProd->prod = maxIzq;
        colProd->izq = removerDeColProductos(obtenerIdentificadorDeProducto(maxIzq), colProd->izq);
      }
    }else if(obtenerIdentificadorDeProducto(colProd->prod) < idProd){
      colProd->der = removerDeColProductos(idProd, colProd->der);
    }else{
      colProd->izq = removerDeColProductos(idProd, colProd->izq);
    }
  }

  return colProd;
}

/*
  Devuelve una pila con los elementos de la colección ordenados por identificador
  de menor a mayor.
*/
void colProdAPilaAux(TColProductos colProd, TPila &pila){
  if(colProd != NULL){
    if(colProd->izq != NULL){
      colProdAPilaAux(colProd->izq, pila);
    }
    pila = apilar(colProd->prod, pila);
    if(colProd->der != NULL){
      colProdAPilaAux(colProd->der, pila);
    }
  }  
}

TPila colProdAPila(TColProductos colProd){
  TPila pila = crearPila();
  colProdAPilaAux(colProd, pila);
  return pila;
}
