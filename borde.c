
#include "borde.h"

//Funcion que retorna un estado "1" o "0"
int determinaBorde(int cont, int numColunmas, char Matriz[cont][numColunmas]){

    int borde;
    int fila,columna;

        //Determina si existe un "1" en la fila 0
        for( columna=0; columna<numColunmas; columna++){
            if(Matriz[0][columna] == '1'){
                borde = 1;
            }
        }

        //Determina si existe un "1" en la ultima fila
        for( columna=0; columna<numColunmas; columna++){
            if(Matriz[cont-1][columna] == '1'){
                borde = 1;
            }
        }

        //Determina si existe un "1" en la columna 0
        for( fila=0; fila<cont; fila++){
            if(Matriz[fila][0] == '1'){
                borde = 1;
            }
         }

        //Determina si existe un "1" en la ultima columna
        for( fila=0; fila<cont; fila++){
            if(Matriz[fila][numColunmas-1] == '1'){
                borde = 1;
            }
         }

    return borde;
}
