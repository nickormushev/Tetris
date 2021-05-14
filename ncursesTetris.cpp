#include <ncurses.h>
#include <unistd.h>
#include <iostream>

using namespace std;

const int WIDTH = 20, HEIGHT = 15, startX = 5, startY = 1;


int xCoordAdjust(int xWidth, int fig_mas[][4], int board[HEIGHT][WIDTH], int x, int flag = true) {

        for(int i = 1; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(board[i][j+x] != 0 && fig_mas[i-1][j] != 0) {
                    
                    if(x + xWidth >= WIDTH) {
                        flag = false;
                        x = startX;
                    }

                    if(flag) x = xCoordAdjust(xWidth, fig_mas, board, ++x, true); 
                    
                    if(!flag) x = xCoordAdjust(xWidth, fig_mas, board, --x, false);
                    
                    if(x < 0) {
                        return -1;
                    }
                }
            }
        }

    return x;
}

void InitPiece(int xWidth,int fig_mas[][4], int board[HEIGHT][WIDTH], int& x, int& y, int a[4][4]){

    x = startX;
    y = startY;
    
    x = xCoordAdjust(xWidth, fig_mas, board, x);
    
    if(x<0) {
        board[0][0] = 1;
        return;
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            a[i][j] = fig_mas[i][j];
            if(board[i+1][j+x] == 0) {
                board[i+1][j+x] = fig_mas[i][j];
            }           
        }
        
    }
    
}


void DisplayBoard(int board[HEIGHT][WIDTH], int score) {
    
    for(int i = 1; i < HEIGHT; i++) {
        
        printw("#");
        for(int j = 0; j < WIDTH; j++) {
            if(board[i][j]!=0) printw("%d", board[i][j]);
            else printw(" ");
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

class Figure
{
public:
    
    int a[4][4];
    int x,y,width,heigth, num;
    char type;

    void getL(int board[][WIDTH])
    {
        if(rand()%2==0)
        {
            int fig_mas[4][4]=
            {
                {1,0,0,0},
                {1,1,1,0},
                {0,0,0,0},
                {0,0,0,0}
            };

            width = 3;
            heigth = 2;
            num = 1;
            type='j';
            InitPiece(width, fig_mas,board,x,y,a);
        }
        else
        {
            int fig_mas[4][4]=
            {
                {0,0,2,0},
                {2,2,2,0},
                {0,0,0,0},
                {0,0,0,0}
            };
            
            width = 3;
            num = 2;            
            heigth = 2;
            type = 'l';
            InitPiece(width, fig_mas,board,x,y,a);            
        }

    };
    void getS(int board[][WIDTH])
    {

        if(rand()%2==0)
        {

            int fig_mas[4][4]=
            {
                {3,3,0,0},
                {0,3,3,0},
                {0,0,0,0},
                {0,0,0,0}
            };
            
            width = 3;
            num = 3;
            heigth = 2;
            type='z';
            InitPiece(width, fig_mas,board,x,y,a);
        }
        else
        {
            int fig_mas[4][4]=
            {
                {0,4,4,0},
                {4,4,0,0},
                {0,0,0,0},
                {0,0,0,0}
            };
            
            width = 3;            
            num = 4;
            heigth = 2;
            type='s';            
            InitPiece(width, fig_mas,board,x,y,a);
       }


    };
    void getI(int board[][WIDTH])
    {
        int fig_mas[4][4]=
        {
            {5,0,0,0},
            {5,0,0,0},
            {5,0,0,0},
            {5,0,0,0}
        };

        width = 1;
        num = 5;
        heigth = 4;
        type='i';
        InitPiece(width, fig_mas,board,x,y,a);
    };

    void getT(int board[][WIDTH])
    {
        int fig_mas[4][4]=
        {
            {0,6,0,0},
            {6,6,0,0},
            {0,6,0,0},
            {0,0,0,0}
        };
         
        width = 2;
        num = 6;
        heigth = 3;
        type='t';
        InitPiece(width,fig_mas,board,x,y,a);
    };
    
    void getRect(int board[][WIDTH])
    {
        int fig_mas[4][4]=
        {
            {7,7,0,0},
            {7,7,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        
        width = 2;
        num = 7;        
        heigth = 2;
        type='r';
        InitPiece(width,fig_mas,board,x,y,a);
    };

};

class BoardClass {

    public:

        int board[HEIGHT][WIDTH], score;

        void BoardZeroFill(){

            score = 0;

            for(int i = 0; i < HEIGHT; i++) {
                for(int j = 0; j < WIDTH; j++) {
                    board[i][j] = 0;
                }
            }
        }

        void ReplaceNum(Figure fig, int num) {
            for(int i = 0; i < 4; i++) {                
                for(int j = 0; j < 4; j++) {
                    if(fig.a[i][j] != 0 && board[fig.y + i][fig.x + j] != 0) {   
                        board[i + fig.y][j + fig.x] = num;
                    }
                }
            }
        }

        int CollisionDetect(Figure fig, char direction) {
            
            if(fig.y + fig.heigth > HEIGHT) return 0; // cant move no more = 0
            if(fig.x + fig.width > WIDTH) return -1; // try again
            if(fig.x < 0) return -1;

            for(int i = 0; i < 4; i++) {                
                for(int j = 0; j < 4; j++) 
                {
                    if(fig.a[i][j] != 0 && board[i + fig.y][j + fig.x] != 0 && board[i + fig.y][j + fig.x] != 10) {            
                        return direction == 's' ? 0 : -1;
                    }
                }
            }
            return 1; // No collisions
        }

        void DeleteRow() {

        int counter;
            
            for(int i = 0; i < HEIGHT; i++) {
                counter = 0;
                
                for(int j = 0; j < WIDTH; j++) {
                    if(board[i][j]!=0) counter++;
                }

                if(counter == WIDTH - 1) {
                    moveAllElementsDown(i);
                    score+=10;
                }
            }

        }

        void moveAllElementsDown(int row) {

            for(int i = row; i > 0; i--) {
                for(int j = 0; j < WIDTH; j++) {
                    board[i][j] = board[i-1][j];
                }
            }
        }

        void moveElementDown(Figure fig) {
            for(int i = fig.y - 1 + fig.heigth; i >= fig.y - 1; i--) {
                for(int j = fig.x; j < fig.x + 4; j++){
                    if((board[i][j] == 0 && board[i-1][j] == 10)  || board[i][j] == 10) {
                        board[i][j] = board[i-1][j];
                    } 
                }
            } 
        }
        
        void moveElementLeft(Figure fig) {
          
                for(int j = fig.x; j < fig.x + fig.width; j++){            
                    for(int i = fig.y; i < fig.y + fig.heigth; i++) {
                        if(board[i][j] == 0 && board[i][j + 1] == 10) {
                        board[i][j] = board[i][j + 1];
                        board[i][j + 1] = 0;
                    } 
                }
            } 
        }


        void moveElementRight(Figure fig) {
                for(int j = fig.x + fig.width - 1; j >= fig.x; j--){            
                    for(int i = fig.y; i < fig.y + fig.heigth; i++) {
                        if(board[i][j] == 0 && board[i][j-1] == 10) {
                        board[i][j] = board[i][j-1];
                        board[i][j-1] = 0;
                    } 
                }
            } 
        }

        bool GameOver() {
        
            for(int i = 0; i<WIDTH; i++) {
                if(board[0][i]!=0) {
                    return false;
                }
            }

            return true;
        }

};

bool PeriodicMove(BoardClass& board, Figure& fig, int direction) {

    board.ReplaceNum(fig, 10);
    
    if(direction == 115) { fig.y++; }      // s = down = 115
    else if(direction == 100) { fig.x++; } // d = right = 100
    else if(direction == 97) { fig.x--; } // a = left = 97
    int collisionResult = board.CollisionDetect(fig, direction);
    

    if(collisionResult == 1){
       
       if(direction == 115) {
           board.moveElementDown(fig);
       }
       if(direction == 100) {
           board.moveElementRight(fig);
       }
       if(direction == 97) {
           board.moveElementLeft(fig);
       }

    } else {
        
        if(direction == 115) { fig.y--; }
        else if(direction == 100) { fig.x--; }
        else if(direction == 97) { fig.x++; }

        board.ReplaceNum(fig, fig.num);
       if(collisionResult == 0) return false;
       else return true;
    }
        board.ReplaceNum(fig, fig.num);
        return true;

}

void RandomElementGeneration(Figure& fig, int board[HEIGHT][WIDTH]) {

    switch(rand()%6)
        {
        case 0:
            fig.getL(board);
            break;
        case 1:
            fig.getS(board);
            break;
        case 2:
            fig.getRect(board);
            break;
        case 3:
            fig.getI(board);
            break;
        case 4:
            fig.getT(board);
            break;
        case 5:
            fig.getRect(board);
            break;
        default:
            break;
        }
}

int main() {

BoardClass boardMain;
Figure fig;

int MoveDownCounter = 0;
bool fasterMoveFlag = false;
char keyCode;

initscr();
nodelay(stdscr, TRUE);

boardMain.BoardZeroFill();

RandomElementGeneration(fig, boardMain.board);

DisplayBoard(boardMain.board, boardMain.score); // I towa

while(boardMain.GameOver()) {
    

    MoveDownCounter++;
    keyCode = getch();
   

    if(keyCode == 115) {
        fasterMoveFlag = true;    
    }

    if(keyCode == -1) { 
        keyCode = 115;
    }

    if(MoveDownCounter == 4 && !PeriodicMove(boardMain, fig, keyCode)){
         keyCode = 115;
         MoveDownCounter = 0;
    }


    if(!PeriodicMove(boardMain, fig, keyCode)) {
        boardMain.DeleteRow();  
        RandomElementGeneration(fig, boardMain.board);
    }

    flushinp();    
    clear();
    DisplayBoard(boardMain.board, boardMain.score);
    refresh();
    if(fasterMoveFlag) {
        fasterMoveFlag = false;
        usleep(150000);
    } else {
        usleep(300000);
    }
}

printw("Game over mate");
refresh();


endwin();

}



// Kakvo ostava: Napishi rotaciqta. Posle proveri dali redowete se triqt che mai ne raboti. Inache si gotow :D
