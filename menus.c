#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "macros.h"

int menuBienvenida(int [FIL][COL], int, int);
void menuPrincipal(int [FIL][COL], int, int);
void menuAyuda (int [FIL][COL], int, int);
void menuCargar(int [FIL][COL], int, int);
void validarCarga (int [FIL][COL], int, int, char);
void posAyudaRandom (int [FIL][COL], int);
void easySudoku (int [FIL][COL]);
void mediumSudoku (int [FIL][COL]);
void hardSudoku (int [FIL][COL]);
void mostrarSudoku (int [FIL][COL]);
int comprobarFila(int [FIL][COL], int, int);
int comprobarColumna(int [FIL][COL], int, int);
int comprobarCuadrantes(int [FIL][COL], int, int, int);
int comprobarFCC (int [FIL][COL], int, int, int);
int comprobarVictoria(int [FIL][COL]);
int comprobarTablero(int [FIL][COL]);
void clearScreen(void);
void redColor(void);
void greenColor(void);
void yellowColor(void);
void resetColor(void);

extern int SOLUCION[FIL][COL];
extern int COPY[FIL][COL];

int menuBienvenida(int TABLERO[FIL][COL], int cont, int dificultad){
    char option = '1'; clearScreen();
    yellowColor();printf("\n费尔南多·比利亚尔 BIENVENIDO A SUDOKU 费尔南多·比利亚尔\n");resetColor();
    if (comprobarVictoria(TABLERO) == 0){
        printf("\nHAS GANADO!!!\n");
        mostrarSudoku(TABLERO);
    }
    printf("\n1 - Easy\n");
    printf("2 - Medium\n");
    printf("3 - Hard\n");
    if (comprobarTablero(TABLERO) != 0){
        printf("\n4 - Volver al Menu Principal\n");
    }
    else printf("\n");
    printf("5 - Salir del juego\n");
    printf("\nSeleccione la opcion que desee: ");
    scanf(" %c", &option);
    if (isdigit(option) == 1){
        if (option == '1'){
            cont = 0;
            dificultad = 1;
            easySudoku(TABLERO);
            menuPrincipal(TABLERO, cont, dificultad);
        }
        else if (option == '2'){
            cont = 0;
            dificultad = 2;
            mediumSudoku(TABLERO);
            menuPrincipal(TABLERO, cont, dificultad);
        }
        else if (option == '3'){
            cont = 0;
            dificultad = 3;
            hardSudoku(TABLERO);
            menuPrincipal(TABLERO, cont, dificultad);
        }
        else if (option == '4'){
            if (comprobarVictoria(TABLERO) != 0){
                menuPrincipal(TABLERO, cont, dificultad);
            }
            else {
                printf("\nOpcion no valida\n");
                sleep(1);
                menuBienvenida(TABLERO, cont, dificultad);

            }
        }
        else if (option == '5'){
            int query;
            printf("\nEsta seguro que desea salir de SUDOKU?\n");
            printf("Si sale se perdera toda la informacion cargada\n");
            printf("Responda SI");greenColor();printf(" [1]");resetColor();
            printf(" o NO");redColor();printf(" [0]: ");resetColor();
            scanf("%d", &query);
            if (query == 1){
                return 0;
            }
            else {
                menuBienvenida(TABLERO, cont, dificultad);
            }
        }
        else {
            printf("\nOpcion no valida\n");
            sleep(1);
            menuBienvenida(TABLERO, cont, dificultad);
        }
    }
    else {
        printf("\nOpcion no valida, ingrese un entero\n");
        sleep(1);
        menuBienvenida(TABLERO, cont, dificultad);
    }

    return 0;
}

void menuPrincipal(int TABLERO[FIL][COL], int cont, int dificultad){
    char option = '1'; clearScreen();
    yellowColor();printf("\n费尔南多·比利亚尔 BIENVENIDO AL MENU PRINCIPAL 费尔南多·比利亚尔\n");resetColor();
    printf("\n1 - Menu de Carga\n");
    if (cont < dificultad+2){
    printf("2 - Menu de Ayuda\n");
    }
    printf("3 - Volver atras\n");
    mostrarSudoku(TABLERO);
    printf("\nSeleccione la opcion que desee: ");
    scanf(" %c", &option);
    if (isdigit(option) != 0){
        if (option == '1'){
            menuCargar(TABLERO, cont, dificultad);
        }
        else if ((option == '2') && (cont < dificultad+2)){
            menuAyuda(TABLERO, cont, dificultad);
        }
        else if (option == '3'){
            menuBienvenida(TABLERO, cont, dificultad);
        }
        else {
            printf("Opcion no valida\n");
            sleep(1);
            menuPrincipal(TABLERO, cont, dificultad);
        }
    }
    else {
        printf("\nOpcion no valida, ingrese un entero");
        sleep(1);
        menuPrincipal(TABLERO, cont, dificultad);
    }
}

void menuCargar (int TABLERO[FIL][COL], int cont, int dificultad){
    char query = '1'; clearScreen();
    yellowColor();printf("\n费尔南多·比利亚尔 BIENVENIDO AL MENU DE CARGA 费尔南多·比利亚尔\n");resetColor();
    mostrarSudoku(TABLERO);
    printf("\nAyudas otorgadas: %d / %d", cont, dificultad+2);
    printf("\nDesea cargar valores o salir\n");
    printf("Responda con ");greenColor();printf("[1]");resetColor();printf(" o ");
    redColor();printf("[0]");resetColor();printf(" respectivamente: ");
    scanf(" %c", &query);
    if (isdigit(query) != 0){
        if (query == '1'){
            mostrarSudoku(TABLERO);
            validarCarga(TABLERO, cont, dificultad, query);
            if (comprobarVictoria(TABLERO) == 0){
                menuBienvenida(TABLERO, cont, dificultad);
            } else {
                mostrarSudoku(TABLERO);
                menuCargar(TABLERO, cont, dificultad);
            }
        }
        else if (query == '0'){
            menuPrincipal(TABLERO, cont, dificultad);
        }
        else {
            printf("\nOpcion no valida\n");
            menuCargar(TABLERO, cont, dificultad);
        }
    }
    else {
        printf("\nOpcion no valida, ingrese un entero\n");
        sleep(1);
        menuCargar(TABLERO, cont, dificultad);
    }
}

void validarCarga (int TABLERO[FIL][COL], int cont, int dificultad, char query){
    clearScreen(); mostrarSudoku(TABLERO);
    int fil, col, num;
    while (query == '1'){
        printf("\nIngrese Fila: ");
        scanf("%d", &fil);
        if (fil < 1 || fil > 9){
            printf("Numero fuera de rango\n");
            break;
        }
        printf("Ingrese Columna: ");
        scanf("%d", &col);
        if (col < 1 || col > 9){
            printf("Numero fuera de rango\n");
            sleep(1);
            break;
        }
        if (COPY[fil-1][col-1] != 0){
            printf("\nERROR!!! el casillero no es modificable\n");
            sleep(1);
            break;
        }
        printf("Ingrese Valor: ");
        scanf("%d", &num);
        if (num < 0 || num > 9){
            printf("Numero fuera de rango\n");
            sleep(1);
            break;
        }
        else if (comprobarFCC(TABLERO, fil, col, num) == 1){
            break;
        }
        else {
            TABLERO[fil-1][col-1] = num;
            if (TABLERO[fil-1][col-1] == SOLUCION[fil-1][col-1]){
                COPY[fil-1][col-1] = num;
            }
        }
        break;
    }
}

void menuAyuda (int TABLERO[FIL][COL], int cont, int dificultad){
    int help; clearScreen();
    yellowColor();printf("\n费尔南多·比利亚尔 BIENVENIDO AL MENU DE AYUDA 费尔南多·比利亚尔\n");resetColor();
    while (cont < dificultad+2){
        printf("\nAyudas otorgadas: %d / %d\n", cont, dificultad+2);
        printf("Requiere ayuda o desea salir del menu\n");
        printf("Responda con ");greenColor();printf("[1]");resetColor();printf(" o ");
        redColor();printf("[0]");resetColor();printf(" respectivamente: ");
        scanf("%d", &help);
        if (help == 1){
            cont += 1;
            posAyudaRandom(TABLERO, cont);
            if (comprobarVictoria(TABLERO) == 0){
                menuBienvenida(TABLERO, cont, dificultad);
                break;
            }
            mostrarSudoku(TABLERO);
        }
        else {
            menuPrincipal(TABLERO, cont, dificultad);
            break;
        }
    }
    if (cont == dificultad+2){
        menuCargar(TABLERO, cont, dificultad);
    }
}

void mostrarSudoku (int TABLERO[FIL][COL]){
    for (int x = 0; x < FIL; x++){
        if (x % 3 == 0){
            printf("\n");
        }
        for (int y = 0; y < COL; y++){
            if (y % 3 == 0){
                printf(" ");
            }
            printf("[%d]", TABLERO[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void clearScreen(void){
    system("clear");
}

void redColor(void){
    printf("\033[1;31m");
}
void greenColor(void){
    printf("\033[1;32m");
}
void yellowColor(void){
    printf("\033[0;33m");
}
void resetColor(void){
    printf("\033[0m");
}
