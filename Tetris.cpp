#include <iostream>
#include <unistd.h>

using namespace std;

const int WIDTH = 20, HEIGHT = 10, startX = 5, startY = 1;


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

void ArraySwap(int a[][5], int fig_mas[][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            a[i][j] = fig_mas[i][j];          
        }
    }
}

void InitPiece(int xOffset, int yOffset, int xWidth,int fig_mas[][5], int board[HEIGHT][WIDTH], int& x, int& y, int a[][5]){

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

    ArraySwap(a, fig_mas);
}

void DisplayBoard(int board[HEIGHT][WIDTH]) {
    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl; 
    cout<<endl;
    cout<<endl;
    cout<<endl;

    for(int i = 1; i < HEIGHT; i++) {
        
        cout<<"#";
        for(int j = 0; j < WIDTH; j++) {
            if(board[i][j]!=0)cout<<board[i][j];
            else cout<<" ";
        }
        cout<<"#";
        cout<<endl;
    }
    for(int i = 0; i < WIDTH/2; i++) {
        cout<<"# ";
    }
    cout<<"##";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
}   

class Figure
{
public:
    
    int a[5][5];
    int x,y,width,heigth,xOffset,yOffset,num;
    char rotation;

    void getL(int board[][WIDTH])
    {
        if(rand()%2==0)
        {
            int fig_mas[5][5]=
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,0,1,0,0},
                {0,1,1,0,0},
                {0,0,0,0,0}
            };

            yOffset = -1;
            xOffset = -1;
            width = 2;
            heigth = 3;
            num = 1;
            rotation = 'l';
            InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,a);
        }
        else
        {
            int fig_mas[5][5]=
            {
                {0,0,0,0,0},
                {0,0,2,0,0},
                {0,0,2,0,0},
                {0,0,2,2,0},
                {0,0,0,0,0}
            };
            

            xOffset = -2;
            yOffset = -1;
            width = 2;
            num = 2;            
            heigth = 3;
            rotation = 'r';
            InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,a);            
        }

    };
    void getS(int board[][WIDTH])
    {

        if(rand()%2==0)
        {

            int fig_mas[5][5]=
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,3,3,0,0},
                {0,0,3,3,0},
                {0,0,0,0,0}
            };
            
            xOffset = -1;
            yOffset = -2;
            width = 3;
            num = 3;
            heigth = 2;
            rotation = 'l';
            InitPiece(xOffset, yOffset, width, fig_mas,board,x,y,a);
        }
        else
        {
            int fig_mas[5][5]=
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,0,4,4,0},
                {0,4,4,0,0},
                {0,0,0,0,0}
            };
            
            yOffset = -2;
            xOffset = -1;
            width = 3;            
            num = 4;
            heigth = 2;
            rotation = 'r';            
            InitPiece(xOffset, yOffset, width, fig_mas,board,x,y,a);
       }


    };
    void getI(int board[][WIDTH])
    {
        int fig_mas[5][5]=
        {
            {0,0,5,0,0},
            {0,0,5,0,0},
            {0,0,5,0,0},
            {0,0,5,0,0},
            {0,0,0,0,0}
        };

        yOffset = 0;
        xOffset = -2;
        width = 1;
        num = 5;
        heigth = 4;
        rotation='u';
        InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,a);
        
    };

    void getT(int board[][WIDTH])
    {
        int fig_mas[5][5]=
        {
            {0,0,0,0,0},
            {0,0,6,0,0},
            {0,6,6,0,0},
            {0,0,6,0,0},
            {0,0,0,0,0}
        };

        xOffset = -1;
        yOffset = -1;
        width = 2;
        num = 6;
        heigth = 3;
        rotation = 'l';
        InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,a);
    };
    
    void getRect(int board[][WIDTH])
    {
        int fig_mas[5][5]=
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,7,7,0},
            {0,0,7,7,0},
            {0,0,0,0,0}

        };
        
        xOffset = -2;
        yOffset = -2;
        width = 2;
        num = 7;        
        heigth = 2;
        InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,a);
    };

    void figureRotate() {
        
        if(num == 6) {
            switch(rotation) {
                case 'l':
                {
                    int fig_mas[5][5] = 
                    { 
                        {0,0,0,0,0},
                        {0,0,6,0,0},
                        {0,6,6,6,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'u';
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -1;
                    width = 3;
                    break;
                }

                case 'u':
                {    
                    int fig_mas[5][5] = 
                    { 
                        {0,0,0,0,0},
                        {0,0,6,0,0},
                        {0,0,6,6,0},
                        {0,0,6,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'r';
                    heigth = 3;
                    xOffset = -2;
                    yOffset = -1;
                    width = 2;

                    break;
                }

                case 'r':
                {
                    int fig_mas[5][5] = 
                    { 
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,6,6,6,0},
                        {0,0,6,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -2;
                    width = 3;
                    rotation = 'd'; 
                    break;
                }
                
                case 'd':
                {                    
                    int fig_mas[5][5] = 
                    { 
                        {0,0,0,0,0},
                        {0,0,6,0,0},
                        {0,6,6,0,0},
                        {0,0,6,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);

                    rotation = 'l';
                    heigth = 3;
                    xOffset = -1;
                    yOffset = -1;
                    width = 2;
                    break;
                }

                default:
                    break;  
            }


        } else if(num == 5) {
            switch(rotation) {
                case 'l':
                {
                    int fig_mas[5][5]=
                    {
                        {0,0,5,0,0},
                        {0,0,5,0,0},
                        {0,0,5,0,0},
                        {0,0,5,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);

                    rotation = 'u';
                    heigth = 4;
                    xOffset = -2;
                    yOffset = 0;
                    width = 1;
                    break;
                }

                case 'u':
                {                    
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,5,5,5,5},
                        {0,0,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);

                    rotation = 'r';
                    heigth = 1;
                    xOffset = -1;
                    yOffset = -2;
                    width = 4;
                    break;
                }

                case 'r':
                {
                    int fig_mas[5][5] = 
                        { 
                            {0,0,0,0,0},
                            {0,0,5,0,0},
                            {0,0,5,0,0},
                            {0,0,5,0,0},
                            {0,0,5,0,0}
                        };

                    ArraySwap(a, fig_mas);

                    rotation = 'd'; 
                    heigth = 4;
                    xOffset = -2;
                    yOffset = -1;
                    width = 1;
                    break;
                }
                
                case 'd':
                {    
                    int fig_mas[5][5] = 
                    { 
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {5,5,5,5,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'l';
                    heigth = 1;
                    xOffset = 0;
                    yOffset = -2;
                    width = 4;
                    break;
                }

                default:
                    break;  
            }
        } else if(num == 4) {
            switch(rotation) {
                case 'l':
                {
                    int fig_mas[5][5]=
                    {
                        
                        {0,0,0,0,0},
                        {0,4,0,0,0},
                        {0,4,4,0,0},
                        {0,0,4,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    rotation = 'u';
                    heigth = 3;
                    xOffset = -1;
                    yOffset = -1;
                    width = 2;
                    break;
                }

                case 'u':
                {                    
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,4,4,0},
                        {0,4,4,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);

                    rotation = 'r';
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -1;
                    width = 3;
                    break;
                }

                case 'r':
                {
                    int fig_mas[5][5]=
                    {                        
                        {0,0,0,0,0},
                        {0,0,4,0,0},
                        {0,0,4,4,0},
                        {0,0,0,4,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'd'; 
                    heigth = 3;
                    xOffset = -2;
                    yOffset = -1;
                    width = 2;
                    break;
                }
                
                case 'd':
                {                    
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,4,4,0},
                        {0,4,4,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'l';
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -1;
                    width = 3;
                    break;
                }

                default:
                    break;  
            }
        } else if(num == 3) {
            switch(rotation) {
                case 'l':
                {
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,3,0,0},
                        {0,3,3,0,0},
                        {0,3,0,0,0},
                        {0,0,0,0,0}                    
                    };

                    ArraySwap(a, fig_mas);
                    rotation = 'u';
                    heigth = 3;
                    xOffset = -1;
                    yOffset = -1;
                    width = 2;
                    break;
                }

                case 'u':
                {                    
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,3,3,0,0},
                        {0,0,3,3,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);

                    rotation = 'r';
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -1;
                    width = 3;
                    break;
                }

                case 'r':
                {
                    int fig_mas[5][5]=
                    {                        
                        {0,0,0,0,0},
                        {0,0,0,3,0},
                        {0,0,3,3,0},
                        {0,0,3,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'd'; 
                    heigth = 3;
                    xOffset = -2;
                    yOffset = -1;
                    width = 2;
                    break;
                }
                
                case 'd':
                {                    
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,3,3,0,0},
                        {0,0,3,3,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'l';
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -2;
                    width = 3;
                    break;
                }

                default:
                    break;  
            }
        } else if(num == 2) {
            switch(rotation) {
                case 'l':
                {
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,2,0,0},
                        {0,0,2,0,0},
                        {0,0,2,2,0},
                        {0,0,0,0,0}
                    };
 

                    ArraySwap(a, fig_mas);
                    rotation = 'u';
                    heigth = 3;
                    xOffset = -2;
                    yOffset = -1;
                    width = 2;
                    break;
                }

                case 'u':
                {                    
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,2,2,2,0},
                        {0,2,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);

                    rotation = 'r';
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -2;
                    width = 3;
                    break;
                }

                case 'r':
                {
                    int fig_mas[5][5]=
                    {                        
                        {0,0,0,0,0},
                        {0,2,2,0,0},
                        {0,0,2,0,0},
                        {0,0,2,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'd'; 
                    heigth = 3;
                    xOffset = -1;
                    yOffset = -1;
                    width = 2;
                    break;
                }
                
                case 'd':
                {    
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,0,2,0},
                        {0,2,2,2,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'l';
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -1;
                    width = 3;
                    break;
                }

                default:
                    break;  
            }
        } else if(num == 1) {
            switch(rotation) {
                case 'l':
                {
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,0,1,0,0},
                        {0,0,1,0,0},
                        {0,1,1,0,0},
                        {0,0,0,0,0}
                    };
 

                    ArraySwap(a, fig_mas);
                    rotation = 'u';
                    heigth = 3;
                    xOffset = -1;
                    yOffset = -1;
                    width = 2;
                    break;
                }

                case 'u':
                {    
                    int fig_mas[5][5]=
                    {
                        {0,0,0,0,0},
                        {0,1,0,0,0},
                        {0,1,1,1,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);

                    rotation = 'r';
                    heigth = 2;
                    xOffset = -1;
                    yOffset = -1;
                    width = 3;
                    break;
                }

                case 'r':
                {
                    int fig_mas[5][5]=
                    {                        
                        {0,0,0,0,0},
                        {0,0,1,1,0},
                        {0,0,1,0,0},
                        {0,0,1,0,0},
                        {0,0,0,0,0}
                    };

                    ArraySwap(a, fig_mas);
                    
                    rotation = 'd'; 
                    heigth = 3;
                    xOffset = -2;
                    yOffset = -1;
                    width = 2;
                    break;
                }
                case 'd':
                    {
                        int fig_mas[5][5]=
                        {
                            {0,0,0,0,0},
                            {0,0,0,0,0},
                            {0,1,1,1,0},
                            {0,0,0,1,0},
                            {0,0,0,0,0}
                        };

                        ArraySwap(a, fig_mas);
                        
                        rotation = 'l';
                        heigth = 2;
                        xOffset = -1;
                        yOffset = -2;
                        width = 3;
                        break;
                    }

                default:
                    break;  
            }
        }
    }

};

class BoardClass {

    public:

        int board[HEIGHT][WIDTH];
        
        void BoardZeroFill(){

            for(int i = 0; i < HEIGHT; i++) {
                for(int j = 0; j < WIDTH; j++) {
                    board[i][j] = 0;
                }
            }
        }

        void ReplaceNum(Figure fig, int num) {
            for(int i = 0; i < 5 + fig.yOffset; i++) {                
                for(int j = 0; j < 5 + fig.xOffset; j++) {
                    if(fig.a[i - fig.yOffset][j - fig.xOffset] != 0 && board[fig.y + i][fig.x + j] != 0) {   
                        board[i + fig.y][j + fig.x] = num;
                    }
                }
            }
        }

        int CollisionDetect(Figure fig, char direction) {
            
            if(fig.y + fig.heigth > HEIGHT) return 0; // cant move no more = 0
            if(fig.x + fig.width > WIDTH) return -1; // try again
            if(fig.x < 0) return -1;

            for(int i = 0; i < 5 + fig.yOffset; i++) {                
                for(int j = 0; j < 5 + fig.xOffset; j++) 
                {
                    if(fig.a[i - fig.yOffset][j - fig.xOffset] != 0 && board[i + fig.y][j + fig.x] != 0 && board[i + fig.y][j + fig.x] != 10) {            
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
                }
            }

        }

        void moveAllElementsDown(int row) {

            for(int i = row; i>0; i--) {
                for(int j = 0; j<WIDTH; j++) {
                    board[i][j] = board[i-1][j];
                }
            }
        }

        void moveElementDown(Figure fig) {
            for(int i = fig.y - 1 + fig.heigth; i >= fig.y - 1; i--) {
                for(int j = fig.x; j < fig.x + fig.width; j++){
                    if((board[i][j] == 0 && board[i-1][j] == 10)  || board[i][j] == 10) {
                        board[i][j] = board[i-1][j];
                        if(board[i-1][j] != 0 && board[i-1][j] != 10) board[i][j] = 0;
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

        void rotateElement(Figure& fig) {
            
            if(fig.num == 7) return; // seven is for square
            int backupArray[5][5];
            ArraySwap(backupArray, fig.a);

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
                            board[i + fig.y][j + fig.x] = fig.a[i - fig.yOffset][j - fig.xOffset];
                        }           
                    }
                } 
            } else {
                ArraySwap(fig.a, backupArray);
            } ;

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

bool PeriodicMove(BoardClass& board, Figure& fig, char direction) {

    board.ReplaceNum(fig, 10);
    
    if(direction == 's') { fig.y++; }
    else if(direction == 'd') { fig.x++; }
    else if(direction == 'a') { fig.x--; }
    else if(direction == 'w') { board.rotateElement(fig); }
    
    int collisionResult = board.CollisionDetect(fig, direction);

    if(collisionResult == 1){
       
       if(direction == 's') {
           board.moveElementDown(fig);
       }
       if(direction == 'd') {
           board.moveElementRight(fig);
       }
       if(direction == 'a') {
           board.moveElementLeft(fig);
       }

    } else {
        
        if(direction == 's') { fig.y--; }
        else if(direction == 'd') { fig.x--; }
        else if(direction == 'a') { fig.x++; }

        board.ReplaceNum(fig, fig.num);
        if(collisionResult == 0) return false;
        else return true;
    }
        board.ReplaceNum(fig, fig.num);
        return true;

}


int main() {

BoardClass boardMain;
Figure fig;

char keyCode;

boardMain.BoardZeroFill();
fig.getI(boardMain.board); // Mahni go towa

DisplayBoard(boardMain.board); // I towa

while(boardMain.GameOver()) {
    
    cin>>keyCode;
    if(PeriodicMove(boardMain, fig, keyCode)) {
    } else {
        boardMain.DeleteRow();
        switch(rand()%6)
        {
        case 0:
            fig.getL(boardMain.board);
            break;
        case 1:
            fig.getS(boardMain.board);
            break;
        case 2:
            fig.getRect(boardMain.board);
            break;
        case 3:
            fig.getI(boardMain.board);
            break;
        case 4:
            fig.getT(boardMain.board);
            break;
        case 5:
            fig.getRect(boardMain.board);
            break;
        default:
            break;
        }
    }

    DisplayBoard(boardMain.board);
}
cout<<"Game over mate"<<endl;

}



// Kakvo ostava: Napishi rotaciqta. Posle proveri dali redowete se triqt che mai ne raboti. Inache si gotow :D