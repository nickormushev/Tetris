#include <iostream>
#include <unistd.h>

using namespace std;

const int WIDTH = 20, HEIGHT = 10, startX=5, startY=1;


int xCoordAdjust(int xWidth, int fig_mas[][4], int board[HEIGHT][WIDTH], int x, int flag = true) {

        for(int i = 1; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(board[i][j+x] != 0 && fig_mas[i-1][j] != 0) {
                    
                    if(flag) x = xCoordAdjust(xWidth, fig_mas, board, ++x, true); 

                    if(x + xWidth >= WIDTH) {
                        flag = false;
                        x = startX;
                    }
                    
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

        int board[HEIGHT][WIDTH];
        
        void BoardZeroFill(){

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

        bool CollisionDetect(Figure fig) {
            
            if(fig.y + fig.heigth > HEIGHT) return false;
            for(int i = 0; i < 4; i++) {                
                for(int j = 0; j < 4; j++) 
                {
                    if(fig.a[i][j] != 0 && board[i + fig.y][j + fig.x] != 0 && board[i + fig.y][j + fig.x] != 10) {            
                        return false;
                    }
                }
            }
            return true;
        }

        void DeleteRow() {

        int counter;
            
            for(int i = 0; i < HEIGHT; i++) {
                counter = 0;
                
                for(int j = 0; j < WIDTH; j++) {
                    if(board[i][j]!=0) counter++;
                }

                if(counter == WIDTH - 1) {
                    moveElementsDown(i);
                }
            }

        }

        void moveElementsDown(int row) {

            for(int i = row; i>=0; i--) {
                for(int j = 0; j<WIDTH; j++) {
                    board[i][j] = board[i-1][j];
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

bool PeriodicMove(BoardClass& board, Figure& fig) {

    board.ReplaceNum(fig, 10);

    fig.y++;
    if(board.CollisionDetect(fig)){
        for(int i = fig.y - 1 + fig.heigth; i >= fig.y - 1; i--) {
            for(int j = fig.x; j < fig.x + 4; j++){
                if((board.board[i][j] == 0 && board.board[i-1][j] == 10)  || board.board[i][j] == 10) {
                    board.board[i][j] = board.board[i-1][j];
                }
            }
        } 
    } else {
        fig.y--;
        board.ReplaceNum(fig, fig.num);
        return false;
    }
        board.ReplaceNum(fig, fig.num);
        return true;

}
 

int main() {

BoardClass boardMain;
Figure fig;

int keyCode;

boardMain.BoardZeroFill();
fig.getI(boardMain.board);

while(boardMain.GameOver()) {
    
    keyCode = 0;
    
    DisplayBoard(boardMain.board);
    if(PeriodicMove(boardMain, fig)) {
      
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

    usleep(300000);
}
}