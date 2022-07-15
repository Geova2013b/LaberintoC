
#include "filacolumna.h"

//Funcion que asina los valores del arreglo a la funcion
void FilaColumna(int cont, int numColunmas, char Matriz[cont][numColunmas], char *matrizAux){

    int contador = 0;
    int fila,columna;

    //Mediante un contador se mueve el valor del arreglo y se asigna a la matriz
    for( fila=0; fila<cont; fila++){
        for( columna=0; columna<numColunmas; columna++){
            Matriz[fila][columna]=  matrizAux[contador];
                contador++;
            }
    }
}
