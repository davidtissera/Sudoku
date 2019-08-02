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
    int x, y;
    x = (fil-1)/3;
    y = (col-1)/3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3;j++){
            if (TABLERO[3 * x+i][3 * y+j] == num){
                return 1;
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
    srand(getpid());
    int A[81], k = 0;
    for (int i = 0; i < FIL; i++){
        for (int j = 0; j < COL; j++){
            if (COPY[i][j] == 0){
                A[k] = (i*10)+j;
                k++;
            }
        }
    }
    int cord = A[rand() % k];
    int x = cord / 10;
    int y = cord % 10;
    TABLERO[x][y] = SOLUCION[x][y];
    COPY[x][y] = SOLUCION[x][y];
    printf("\nLa ayuda fue otorgada en la posicion: [%d][%d]\n", x+1, y+1);
}
