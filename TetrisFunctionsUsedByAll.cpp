#include <ncurses.h>

#include "functionHeader.hpp"

int xCoordAdjust(int xOffset, int yOffset, int xWidth, int fig_mas[][5], int board[HEIGHT][WIDTH], int x, int flag = true) {

        for(int i = 1; i < 5 + yOffset; i++) {
            for(int j = 0; j < 5 + xOffset; j++) {
                if(board[i][j + x] != 0 && fig_mas[i - 1 - yOffset][j - xOffset] != 0) {
                    
                    if(x + xWidth >= WIDTH) {
                        flag = false;
                        x = startX;
                    }

                    if(flag) x = xCoordAdjust(xOffset, yOffset, xWidth, fig_mas, board, ++x, true); 
                    
                    if(!flag) x = xCoordAdjust(xOffset, yOffset, xWidth, fig_mas, board, --x, false);
                    
                    if(x < 0) {
                        return -1;
                    }
                }
            }
        }

    return x;
}

void ArraySwap(int array[][5], int fig_mas[][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            array[i][j] = fig_mas[i][j];          
        }
    }
}

void InitPiece(int xOffset, int yOffset, int xWidth,int fig_mas[][5], int board[HEIGHT][WIDTH], int& x, int& y, int array[][5]){

    x = startX;
    y = startY;
    
    x = xCoordAdjust(xOffset, yOffset, xWidth, fig_mas, board, x);
    
    if(x<0) {
        board[0][0] = 1;
        return;
    }

    for(int i = 0; i < 5 + yOffset; i++) {
        for(int j = 0; j < 5 + xOffset; j++) {
            if(board[i+y][j+x] == 0 && fig_mas[i - yOffset][j - xOffset]) {
                board[i+y][j+x] = fig_mas[i - yOffset][j - xOffset];
            }           
        }
    }

    ArraySwap(array, fig_mas);
}


void DisplayBoard(int board[HEIGHT][WIDTH], int score) {
    
    printw("\n");
    for(int i = 1; i < HEIGHT; i++) {
        
        printw("#");
        for(int j = 0; j < WIDTH; j++) {
            if(board[i][j]!=0) { 
                attron(COLOR_PAIR(1));
                printw("%d", board[i][j]); 
            }
            else printw(" ");
            attron(COLOR_PAIR(2));
        }
        printw("#");
        printw("\n");
    }
    for(int i = 0; i < WIDTH/2; i++) {
        printw("# ");
    }
    printw("##");
    printw("\n");
    printw("Score: %d", score);

}   
