/* 1234567 */

/*
  Módulo de implementación de 'GestionDeposito'.

  Los elementos de tipo 'GestionDeposito' son punteros a una estructura (que debe
  definirse en gestionDeposito.cpp).

  Laboratorio de Programación 2 2do semestre 2022.
  InCo-FIng-UDELAR
*/

#include "../include/utils.h"
#include "../include/fecha.h"
#include "../include/gestionDeposito.h"
#include "../include/deposito.h"

// Representación de 'GestionDeposito'.
// Se debe definir en gestionDeposito.cpp.
// struct _rep_gestionDeposito;
// Declaración del tipo 'GestionDeposito'.
struct _rep_gestionDeposito{
	TDeposito deposito;
};

/* Operaciones para controlar el depósito.*/
/* Operaciones de gestionDeposito */

/*
  Devuelve un 'gestionDeposito' sin productos asignados.
 */
TGestionDeposito crearGestionDeposito() { 
	TGestionDeposito nuevo = new _rep_gestionDeposito;
	nuevo->deposito = crearDeposito();
	return nuevo;
};

/*
  Libera la memoria reservada por 'gestionDeposito' y por las subestructuras utilizadas. 
 */
void liberarGestionDeposito(TGestionDeposito gestionDeposito) {
	liberarDeposito(gestionDeposito->deposito);
	delete gestionDeposito;
};

/* 
  Se deben retirar todos los productos cuya fecha de 
  vencimiento sea menor o igual que la fecha que se pasa por parametro.
  Recordar que los productos pueden quedar con cantidad 0.   
*/
void quitarVencidosDeposito(TGestionDeposito gestionDeposito, TFecha fecha) {
	quitarVencidosDeposito(gestionDeposito->deposito, fecha);
};

/*
  Agrega un producto con identificador idProd y nombre nombreProducto al deposito.
*/
bool agregarProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, char* nombreProducto) {
	if (!existeProducto(gestionDeposito->deposito, idProd)){
		agregarProducto(gestionDeposito->deposito, idProd, nombreProducto);
		return true;
	}
	else
		return false;
};

/*
  Agrega 'cantidad' productos con identificador 'idProd' y con fecha de vencimiento 'f' de tipo TFecha. Si 'f_actual' es mayor a la fecha 'f' entonces el producto no se deberá agregar y la función debe devolver false. En caso contrario la función debe devolver true. 
  Si no existen unidades con esa fecha de vencimiento, entonces crea un vencimiento y agrega cantidad unidades. 
*/
bool agregarCantidadProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, nat cantidad, TFecha f, TFecha f_actual) { 
	if ((existeProducto(gestionDeposito->deposito, idProd)) && (definidaFecha(f_actual)) && (compararFechas(f_actual, f) != 1)){
		agregarUnidades(gestionDeposito->deposito, idProd, cantidad, f);
		return true;
	}
	else
		return false;
};

/*
  Quita cantidad productos con identificador idProd. 
  Si el producto no existe, entonces se debe devolver falso.
*/
bool quitarCantidadProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, nat cantidad) { 
	if (existeProducto(gestionDeposito->deposito, idProd)){
		quitarUnidades(gestionDeposito->deposito, idProd, cantidad);
		return true;
	}
	else
		return false; 
};

/*
  Quita un producto con identificador idProd que no tiene unidades.
  Si el producto no existe o tiene unidades entonces devuelve falso.
*/
bool quitarProductoDeposito(TGestionDeposito gestionDeposito, nat idProd) { //usada
	bool ret = false;
	if (existeProducto(gestionDeposito->deposito, idProd)){
		if (obtenerCantidadUnidades(gestionDeposito->deposito, idProd) == 0){
			eliminarProducto(gestionDeposito->deposito, idProd);
			ret = true;
		}
	}
	return ret;
};

/*
  Imprime la información de un producto con el formato especificado en gestionDeposito.h. 
  Se listan los vencimientos y cantidad por vencimiento para el producto. 
  Si el pedido no existe, entonces devuelve falso. 
 */
bool imprimirProductoResumenDeposito(TGestionDeposito gestionDeposito, nat idProd) {
	bool ret = false;
	if (existeProducto(gestionDeposito->deposito, idProd)){
		imprimirProducto(gestionDeposito->deposito, idProd);
		ret = true;
	}
	return ret;
};

/*
  Tarea 3 :: Nueva función
  Imprime la información de un producto con el formato especificado en la gestionDeposito.h. 
  Se listan los vencimientos y cantidad por vencimiento para el producto. 
  Si el pedido no existe, entonces devuelve falso. 
 */
bool imprimirProductoResumenDepositoPorNombre(TGestionDeposito gestionDeposito, char* nombreProducto) { return false; }

/*
    Quita todas las unidades que vencerán dentro de los próximos 7 días.
    Se denen quitar las unidades tanto del depósito.
 */
void quitarProximosAVencerDeposito(TGestionDeposito gestionDeposito, TFecha fecha) {
	aumentarFecha(fecha, 7);
	quitarVencidosDeposito(gestionDeposito->deposito, fecha);
};

/*
  Imprime el resumen del depósito en el formato especificado en gestionDeposito.h.
 */
void imprimirResumenGestionDeposito(TGestionDeposito gestionDeposito) {
	imprimirResumenDeposito(gestionDeposito->deposito);
};
