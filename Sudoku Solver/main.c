//
//  main.c
//  Sudoku Solver
//
//  Created by Egbert-Jan Terpstra on 19/05/2020.
//  Copyright © 2020 Egbert-Jan Terpstra. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


//int sudokuRepresentation[9][9] = {
//    {5, 3, 0,   0, 7, 0,   0, 0, 0},
//    {6, 0, 0,   1, 9, 5,   0, 0, 0},
//    {0, 9, 8,   0, 0, 0,   0, 6, 0},
//
//    {8, 0, 0,   0, 6, 0,   0, 0, 3},
//    {4, 0, 0,   8, 0, 3,   0, 0, 1},
//    {7, 0, 0,   0, 2, 0,   0, 0, 6},
//
//    {0, 6, 0,   0, 0, 0,   2, 8, 0},
//    {0, 0, 0,   4, 1, 9,   0, 0, 5},
//    {0, 0, 0,   0, 8, 0,   0, 7, 9}
//};

int sudokuRepresentation[9][9] = {
    {5, 3, 0,   0, 7, 0,   0, 0, 0},
    {6, 0, 0,   1, 9, 5,   0, 0, 0},
    {0, 9, 8,   0, 0, 0,   0, 6, 0},

    {8, 0, 0,   0, 6, 0,   0, 0, 3},
    {4, 0, 0,   8, 0, 3,   0, 0, 1},
    {7, 0, 0,   0, 2, 0,   0, 0, 6},

    {0, 6, 0,   0, 0, 0,   2, 8, 0},
    {0, 0, 0,   4, 1, 9,   0, 0, 5},
    {0, 0, 0,   0, 8, 0,   0, 0, 0}
};

//int sudokuRepresentation[9][9] = {
//    {0, 5, 0,   7, 6, 0,   0, 0, 9},
//    {0, 2, 0,   0, 0, 0,   0, 0, 0},
//    {0, 0, 7,   9, 0, 0,   5, 0, 0},
//
//    {0, 1, 0,   0, 0, 2,   0, 0, 0},
//    {6, 0, 0,   0, 0, 1,   0, 0, 7},
//    {8, 7, 0,   5, 0, 0,   0, 0, 3},
//
//    {0, 0, 0,   3, 0, 0,   0, 4, 0},
//    {4, 0, 0,   0, 5, 0,   8, 0, 0},
//    {0, 0, 0,   0, 0, 0,   0, 0, 6},
//};

//int sudokuRepresentation[9][9] = {
//    {3, 0, 0, 5, 0, 0, 0, 9, 0},
//    {9, 0, 0, 4, 0, 3, 0, 0, 2},
//    {5, 0, 0, 9, 8, 2, 7, 0, 0},
//
//    {0, 0, 3, 6, 2, 4, 0, 0, 5},
//    {0, 0, 6, 1, 5, 9, 3, 0, 0},
//    {1, 5, 0, 7, 3, 8, 0, 0, 0},
//
//    {0, 0, 5, 8, 9, 0, 0, 0, 0},
//    {8, 0, 0, 3, 4, 7, 0, 0, 6},
//    {0, 3, 0, 2, 0, 5, 0, 0, 4},
//};

void printSudoku() {
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            printf("|%d", sudokuRepresentation[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}


bool isPossibleFor(int row, int column, int number) {
    int x = floor(row / 3) * 3;
    int y = floor(column / 3) * 3;
    
    //Check row of x pos and column of y pos
    for(int n = 0; n < 9; n++) {
        if(sudokuRepresentation[row][n] == number || sudokuRepresentation[n][column] == number) {
            return false;
        }
    }
        
    //Check square where number is in
    for(int n = 0; n < 3; n++) {
        for(int i = 0; i < 3; i++) {
            if(sudokuRepresentation[x+n][y+i] == number) {
                return false;
            }
        }
    }
    
    return true;
}

int counter = 0;

bool solve() {
    counter++;
    for(int row = 0; row < 9; row++) {
        for(int column = 0; column < 9; column++) {
            if(sudokuRepresentation[row][column] > 0) { continue; }
            printSudoku();
            for(int number = 1; number < 10; number++) {
                if (isPossibleFor(row, column, number)) {
                    sudokuRepresentation[row][column] = number;
                    if(solve()) {
                        return true;
                    }
                    sudokuRepresentation[row][column] = 0;
                }
            }
            return false;
        }
    }
    
    
    return true;
}

int main(int argc, const char * argv[]) {

    solve();
    printf("%d", counter);

    printf("\n");
    return 0;
}



