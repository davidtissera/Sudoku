#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "macros.h"
#include "tablerosEasy.h"
#include "tablerosMedium.h"
#include "tablerosHard.h"
#include "solucionesEasy.h"
#include "solucionesMedium.h"
#include "solucionesHard.h"
#include "EasyWin.h"

extern int SOLUCION[FIL][COL];
extern int COPIA[FIL][COL];

void easySudoku (int TABLERO[FIL][COL]){
    static int sumE = 0;
    for (int i = 0; i < FIL; i++){
        for (int j = 0; j < COL; j++){
            TABLERO[i][j] = EASY_WIN[sumE][i][j];
            //TABLERO[i][j] = EASY_ALL[sumE][i][j];
            COPIA[i][j] = EASY_WIN[sumE][i][j];
            SOLUCION[i][j] = SOL_EASY[sumE][i][j];
        }
    }
    if (sumE < 9) sumE++;
    else sumE = 0;
}

void mediumSudoku(int TABLERO[FIL][COL]){
    static int sumM = 0;
    for (int i = 0; i < FIL; i++){
        for (int j = 0; j < COL; j++){
            TABLERO[i][j] = MEDIUM_ALL[sumM][i][j];
            COPIA[i][j] = MEDIUM_ALL[sumM][i][j];
            SOLUCION[i][j] = SOL_MEDIUM[sumM][i][j];
        }
    }
    if (sumM < 9) sumM++;
    else sumM = 0;
}

void hardSudoku (int TABLERO[FIL][COL]){
    static int sumH = 0;
    for (int i = 0; i < FIL; i++){
        for (int j = 0; j < COL; j++){
            TABLERO[i][j] = HARD_ALL[sumH][i][j];
            COPIA[i][j] = HARD_ALL[sumH][i][j];
            SOLUCION[i][j] = SOL_HARD[sumH][i][j];
        }
    }
    if (sumH < 9) sumH++;
    else sumH = 0;
}