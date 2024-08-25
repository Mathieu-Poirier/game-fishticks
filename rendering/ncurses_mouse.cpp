
#include <curses.h>
#include <stdio.h>
#include <iostream>
 
int main()
{
  initscr();
  cbreak();
  noecho();
  mouseinterval(0);

  // Enables keypad mode. This makes (at least for me) mouse events getting
  // reported as KEY_MOUSE, instead as of random letters.
  keypad(stdscr, TRUE);

  // Don't mask any mouse events
  mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

  printf("\033[?1003h\n"); // Makes the terminal report mouse movement events

  for (;;) { 
    int c = wgetch(stdscr);
 
    // Exit the program on new line fed
    if (c == '\n')
      break;
 
    char buffer[512];
    size_t max_size = sizeof(buffer);
    if (c == ERR) {
      snprintf(buffer, max_size, "Nothing happened.");
      refresh();
    }
    else if (c == KEY_MOUSE) {
      MEVENT event;
      if (getmouse(&event) == OK) {

        snprintf(buffer, max_size, "Mouse at row=%d, column=%d bstate=0x%x",
                 event.y, event.x, event.bstate);
        if(event.bstate == 0x4){
            snprintf(buffer, max_size, "Click");
        }
        refresh();
      }
      else {
        snprintf(buffer, max_size, "Got bad mouse event.");
        refresh();
      }

    }
    else {
      snprintf(buffer, max_size, "Pressed key %d (%s)", c, keyname(c));      
    }
 
    move(0, 0);
    insertln();
    addstr(buffer);
    clrtoeol();
    move(0, 0);
  }
 
  printf("\033[?1003l\n"); // Disable mouse movement events, as l = low

  endwin();
 
  return 0;
}