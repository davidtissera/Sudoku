#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "macros.h"

extern int SOLUCION[FIL][COL];
extern int COPY[FIL][COL];

int comprobarFila(int TABLERO[FIL][COL], int fil, int num){
    for (int i = 0; i < COL; i++){
        if (TABLERO[fil-1][i] == num){
            return 1;
        }
    }

    return 0;
}

int comprobarColumna(int TABLERO[FIL][COL], int col, int num){
    for (int i = 0; i < FIL; i++){
        if (TABLERO[i][col-1] == num){
            return 1;
        }
    }
    return 0;
}

int comprobarCuadrantes(int TABLERO[FIL][COL], int fil, int col, int num){
    if (fil-1 < FIL/3 && col-1 < COL/3){
        for (int i = 0; i < FIL/3; i++){
            for (int j = 0; j < COL/3; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }
    if (fil-1 < FIL/3 && col > COL/3 && col-1 < COL-3){
        for (int i = 0; i < FIL/3; i++){
            for (int j = COL/3; j < COL-3; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }
    if (fil-1 < FIL/3 && col > COL-3 && col-1 < COL){
        for (int i = 0; i < FIL/3; i++){
            for (int j = COL-3; j < COL; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }
    if (fil > FIL/3 && fil-1 < FIL-3 && col-1 < COL/3){
        for (int i = FIL/3; i < FIL-3; i++){
            for (int j = 0; j < COL/3; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }
    if (fil > FIL/3 && fil < FIL-3 && col > COL/3 && col-1 < COL-3){
        for (int i = FIL/3; i < FIL-3; i++){
            for (int j = COL/3; j < COL-3; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }
    if (fil > FIL/3 && fil-1 < FIL-3 && col > COL-3 && col-1 < COL){
        for (int i = FIL/3; i < FIL-3; i++){
            for (int j = COL-3; j < COL; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }
    if (fil > FIL-3 && fil-1 < FIL && col-1 < COL/3){
        for (int i = FIL-3; i < FIL; i++){
            for (int j = 0; j < COL/3; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }
    if (fil > FIL-3 && fil-1 < FIL && col > COL/3 && col-1 < COL-3){
        for (int i = FIL-3; i < FIL; i++){
            for (int j = COL/3; j < COL-3; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }
    if (fil > FIL-3 && fil-1 < FIL && col > COL-3 && col-1 < COL){
        for (int i = FIL-3; i < FIL; i++){
            for (int j = COL-3; j < COL; j++){
                if (TABLERO[i][j] == num){
                    return 1;
                }
            }
        }
    }

    return 0;
}

int comprobarFCC (int TABLERO[FIL][COL], int fil, int col, int num){
    if (comprobarFila(TABLERO, fil, num) == 1){
        printf("\nERROR!!!, el numero ya esta en la fila\n");
        sleep(1);
        return 1;
    }
    if (comprobarColumna(TABLERO, col, num) == 1){
        printf("\nERROR!!!, el numero ya esta en la columna\n");
        sleep(1);
        return 1;
    }
    if (comprobarCuadrantes(TABLERO, fil, col, num) == 1){
        printf("\nERROR!!!, el numero ya se encuentra en el cuadrante\n");
        sleep(1);
        return 1;
    }

    return 0;
}

int comprobarVictoria(int TABLERO[FIL][COL]){
    for (int i = 0; i < FIL; i++){
        for (int j = 0; j < COL; j++){
            if (TABLERO[i][j] != SOLUCION[i][j]){
                return 1;
            }
        }
    }
    return 0;
}

int comprobarTablero(int TABLERO[FIL][COL]){
    for (int i = 0; i < FIL; i++){
        for (int j = 0; j < COL; j++){
            if (TABLERO[i][j] != 0){
                return 1;
            }
        }
    }
    return 0;
}

void posAyudaRandom(int TABLERO[FIL][COL], int cont){
    //srand(time(NULL));
    srand(getpid());
    //se define un Array en donde se guardaran coordenadas
    int A[81], k = 0;
    for (int i = 0; i < FIL; i++){
        for (int j = 0; j < COL; j++){
            //Se guardan las coordenadas de los numeros que tengan 0 en la matriz
            if (COPY[i][j] == 0){
                //se codifican ambos numeros en uno solo
                A[k] = (i*10)+j;
                k++;
            }
        }
    }
    int cord = A[rand() % k];
    //se decodifica el numero correspondiente a la fila
    int x = cord / 10;
    //se decodifica el numero correspondiente a la columna
    int y = cord % 10;
    //se reemplaza el valor de la matriz de trabajo con el correspondiente en esa coordenada de la matriz solucion
    TABLERO[x][y] = SOLUCION[x][y];
    //se reemplaza el valor de la matriz copia con el correspondiente en esa coordenada de la matriz solucion
    //para no volver a evaluar en la proxima llamada a la funcion sobre ese casillero que ya no tendra un 0.
    COPY[x][y] = SOLUCION[x][y];
    printf("\nLa ayuda fue otorgada en la posicion: [%d][%d]\n", x+1, y+1);
}
