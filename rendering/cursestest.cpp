#include <curses.h>
#include <unistd.h>

WINDOW *win1, *win2, *win3;

int main(){

    initscr();
    clear();
    win1 = newwin(24, 80, 0 ,0);
    mvwaddstr(win1, 2, 2, "HELLO");
    wrefresh(win1);
    sleep(1);
    endwin();
}