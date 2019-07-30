    #include "sudoku.h"

    int EASY_515[FIL][COL] = {
        0,0,0,1,0,0,0,8,0,
        5,0,6,3,0,0,0,0,1,
        0,0,0,0,0,9,0,3,5,
        0,0,7,0,0,3,0,0,0,
        0,0,1,7,0,0,0,6,0,
        9,6,0,0,0,8,0,0,0,
        0,0,4,0,3,0,0,9,7,
        0,3,0,2,0,0,8,5,0,
        0,0,8,0,5,6,0,0,4
    };
    int EASY_516[FIL][COL] = {
        0,2,0,0,0,9,6,0,0,
        0,9,3,0,0,0,4,0,0,
        0,7,0,0,3,0,5,8,0,
        7,0,0,3,0,0,8,0,0,
        0,1,0,0,0,6,0,9,2,
        0,0,6,0,0,5,0,0,3,
        0,0,2,0,4,1,0,0,0,
        0,0,0,0,5,0,0,0,0,
        0,0,0,0,0,0,3,0,0
    };
    int EASY_517[FIL][COL] = {
        0,0,0,2,0,0,5,6,7,
        0,0,0,5,0,8,0,0,1,
        3,0,0,0,0,0,8,0,4,
        8,0,0,0,0,1,0,0,0,
        1,0,2,0,0,0,3,7,8,
        0,6,0,0,0,0,0,0,0,
        2,0,7,0,5,0,0,1,0,
        0,0,0,0,0,3,2,0,0,
        0,3,0,4,0,9,0,0,0
    };
    int EASY_518[FIL][COL] = {
        6,0,0,5,0,0,7,0,0,
        0,9,0,2,4,0,0,3,0,
        4,0,0,0,0,0,0,0,0,
        0,0,0,0,3,8,0,4,7,
        0,0,0,4,0,0,8,0,0,
        0,0,9,7,0,5,0,0,6,
        0,6,0,0,2,0,0,8,3,
        1,0,0,0,0,0,0,0,9,
        0,0,0,0,8,0,6,0,0
    };
    int EASY_519[FIL][COL] = {
        1,0,0,0,5,0,7,0,0,
        0,5,0,2,0,0,3,8,9,
        0,0,4,0,3,8,0,0,0,
        0,0,8,0,0,9,0,7,0,
        2,0,0,0,0,0,4,9,0,
        0,0,5,0,0,0,0,0,0,
        3,7,6,0,0,0,0,0,5,
        0,0,0,0,0,0,8,0,1,
        0,0,0,0,0,3,2,6,0
    };
    int EASY_520[FIL][COL] = {
        3,6,0,0,0,0,0,9,0,
        0,8,9,5,0,0,0,2,0,
        0,0,5,0,9,2,0,0,0,
        0,0,0,0,8,5,0,0,0,
        0,0,7,0,4,1,3,0,0,
        0,1,6,2,0,0,7,0,0,
        0,7,0,0,0,0,0,0,2,
        0,0,0,0,5,0,0,6,0,
        0,0,0,4,0,0,2,8,0
    };
    int EASY_521[FIL][COL] = {
        0,1,0,0,0,0,0,0,0,
        0,0,0,0,8,0,0,0,0,
        2,0,0,3,9,0,0,0,6,
        5,0,0,8,0,0,0,4,9,
        0,9,0,0,1,0,3,6,0,
        0,0,0,0,0,0,7,0,1,
        0,3,0,2,0,5,0,7,0,
        7,0,5,0,6,0,0,0,0,
        0,0,6,7,0,0,0,9,0
    };
    int EASY_522[FIL][COL] = {
        6,0,4,0,0,0,9,2,8,
        3,9,0,0,0,0,0,1,6,
        0,0,0,0,0,0,0,0,0,
        0,5,0,2,0,7,0,0,0,
        9,0,1,8,4,0,0,0,0,
        0,7,0,9,0,3,0,0,0,
        0,0,0,5,0,0,0,0,1,
        8,0,0,0,0,0,0,6,3,
        0,0,0,7,0,8,0,0,0
    };
    int EASY_523[FIL][COL] = {
        7,3,0,0,0,0,0,2,0,
        5,0,0,9,0,0,8,0,4,
        2,0,2,3,4,0,5,0,0,
        0,0,0,0,7,0,0,8,9,
        9,0,6,2,5,0,0,0,0,
        4,0,0,0,0,0,2,0,0,
        0,0,7,0,0,0,0,0,0,
        0,0,0,0,3,1,0,0,5,
        0,4,3,0,0,0,0,1,0
    };
    int EASY_524[FIL][COL] = {
        0,0,0,0,9,0,6,5,0,
        0,0,0,0,0,0,0,0,7,
        0,0,0,5,0,7,0,4,0,
        0,5,2,0,1,0,0,0,0,
        0,0,0,0,2,9,0,0,0,
        0,3,0,4,0,0,0,0,9,
        0,1,6,0,5,0,2,3,0,
        8,0,0,0,0,4,7,0,0,
        0,0,0,0,7,3,0,9,0
    };
    int SOL_515[FIL][COL] = {
        4,9,3,1,7,5,6,8,2,
        5,8,6,3,2,4,9,7,1,
        7,1,2,6,8,9,4,3,5,
        8,2,7,5,6,3,1,4,9,
        3,4,1,7,9,2,5,6,8,
        9,6,5,4,1,8,7,2,3,
        6,5,4,8,3,1,2,9,7,
        1,3,9,2,4,7,8,5,6,
        2,7,8,9,5,6,3,1,4,
    };
    int SOL_516[FIL][COL] = {
        4,2,8,5,7,9,6,3,1,
        5,9,3,1,6,8,4,2,7,
        6,7,1,2,3,4,5,8,9,
        7,4,9,3,1,2,8,5,6,
        3,1,5,4,8,6,7,9,2,
        2,8,6,7,9,5,1,4,3,
        8,3,2,6,4,1,9,7,5,
        9,6,7,8,5,3,2,1,4,
        1,5,4,9,2,7,3,6,8,
    };
    int SOL_517[FIL][COL] = {
        9,1,8,2,3,4,5,6,7,
        7,2,4,5,6,8,9,3,1,
        3,5,6,9,1,7,8,2,4,
        8,7,9,3,4,1,6,5,2,
        1,4,2,6,9,5,3,7,8,
        5,6,3,7,8,2,1,4,9,
        2,9,7,8,5,6,4,1,3,
        4,8,5,1,7,3,2,9,6,
        6,3,1,4,2,9,7,8,5
    };
    int SOL_518[FIL][COL] = {
        6,8,2,5,9,3,7,1,4,
        7,9,1,2,4,6,5,3,8,
        4,5,3,8,7,1,9,6,2,
        5,2,6,9,3,8,1,4,7,
        3,1,7,4,6,2,8,9,5,
        8,4,9,7,1,5,3,2,6,
        9,6,5,1,2,7,4,8,3,
        1,3,8,6,5,4,2,7,9,
        2,7,4,3,8,9,6,5,1,
    };
    int SOL_519[FIL][COL] = {
        1,8,3,9,5,6,7,2,4,
        6,5,7,2,1,4,3,8,9,
        9,2,4,7,3,8,1,5,6,
        4,3,8,1,6,9,5,7,2,
        2,6,1,3,7,5,4,9,8,
        7,9,5,4,8,2,6,1,3,
        3,7,6,8,2,1,9,4,5,
        5,4,2,6,9,7,8,3,1,
        8,1,9,5,4,3,2,6,7,
    };
    int SOL_520[FIL][COL] = {
        3,6,2,1,7,4,8,9,5,
        7,8,9,5,6,3,1,2,4,
        1,4,5,8,9,2,6,7,3,
        9,3,4,7,8,5,2,1,6,
        8,2,7,6,4,1,3,5,9,
        5,1,6,2,3,9,7,4,8,
        4,7,8,9,1,6,5,3,2,
        2,9,1,3,5,8,4,6,7,
        6,5,3,4,2,7,9,8,1,
    };
    int SOL_521[FIL][COL] = {
        9,1,4,5,2,6,8,3,7,
        6,5,3,1,8,7,9,2,4,
        2,7,8,3,9,4,1,5,6,
        5,6,1,8,7,3,2,4,9,
        8,9,7,4,1,2,3,6,5,
        3,4,2,6,5,9,7,8,1,
        1,3,9,2,4,5,6,7,8,
        7,2,5,9,6,8,4,1,3,
        4,8,6,7,3,1,5,9,2,
    };
    int SOL_522[FIL][COL] = {
        6,1,4,3,7,5,9,2,8,
        3,9,7,4,8,2,5,1,6,
        5,8,2,6,9,1,3,4,7,
        4,5,8,2,1,7,6,3,9,
        9,3,1,8,4,6,2,7,5,
        2,7,6,9,5,3,1,8,4,
        7,2,3,5,6,4,8,9,1,
        8,4,5,1,2,9,7,6,3,
        1,6,9,7,3,8,4,5,2,
    };
    int SOL_523[FIL][COL] = {
        7,3,4,8,1,5,9,2,6,
        5,6,1,9,2,7,8,3,4,
        8,9,2,3,4,6,5,7,1,
        3,2,5,1,7,4,6,8,9,
        9,7,6,2,5,8,1,4,3,
        4,1,8,6,9,3,2,5,7,
        1,5,7,4,6,2,3,9,8,
        2,8,9,7,3,1,4,6,5,
        6,4,3,5,8,9,7,1,2,
    };
    int SOL_524[FIL][COL] = {
        3,7,4,8,9,2,6,5,1,
        5,2,9,6,4,1,3,8,7,
        1,6,8,5,3,7,9,4,2,
        9,5,2,3,1,6,4,7,8,
        4,8,1,7,2,9,5,6,3,
        6,3,7,4,8,5,1,2,9,
        7,1,6,9,5,8,2,3,4,
        8,9,3,2,6,4,7,1,5,
        2,4,5,1,7,3,8,9,6,
    };
    int MEDIUM[FIL][COL] = {
        0,0,2,9,0,5,0,0,0,
        0,0,0,0,0,6,0,0,3,
        7,0,1,0,0,8,4,0,0,
        0,0,0,7,0,0,0,0,4,
        0,9,6,3,0,0,0,0,0,
        0,0,0,0,0,1,2,0,0,
        0,0,0,0,0,0,0,0,2,
        0,0,0,0,8,0,3,9,0,
        3,5,0,0,0,0,0,0,0,
    };
    int SOL_MEDIUM[FIL][COL] = {
        8,3,2,9,4,5,6,1,7,
        9,4,5,1,7,6,8,2,3,
        7,6,1,2,3,8,4,5,9,
        5,1,8,7,6,2,9,3,4,
        2,9,6,3,5,4,7,8,1,
        4,7,3,8,9,1,2,6,5,
        6,8,9,4,1,3,5,7,2,
        1,2,4,5,8,7,3,9,6,
        3,5,7,6,2,9,1,4,8,
    };
    int HARD[FIL][COL] = {
        9,0,3,0,0,0,0,0,6,
        0,0,0,0,0,2,0,0,0,
        0,6,0,3,7,0,0,0,9,
        3,0,1,6,0,0,0,0,0,
        0,0,0,2,0,1,0,0,0,
        0,0,0,0,0,0,0,3,4,
        0,1,8,0,2,0,7,0,0,
        0,0,6,8,0,0,0,9,5,
        0,0,0,0,0,0,0,8,0,
    };
    int SOL_HARD[FIL][COL] = {
        9,7,3,1,8,4,5,2,6,
        8,5,4,9,6,2,3,1,7,
        1,6,2,3,7,5,8,4,9,
        3,8,1,6,4,7,9,5,2,
        4,9,5,2,3,1,6,7,8,
        6,2,7,5,9,8,1,3,4,
        5,1,8,4,2,9,7,6,3,
        7,4,6,8,1,3,2,9,5,
        2,3,9,7,5,6,4,8,1,
    };