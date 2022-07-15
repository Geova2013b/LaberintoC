#include "solucion.h"

//Metodo que verifica si el laberinto posee solucion
void solucion(int cont, int numColunmas, char Matriz[cont][numColunmas]){
    int fila,columna;
    int x,y;
    int solucion = 0;

    for( fila=0; fila<cont; fila++){
        for( columna=0; columna<numColunmas; columna++){
            //Se recorre la matriz con un for en busca de un "2"
            if(Matriz[fila][columna] == '2'){
                x=fila;
                y=columna;
                //Si existe un "2" se llama a busca solucion
                solucion = buscaSolucion(x, y, cont, numColunmas, Matriz);
                if(solucion == 1){
                    fila = cont;
                    printf("Solucion (%d,%d)\n", x, y);
                }

            }
        }
    }

    if(solucion != 1){
        printf("No hay Solucion\n");
    }

}


//Funcion que se encarga de buscar el camino de la solucion
int buscaSolucion(int x, int y, int cont, int numColunmas, char Matriz[cont][numColunmas]){

    int fin = 0;
    int xmenos = 0;
    int xmas = 0;
    int ymenos = 0;
    int ymas = 0;
    int vacio = 0;

    do{
            //Por medio de "if" anidados se determina que camino debe tomar
            if(Matriz[x][y + 1] == '1' && ymenos == 0){
                ymas = 1;
                xmenos = 0;
                xmas = 0;
                y = y + 1;
            }else{
                if(Matriz[x + 1][y] == '1' && xmenos == 0){
                    ymenos = 0;
                    ymas = 0;
                    xmas = 1;
                    x = x + 1;
                }else{
                    if(Matriz[x][y - 1] == '1' && ymas == 0){
                        ymenos = 1;
                        xmenos = 0;
                        xmas = 0;
                        y = y - 1;
                    }else{
                        if(Matriz[x - 1][y] == '1' && xmas == 0){
                                ymenos = 0;
                                ymas = 0;
                                xmenos = 1;
                                x = x - 1;
                        }else{
                            vacio = 1;
                        }
                    }
                }
            }
            if(x == 0 || x == cont){
                fin = 1;
            }
            if(y == 0 || y == numColunmas){
                fin = 1;
            }

    }while(vacio == 0);

    //El ciclo finaliza si se llega a un borde y se retorna fin para su respectiva desicion en el metodo "solucion"
    return fin;
}

