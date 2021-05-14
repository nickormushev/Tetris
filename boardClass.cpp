#include "boardHeader.hpp"

        
void BoardClass::BoardZeroFill(){
    
    score = 0;
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = 0;
        }
    }
}

void BoardClass::ReplaceNum(Figure fig, int num) {
    for(int i = 0; i < 5 + fig.yOffset; i++) {                
        for(int j = 0; j < 5 + fig.xOffset; j++) {
            if(fig.array[i - fig.yOffset][j - fig.xOffset] != 0 && board[fig.y + i][fig.x + j] != 0) {   
                board[i + fig.y][j + fig.x] = num;
            }
        }
    }
}

int BoardClass::CollisionDetect(Figure fig, char direction) {
    
    if(fig.y + fig.heigth > HEIGHT) return 0; // cant move no more = 0
    if(fig.x + fig.width > WIDTH) return -1; // try again
    if(fig.x < 0) return -1;

    for(int i = 0; i < 5 + fig.yOffset; i++) {                
        for(int j = 0; j < 5 + fig.xOffset; j++) 
        {
            if(fig.array[i - fig.yOffset][j - fig.xOffset] != 0 && board[i + fig.y][j + fig.x] != 0 && board[i + fig.y][j + fig.x] != 10) {            
                return direction == 's' ? 0 : -1;
            }
        }
    }
    return 1; // No collisions
}

void BoardClass::DeleteRow() {

int counter;
    
    for(int i = 0; i < HEIGHT; i++) {
        
        counter = 0;

        for(int j = 0; j < WIDTH; j++) {
            if(board[i][j]!=0) counter++;
        }

        if(counter == WIDTH) {
            score += 100;
            BoardClass::moveAllElementsDown(i);
        }
    }

}

void BoardClass::moveAllElementsDown(int row) {

    for(int i = row; i > 0; i--) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = board[i-1][j];
        }
    }
}

void BoardClass::moveElementDown(Figure fig) {
    for(int i = fig.y - 1 + fig.heigth; i >= fig.y - 1; i--) {
        for(int j = fig.x; j < fig.x + 4; j++){
            if((board[i][j] == 0 && board[i-1][j] == 10)  || board[i][j] == 10) {
                board[i][j] = board[i-1][j];
                if(board[i-1][j] != 0 && board[i-1][j] != 10) board[i][j] = 0;
            } 
        }
    } 
}

void BoardClass::moveElementLeft(Figure fig) {
    
        for(int j = fig.x; j < fig.x + fig.width; j++){            
            for(int i = fig.y; i < fig.y + fig.heigth; i++) {
                if(board[i][j] == 0 && board[i][j + 1] == 10) {
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = 0;
            } 
        }
    } 
}

void BoardClass::rotateElement(Figure& fig) {
    
    // seven is for square
    int backupArray[5][5];
    ArraySwap(backupArray, fig.array);

    fig.figureRotate();

    if(CollisionDetect(fig, 'w') == 1) {
        
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++){
                if(board[i + fig.y][j + fig.x] == 10) { 
                    board[i + fig.y][j + fig.x] = 0;
                }
            }
        }
        for(int i = 0; i < 5 + fig.yOffset; i++) {
            for(int j = 0; j < 5 + fig.xOffset; j++) {
                if(board[i + fig.y][j + fig.x] == 0 || board[i + fig.y][j + fig.x] == 10) {
                    board[i + fig.y][j + fig.x] = fig.array[i - fig.yOffset][j - fig.xOffset];
                }           
            }
        } 
    } else {
        ArraySwap(fig.array, backupArray);
    } ;

}

void BoardClass::moveElementRight(Figure fig) {
        for(int j = fig.x + fig.width - 1; j >= fig.x; j--){            
            for(int i = fig.y; i < fig.y + fig.heigth; i++) {
                if(board[i][j] == 0 && board[i][j-1] == 10) {
                board[i][j] = board[i][j-1];
                board[i][j-1] = 0;
            } 
        }
    } 
}

bool BoardClass::GameOver() {

    for(int i = 0; i<WIDTH; i++) {
        if(board[0][i]!=0) {
            return false;
        }
    }

    return true;
}