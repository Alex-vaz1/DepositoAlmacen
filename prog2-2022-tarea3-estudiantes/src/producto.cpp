/* 1234567 */

/*
  Módulo de implementacion de 'Producto'.

  Los elementos de tipo 'Producto' son punteros a una estructura (que debe
  definirse en producto.cpp).

  Laboratorio de Programación 2 2do semestre 2022.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"
#include "../include/fecha.h"
#include "../include/producto.h"
#include "../include/lista.h"

// Representación de 'Producto'.
// Se debe definir en producto.cpp.
// struct _rep_producto;
// Declaración del tipo 'Producto'.
struct _rep_producto{
	nat id;
	char* nombre;
	nat cantidadUnidades;
	TLista unidades;
};

/* Operaciones de producto */

/*
  Devuelve un 'producto'.
 */
Producto crearProducto(nat identificadorDeProducto, char* nombre){
	Producto nuevo = new _rep_producto;
	nuevo->id = identificadorDeProducto;
	nuevo->nombre = copiarCadenaChar(nombre);
	nuevo->unidades = crearLista();
	nuevo->cantidadUnidades = 0;
	return nuevo;
} 

/*
  Libera la memoria reservada por 'producto'.
 */
void liberarProducto(Producto producto){
	delete []producto->nombre;
	liberarLista(producto->unidades);
	delete producto;
}

/*
  Devuelve la cantidad de unidades 'producto'.
 */
nat obtenerCantidad(Producto producto){
	return producto->cantidadUnidades;
}

/*
  Devuelve el identificador de producto de 'producto'.
 */
nat obtenerIdentificadorDeProducto(Producto producto){
	return producto->id;
}

char* obtenerNombre(Producto producto){
	return producto->nombre;
}

/*
    Agrega cantidad elementos a la unidad.
    Pre: cantidad y f_venc deben ser mayores a cero. 
 */
void agregarUnidades(Producto producto, nat cantidad, TFecha f_venc){
	producto->cantidadUnidades += cantidad;
	producto->unidades = agregarAListaOrdenado(producto->unidades, f_venc, cantidad);
} 

/*
    Quita cantidad elementos al producto con fecha de vencimiento más
    próxima.
    Pre: cantidad debe ser mayor a cero.  
 */
void quitarUnidades(Producto producto, nat cantidad){
	producto->cantidadUnidades < cantidad ? producto->cantidadUnidades = 0 : producto->cantidadUnidades -= cantidad;
	producto->unidades = quitarDeLista(producto->unidades, cantidad);
} 

/*
    Quita todas las unidades de productos cuya fecha de vencimiento es menor a
    la fecha actual.  
 */
void quitarVencidos(Producto producto, TFecha fecha){
	bool continuar = true;
	while(!esVaciaLista(producto->unidades) && continuar){
		Vencimiento venc = obtenerMasViejo(producto->unidades);
		TFecha f_venc = obtenerFVencimiento(venc);
		if (compararFechas(f_venc, fecha) != 1){ // el vencimiento es menor o igual a la fecha
			producto->cantidadUnidades -= obtenerCantidad(venc);
			producto->unidades = quitarMasViejo(producto->unidades);
			liberarVencimiento(venc);
		}else{
			continuar = false; 
		}
	}
} 

/*
    Quita todos los productos que vencerán dentro de los próximos cantidadDias días.
    Por ejemplo si la fecha actual es 10 y cantidadDias es 5, entonces se deberán
    quitar las unidades que tengan fecha de vencimiento el día 15 o antes.
    Pre: cantidad debe ser mayor a cero.  
 */
void quitarProximosAVencer(Producto producto, nat cantidadDias){}

/*
  Imprime los datos del producto en el formato específicado en la letra.
 */
void imprimirProducto(Producto producto){
  printf("Información del producto %d - %s\n", producto->id, producto->nombre);
  printf("Total de unidades: %d\n", producto->cantidadUnidades);
  imprimirInfoLista(producto->unidades);
} 