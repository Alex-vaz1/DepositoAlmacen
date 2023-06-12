/* 1234567 */

/*
  Módulo de definición de 'Deposito'.

  Los elementos de tipo 'Deposito' son punteros a una estructura (que debe
  definirse en deposito.cpp).

  Laboratorio de Programación 2 2do semestre 2022.
  InCo-FIng-UDELAR
 */

#include "../include/deposito.h"
#include "../include/fecha.h"
#include "../include/colProductos.h"
#include "../include/pila.h"
#include "../include/producto.h"
#include "../include/colProductosPorNombre.h"

// Representación de 'Deposito'.
// Se debe definir en deposito.cpp.
// struct _rep_deposito;
// Declaración del tipo 'Deposito'.
struct _rep_deposito{
	TColProductos productos;
	TColProductosPorNombre productosPorNombre;
};

/* Operaciones de deposito */

/*
  Devuelve un 'deposito'.
 */
TDeposito crearDeposito() { 
	TColProductos prods = crearColProductos();
	TDeposito deposito = new _rep_deposito;
	deposito->productos = prods;
	return deposito;
}

/*
  Libera la memoria reservada por 'deposito' y de todos sus elementos.
 */
void liberarDeposito(TDeposito deposito) {
	TPila pila = colProdAPila(deposito->productos);
	liberarColProductos(deposito->productos);
	while(cantidadEnPila(pila) > 0){
		Producto prod = (Producto) cima(pila);
		pila = desapilar(pila);
		liberarProducto(prod);
	}
	liberarPila(pila);
	delete deposito;
}

/*
  Devuelve las unidades del producto con identificador 'identificador'
  en el deposito 'deposito'. O(log(n))
 */
nat obtenerCantidadUnidades(TDeposito deposito, int identificador){
	nat cantUnidades = 0;
	Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
	if (prod != NULL){
		cantUnidades = obtenerCantidad(prod);
	}
	return cantUnidades;
}

/*
  Agrega un producto al depósito con el identificador y el nombre que se pasan como parametros. O(log(n))
  Pre: !existeProducto(). 
 */
void agregarProducto(TDeposito deposito, nat identificador, char* nombre){
	bool existeProd = existeProductoEnColProductos(identificador, deposito->productos);
	if (!existeProd){
		Producto prod = crearProducto(identificador, nombre);
		deposito->productos = insertarEnColProductos(prod, deposito->productos);
	}
}

/*
  Devuelve true si existe un producto con identificador 'identificador'. O(log(n))
*/
bool existeProducto(TDeposito deposito, nat identificador){ 
	return existeProductoEnColProductos(identificador, deposito->productos);
}

/*
Tarea 3 :: Nueva función 
Devuelve true si existe un producto con nombre 'nombreProducto'. O(1) promedio.
*/
bool existeProductoPorNombre(TDeposito deposito, char* nombreProducto){ return false; }

/*
  Quita del depósito todas las unidades que tengan fecha de vencimiento anterior 
  o igual a la fecha pasada como parámetro.
*/
void quitarVencidosDeposito(TDeposito deposito, TFecha fecha){
	TPila pila = colProdAPila(deposito->productos);
	while(cantidadEnPila(pila) > 0){
		Producto prod = (Producto) cima(pila);
		pila = desapilar(pila);
		quitarVencidos(prod, fecha);
	}
	liberarPila(pila);
}

/*
  Agrega cantidad unidades con fecha de vencimiento fVenc al producto de identificador
  'identificador'.
  Pre: existeProducto().
*/
void agregarUnidades(TDeposito deposito, nat identificador, nat cantidad, TFecha fVenc){
	if (existeProductoEnColProductos(identificador, deposito->productos)){
		Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
		agregarUnidades(prod, cantidad, fVenc);
	}
}

/*
    Quita cantidad elementos al producto con identificador 'identificador'.
    Se quitan los elementos con fecha de vencimiento más próxima.
    Pueden existir productos con cantidad 0 pero no con cantidad menor a cero.
    Pre: existeProducto() && obtenerCantidadUnidades() >= cantidad.
*/
void quitarUnidades(TDeposito deposito, nat identificador, nat cantidad){
	if (existeProductoEnColProductos(identificador, deposito->productos)){
		Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
		quitarUnidades(prod, cantidad);
	}
}

/*
    Si el producto existe, entonces lo elimina. También se deben eliminar todas 
    las unidades del producto. 
*/
void eliminarProducto(TDeposito deposito, nat identificador){
	if (existeProductoEnColProductos(identificador, deposito->productos)){
		Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
		deposito->productos = removerDeColProductos(identificador, deposito->productos);
		liberarProducto(prod);
	}
}

/*
  Se debe imprimir el resumen del depósito de la forma que está aclarada en
  el archivo de especificación gestionDeposito.h
*/
void imprimirResumenDeposito(TDeposito deposito) { //NO USADA
	TPila pilaProd = colProdAPila(deposito->productos);
	while (cantidadEnPila(pilaProd) > 0){
		Producto prod = (Producto) cima(pilaProd);
		imprimirProducto(prod);
		pilaProd = desapilar(pilaProd);
	}
	liberarPila(pilaProd);
}

/*
  Imprime los datos del producto en el formato específicado en la letra. O(log(n))
  Pre: existeProducto() 
 */
void imprimirProducto(TDeposito deposito, int identificador){
	if (existeProductoEnColProductos(identificador, deposito->productos)){
		Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
		imprimirProducto(prod);
	}
}

/*
Tarea 3 :: Nueva función
Imprime los datos del producto en el formato específicado en gestionDeposito.h. O(1) promedio.
  Pre: existeProductoPorNombre()
*/
void imprimirProductoPorNombre(TDeposito deposito, char* nombreProducto){ }
