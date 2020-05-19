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


int sudokuRepresentation[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};


void printSudoku() {
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            printf("|%d", sudokuRepresentation[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}


bool isPossible(int row, int column, int number) {
    int x = floor(row / 3) * 3;
    int y = floor(column / 3) * 3;
    
    if (sudokuRepresentation[row][column] != 0) { return false; }
        
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
        printf("\n");
    }
    
    return true;
}



int main(int argc, const char * argv[]) {
    printSudoku();
    int row = 4;
    int column = 4;
    printf(isPossible(row, column, 4) ? "true\n" : "false\n");
    printf(isPossible(row, column, 5) ? "true\n" : "false\n");
    printf(isPossible(row, column, 6) ? "true\n" : "false\n");
    printf(isPossible(4, 1, 5) ? "true\n" : "false\n");
        
    for(int n = 0; n < 10; n++) {
        for(int row = 0; row < 9; row++) {
            for(int column = 0; column < 9; column++) {
                int acc = 0, lastNum = -1;
                
                if(row == 4 && column == 1) {
                    
                }
                
                for(int number = 1; number < 10; number++) {
                    if(isPossible(row, column, number)) {
                        acc++;
                        lastNum = number;
                    }
                }
                
                if(acc == 1) {
                    sudokuRepresentation[row][column] = lastNum;
                    printSudoku();
                }
            }
        }
        printSudoku();
    }

    
    printf("\n");
    return 0;
}



