#include <ncurses.h>

int main() {

initscr();
int x;
while((x = getch()) != 27) {
printw("%d", x);
refresh();
}

endwin();

}