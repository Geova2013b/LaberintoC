/*
Geovanny Bonilla Espinoza
Programación bajo plataformas abiertas
Proyecto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char informacion[100];
    int cont = 0;
    int numColunmas = 0;
    char matriz[100];
    char matrizAux[100];

    FILE *archivo;

    //Asignacion del txt a la variable archivo
    archivo = fopen("./laberinto.txt", "r");


    //Por medio de un contador se obtienen el numero de filas de la matriz
    while(!feof(archivo)){
        fgets(informacion,100,archivo);
        cont ++;
    }
    rewind(archivo);

    //Aginacion de una matriz auxiliar para su uso
    for(int in = 0; !feof(archivo); in++){
        fscanf(archivo,"%s",&matriz[in]);
        matrizAux[in] = matriz[in];
    }
    rewind(archivo);

    //Se obtiene el numero total de elementos de la matriz
    while(!feof(archivo)) {
            fscanf(archivo,"%s",&matriz);
            numColunmas++;
         }
    fclose(archivo);

    //Mediante el numero de filas y el numero total de elementos, se obtiene el numero de columnas
    numColunmas = numColunmas/cont;

    //Definicion de matriz con su numero respectivo de filas y columnas
    char Matriz[cont][numColunmas];

    //Llamado a funcion que asina los elementos a las posiciones de la matriz
    FilaColumna(cont, numColunmas, Matriz, matrizAux);

    //Llamado a funcion que verifica la existencia de bordes en la matriz
    if(determinaBorde(cont, numColunmas, Matriz) == 1){

        //Llamado a funcion que recorre la matriz en busca de la solucion
        solucion(cont, numColunmas, Matriz);
    }else{
        printf("No hay solucion");
    }
}

