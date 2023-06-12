/* 1234567 */

/*
  Módulo de definición de 'TLista'.

  Los elementos de tipo TLista son Listas de elementos de tipo TFecha.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"
#include "../include/lista.h"
#include "../include/vencimiento.h"
#include "../include/fecha.h"

// Representación de 'TLista'.
// Se debe definir en Lista.cpp.
// Declaración del tipo 'TLista'
struct _rep_lista{
  _rep_lista* sig;
  Vencimiento ven;
};

// Que sentido tiene esta funcion?
/*
  Devuelve una TLista vacía (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TLista crearLista(){ 
  return NULL;
}

/*
  Libera la memoria asignada a la TLista 'p' y la de todos sus elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de la TLista
  'p'.
 */
void liberarLista(TLista p){
	while(p != NULL){
		TLista aux = p;
		p = p->sig;
		liberarVencimiento(aux->ven);
		delete aux;
		aux = NULL;
	}
}

/*
  Devuelve si la TLista 'p' es vacia.
  El tiempo de ejecución debe ser O(1).
 */
bool esVaciaLista(TLista p){ 
  return p == NULL;
}

/*
  agregarALista 'venc' en 'p'-
  Devuelve 'p' con 'venc' insertado.
  La TLista resultado no comparte memoria con 'venc'.
  Si ya existe un vencimiento con f_venc se le aumenta cantidad a dicho elemento
  El tiempo de ejecución debe ser O(n).
 */

TLista agregarAListaOrdenado(TLista p, TFecha f_venc, nat cantidad){ 
  if(p==NULL){
    TLista nuevo = new _rep_lista;
    TFecha f_ven = crearCopiaFecha(f_venc);
    Vencimiento ven = crearVencimiento(f_ven, cantidad);
    nuevo->ven = ven;
    nuevo->sig = NULL;
    p = nuevo;
    return p;
  }else{
    int comp = compararFechas(f_venc, obtenerFVencimiento(p->ven));
    if(comp == 0){
      agregarUnidades(p->ven, cantidad);
      return p;
    }else{
      if(comp == -1){
		  TLista nuevo = new _rep_lista;
		  TFecha f_ven = crearCopiaFecha(f_venc);
		  Vencimiento ven = crearVencimiento(f_ven, cantidad);
      	  nuevo->ven = ven;
		  nuevo->sig = p;
		  p = nuevo;
		  return p;
      }else{
        TLista iter = p;
        while(iter->sig != NULL && compararFechas(f_venc, obtenerFVencimiento(iter->sig->ven)) == 1){
          iter = iter->sig;
        }
        if(iter->sig != NULL && compararFechas(f_venc, obtenerFVencimiento(iter->sig->ven)) == 0){
          agregarUnidades(iter->sig->ven, cantidad);
        }else{
			TLista nuevo = new _rep_lista;
			TFecha f_ven = crearCopiaFecha(f_venc);
			Vencimiento ven = crearVencimiento(f_ven, cantidad);
      		nuevo->ven = ven;
			nuevo->sig = iter->sig;
			iter->sig = nuevo;			
		}
        return p;
      }
    }
  }
}

/*
  Devuelve el elemento en 'p' con fecha mas antigua.
  Precondición: cantidadEnLista(p) > 0.
  El tiempo de ejecución debe ser O(1).
 */

Vencimiento obtenerMasViejo(TLista p){ 
  Vencimiento res = NULL;
  if( p!= NULL){
    res = p->ven;
  }
  return res;
}

/*	
	Quita de la lista al elemento con la menor fecha de vencimiento.
	Pre: la lista tiene al menos un elemento.
*/
TLista quitarMasViejo(TLista p){ 
  TLista borro = p;
  p->ven = NULL;
  p = p->sig;
  delete borro;
  return p;
}

/*
  Remueve de 'p' los vencimientos iguales a 'venc'.
  'venc' no comparte memoria con ningun elemento de la lista 'p'.
  Se libera la memoria asignada al/los mismo/s.
  Devuelve 'p' sin ocurrencias de 'venc'.
  Precondición: cantidadEnLista(p) > 0.
 */

/*
TLista quitarDeLista(TLista p, Vencimiento venc){ 
  TFecha f_ven = obtenerFVencimiento(venc);
  TLista aux;
  
  while(compararFechas(obtenerFVencimiento(p->ven),f_ven) == 0){
    aux = p;
    p = p->sig;
    liberarFecha(obtenerFVencimiento(aux->ven));
    liberarVencimiento(aux->ven);
    delete aux;
  }
  TLista iter = p;
  while(iter->sig != NULL){
    if(compararFechas(obtenerFVencimiento(iter->sig->ven),f_ven) == 0){
      aux = iter->sig;
      iter->sig = aux->sig;
      liberarFecha(obtenerFVencimiento(aux->ven));
      liberarVencimiento(aux->ven);
      delete aux;
    }else{
      iter = iter->sig;
    }
  }
  return p;
}
*/

/*
 Elimina 'cantidad' de vencimientos con fecha mas baja 
en la TLista 'p'
*/
TLista quitarDeLista(TLista p, nat cantidad){
  while(p!=NULL && cantidad > 0){
    nat cant = obtenerCantidad(p->ven);
    if(cant > cantidad){
      quitarUnidades(p->ven, cantidad);
      cantidad = 0;
    }else{
      cantidad = cantidad - cant;
      TLista aux = p;
      p = p->sig;
      liberarVencimiento(aux->ven);
      delete aux;
    }
  }
  return p;
}

void imprimirInfoLista(TLista p){
  while(p != NULL){
    imprimirVencimiento(p->ven);
    p = p->sig;
  }
}

