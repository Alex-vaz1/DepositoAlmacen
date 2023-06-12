/* 1234567 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/pila.h"
#include "../include/cadena.h"
#include "../include/producto.h"

struct _rep_pila {
  TCadena pila;
  nat cantidad;
};

TPila crearPila() {
  TPila res = new _rep_pila;
  res->pila = crearCadena();
  res->cantidad = 0;
  return res;
}

void liberarPila(TPila p) {
  if (p->pila == NULL)
	delete p;
}

nat cantidadEnPila(TPila p) { return p->cantidad; }

TPila apilar(Producto dato, TPila p) {
  p->pila = insertarAlInicio(p->pila, dato);
  p->cantidad++;
  return p;
}

Producto cima(TPila p) { return datoCadena(p->pila); }

TPila desapilar(TPila p) {
  removerPrimero(p->pila);
  p->cantidad--;
  return p;
}
