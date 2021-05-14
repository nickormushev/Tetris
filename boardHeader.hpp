#include "figureHeader.hpp"

class BoardClass {

    public:

        int board[HEIGHT][WIDTH], score;
        
        void BoardZeroFill();

        void ReplaceNum(Figure fig, int num);

        int CollisionDetect(Figure fig, char direction);

        void DeleteRow();

        void moveAllElementsDown(int row);

        void moveElementDown(Figure fig);
        
        void moveElementLeft(Figure fig);

        void rotateElement(Figure& fig);

        void moveElementRight(Figure fig);

        bool GameOver();

};