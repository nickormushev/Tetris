#include "Api/Api.h"
#include <stdlib.h>


using namespace::Turtle;
using namespace::Time;
using namespace::Input;

void for1(int fig_mas[][4],int ekran [][20],int& x, int& y)
{
    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) 
    {
            ekran[i+4][j+16] = fig_mas[i][j];
            x = 4;
            y = 16;
    }
}
void move1(int ekran[][20],int keyCode)
{


};
bool move_possible(int ekran[][20],int keyCode,int& x,int& y, char type)
{
if(keyCode==0x28){


return false;
} else if(keyCode==0x25){
    return false;


} else if(keyCode==0x27){
    return false;


  } else return true;
}

class Figure
{
public:
    int a[4][4];
    int x,y;
    char type;
    void getL(int ekran[][20])
    {
        if(rand()%2==0)
        {
            int fig_mas[4][4]=
            {
                {0,1,0,0},
                {0,1,1,1},
                {0,0,0,0},
                {0,0,0,0}
            };
            for1(fig_mas,ekran,x,y);
            type='j';
        }
        else
        {
            int fig_mas[4][4]=
            {
                {0,0,0,2},
                {0,2,2,2},
                {0,0,0,0},
                {0,0,0,0}
            };
            for1(fig_mas,ekran,x,y);
            type='l';
        }

    };
    void getS(int ekran[][20])
    {

        if(rand()%2==0)
        {

            int fig_mas[4][4]=
            {
                {0,3,3,0},
                {0,0,3,3},
                {0,0,0,0},
                {0,0,0,0}
            };
            for1(fig_mas,ekran,x,y);
            type='z';
        }
        else
        {
            int fig_mas[4][4]=
            {
                {0,0,4,4},
                {0,4,4,0},
                {0,0,0,0},
                {0,0,0,0}
            };
           for1(fig_mas,ekran,x,y);
            type='s';
        }


    };
    void getI(int ekran[][20])
    {
        int fig_mas[4][4]=
        {
            {5,5,5,5},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };
      for1(fig_mas,ekran,x,y);
        type='i';
    };
    void getT(int ekran[][20])
    {
        int fig_mas[4][4]=
        {
            {0,0,0,6},
            {0,0,6,6},
            {0,0,0,6},
            {0,0,0,0}
        };
       for1(fig_mas,ekran,x,y);
        type='t';
    };
    void getRect(int ekran[][20])
    {
        int fig_mas[4][4]=
        {
            {0,0,7,7},
            {0,0,7,7},
            {0,0,0,0},
            {0,0,0,0}
        };
        for1(fig_mas,ekran,x,y);
        type='r';
    };

};

int main()
{
    InitTurtle();
    HideTurtle();
    SetOceanDisplayCenter(100, -200);
    SuspendPresentation();
    srand((int)(GetStableTime() % 100000000L));
    Figure fig;
    int ekran[10][20];
for(int i = 0; i < 10; i++)for(int j = 0; j < 20; j++)
            ekran[i][j] = 0;
    while (true)
    {
        int keyCode=0;
        keyCode = ConsumeKeyDown();
            Clear();
            SetPenColor(0x000000);
            DrawRectangle(25, 25, 200, 400);
            if (move_possible(ekran,keyCode,fig.x,fig.y,fig.type)==true)move1(ekran,keyCode);
            else{
            switch(rand()%6)
            {
            case 0:
                fig.getL(ekran);
                break;
            case 1:
                fig.getS(ekran);
                break;
            case 2:
                fig.getRect(ekran);
                break;
            case 3:
                fig.getI(ekran);
                break;
            case 4:
                fig.getT(ekran);
                break;
            case 5:
                fig.getRect(ekran);
                break;
            default:
                break;
            }}
            for(int i = 0; i < 10; i++)for(int j = 0; j < 20; j++)
                {
                    switch(ekran[i][j])
                    {
                    case 1:
                        SetPenColor(0x0000CC);
                        break;
                    case 2:
                        SetPenColor(0xFF9933);
                        break;
                    case 3:
                        SetPenColor(0xFF3333);
                        break;
                    case 4:
                        SetPenColor(0x00FF00);
                        break;
                    case 5:
                        SetPenColor(0x33FFFF);
                        break;
                    case 6:
                        SetPenColor(0x990099);
                        break;
                    case 7:
                        SetPenColor(0xFFFF33);
                        break;
                    default:
                        SetPenColor(0xFFFFFF);
                    }
                    FillRectangle(25 + i * 20, 25 + j * 20, 20, 20);
                }


            Present();
        }
    }

