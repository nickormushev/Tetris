#include<iostream>

#include "functionHeader.hpp"
#include "figureHeader.hpp"

void Figure::getL(int board[][WIDTH])
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
        InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,array);
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
        InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,array);            
    }

};
void Figure::getS(int board[][WIDTH])
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
        InitPiece(xOffset, yOffset, width, fig_mas,board,x,y,array);
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
        InitPiece(xOffset, yOffset, width, fig_mas,board,x,y,array);
    }


};
void Figure::getI(int board[][WIDTH])
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
    InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,array);
    
};

void Figure::getT(int board[][WIDTH])
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
    InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,array);
};

void Figure::getRect(int board[][WIDTH])
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
    InitPiece(xOffset,yOffset,width, fig_mas,board,x,y,array);
};

void Figure::figureRotate() {
    
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

                ArraySwap(array, fig_mas);
                
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

                ArraySwap(array, fig_mas);
                
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

                ArraySwap(array, fig_mas);
                
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

                ArraySwap(array, fig_mas);

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

                ArraySwap(array, fig_mas);

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

                ArraySwap(array, fig_mas);

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

                ArraySwap(array, fig_mas);

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

                ArraySwap(array, fig_mas);
                
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

                ArraySwap(array, fig_mas);
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

                ArraySwap(array, fig_mas);

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

                ArraySwap(array, fig_mas);
                
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

                ArraySwap(array, fig_mas);
                
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

                ArraySwap(array, fig_mas);
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

                ArraySwap(array, fig_mas);

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

                ArraySwap(array, fig_mas);
                
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

                ArraySwap(array, fig_mas);
                
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


                ArraySwap(array, fig_mas);
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

                ArraySwap(array, fig_mas);

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

                ArraySwap(array, fig_mas);
                
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

                ArraySwap(array, fig_mas);
                
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


                ArraySwap(array, fig_mas);
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

                ArraySwap(array, fig_mas);

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

                ArraySwap(array, fig_mas);
                
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

                    ArraySwap(array, fig_mas);
                    
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
