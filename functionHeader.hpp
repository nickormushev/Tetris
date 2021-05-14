const int WIDTH = 20, HEIGHT = 15, startX = 5, startY = 1;

int xCoordAdjust(int xOffset, int yOffset, int xWidth, int fig_mas[][5], int board[HEIGHT][WIDTH], int x, int flag = true);

void ArraySwap(int array[][5], int fig_mas[][5]);

void InitPiece(int xOffset, int yOffset, int xWidth,int fig_mas[][5], int board[HEIGHT][WIDTH], int& x, int& y, int array[][5]);

void DisplayBoard(int board[HEIGHT][WIDTH], int score);   
