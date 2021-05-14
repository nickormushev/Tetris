class Figure
{
public:
    
    int array[5][5];
    int x,y,width,heigth,xOffset,yOffset,num;
    char rotation;

    void getL(int board[][WIDTH]);

    void getS(int board[][WIDTH]);

    void getI(int board[][WIDTH]);

    void getT(int board[][WIDTH]);
    
    void getRect(int board[][WIDTH]);

    void figureRotate();
};