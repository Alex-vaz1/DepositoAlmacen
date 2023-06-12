/*
  Módulo de definición de 'utils'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h> // printf, scanf, sprintf

const int CANTIDAD_PROD = 100;

// tipo para los enteros no negativos
typedef unsigned int nat;

// tipos para arreglos
typedef nat *ArregloNats;       // arreglo de nat
typedef char *ArregloChars;     // arreglo de char
typedef bool *ArregloBools;     // arreglo de bool
typedef double *ArregloDoubles; // arreglo de double

// leen desde la entrada estándar y devuelven el elemento leído
nat* leerFecha();
nat leerNat();
char leerChar();
double leerDouble();

/*
  Lee en 'cs' desde la entreada estándar.
 */
void leerChars(ArregloChars cs);

/*
  Lee en 'cs' el resto de la línea de la entrada estandar sin consumir
  el cambi de línea.
 */
void leerRestoLinea(ArregloChars cs);

char* copiarCadenaChar(char* cadenaChar);

bool igualesCadenaCHar(char* cadenaA, char* cadenaB);

/*
Tarea 3 :: Nueva función. 
Devuelve un número que representa el índice en el arreglo que debe 
tener un producto cuyo nombre se pasa como parámetro en la variable 'cadena'.
*/
nat funcionHash(char* cadena);

#endif
