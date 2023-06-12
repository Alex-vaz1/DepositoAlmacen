/* 1234567 */
/*
  Módulo de implementación de 'utils'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"

#include "stdio.h"
#include "string.h"

nat* leerFecha() {
  nat* fecha = new nat[3];
  scanf("%u/%u/%u", &fecha[0], &fecha[1], &fecha[2]);
  return fecha;
}

nat leerNat() {
  nat res;
  scanf("%u", &res);
  return res;
}

char leerChar() {
  char res;
  scanf(" %c", &res);
  return res;
}

double leerDouble() {
  double res;
  scanf("%lf", &res);
  return res;
}

void leerChars(ArregloChars cs) { scanf("%s", cs); }

void leerRestoLinea(ArregloChars cs) { scanf("%[^\n]", cs); }

char* copiarCadenaChar(char* cadenaChar){
	char* copia = new char[strlen(cadenaChar)+1];
	strcpy(copia, cadenaChar);
	return copia;
}

bool igualesCadenaCHar(char* cadenaA, char* cadenaB){
  return strcmp(cadenaA, cadenaB) == 0;
}

/*
Tarea 3 :: Nueva función. 
Devuelve un número que representa el índice en el arreglo que debe 
tener un producto cuyo nombre se pasa como parámetro en la variable 'cadena'.
*/
nat funcionHash(char* cadena){
  nat ret = 0;
  int len = strlen(cadena);
  for(int i = 0; i < len; i++){
    ret += cadena[i]*(i+1);
  }
  return (ret % CANTIDAD_PROD);
}
