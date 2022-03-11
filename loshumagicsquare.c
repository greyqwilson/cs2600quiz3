//This file is meant to serve as the main file for Quiz 3 in Prof. Davarpanah's CS2600 class
//Author: Greyson Wilson
//Quiz 2: Problem 2 Lo Shu magic square - Makes a 3x3 square with numbers 
//        0->9 w/o replacement, then determine whether the square is a magic square
//Inputs: Nothing
//Outputs: A 3x3 magic square
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isLoShuSquare(int sq[][3]){

    //Horizontal and vertical
    int targetTotal = sq[0][0] + sq[0][1] + sq[0][2];

    for (int row=0; row < 3; row++){
        int lineHoriz = 0, lineVert = 0;
        for (int col=0; col < 3; col++){
            lineHoriz += sq[row][col];
            lineVert += sq[col][row];
        }

        if (lineHoriz != targetTotal || lineVert != targetTotal)
            return 0;
    }

    //Diagonal
    int lineUpRight = 0, lineDownRight = 0, col = 0;
    for (int row=2; row >= 0; row--){
        lineUpRight += sq[row][row];
        lineDownRight += sq[row][col];
        col++;
    }

    if (lineUpRight != targetTotal || lineDownRight != targetTotal)
        return 0;

    return 1;
}

void make3x3Square(int square[][3]){
    
    int numbersPicked = 0;
    int try = 0;
    int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    while (numbersPicked < 9){
        int pick = rand() % 10; //Pick a number, replace that index with 0. 
        for (int row = 0; row < 3; row++){
            for (int col = 0; col < 3; col++){
                do{
                    pick = rand() % 10;
                    try++;
                }   while (numbers[pick] == 0); //If 0 (number already picked), then try again

                square[row][col] = pick;
                numbers[pick] = 0;
                numbersPicked++;
            }
        }
        
    }
    return;
}


int main(){
                    //   0  1  2
    int testSquare[3][3] = {{4, 9, 2}, //0
                            {3, 5, 7}, //1
                            {8, 1, 6}};//2
                        //0,0 + 0,1 + 0,2  Horizontal
                        //1,0 + 1,1 + 1,2
                        //2,0 + 2,1 + 2,2

                        //0,0 + 1,0 + 2,0  Vertical
                        //0,1 + 1,1 + 2,1
                        //0,2 + 1,2 + 2,2

                        //0,0 + 1,1 + 2,2  Diag \
                        //2,0 + 1,1 + 0,2  Diag /
    int attempts = 0;
    srand(time(NULL));
    int result = 0;     //0 is not found, 1 is found

    int newSquare[3][3];
    do {
        make3x3Square(newSquare);
        result = isLoShuSquare(newSquare);
        attempts++;
    } while (result == 0);

    for (int row = 0; row < 3; row++){
        printf("[%i %i %i]\n", newSquare[row][0], newSquare[row][1], newSquare[row][2]);
    }
    printf("Square found after %i attempts!\n", attempts);
    return 0;
}