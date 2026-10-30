#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test_edit(){
  printf("\033[5;1H");
  printf("\033[2K");
  printf("edit");
  fflush(stdout);
}

void restoreScreen() {
    printf("\033[%d;1H\n", 18);   // go below everything you drew
    printf("\033[?25h");          // show the cursor again
    fflush(stdout);
}

//colums: 7, 11, 15, 19, 23
void editRow(const int row, const char *string){
  printf("\033[%d;1H", row);
  printf("\033[2K");
  printf("║     %c   %c   %c   %c   %c     ║", string[0], string[1], string[2], string[3], string[4]);
  fflush(stdout);
}

void editRowWithColors(const int row, const char *string, char **colors){
  char reset[] = "\033[0m";
  printf("\033[%d;1H", row);
  printf("\033[2K");
  printf("║     %s%c%s   %s%c%s   %s%c%s   %s%c%s   %s%c%s     ║",  colors[0], string[0], reset,
                                                                    colors[1], string[1], reset, 
                                                                    colors[2], string[2], reset,
                                                                    colors[3], string[3], reset,
                                                                    colors[4], string[4], reset);
  fflush(stdout);
}

void startDisplay(){
  printf("\033[2J\033[H");
  printf("\033[?25l");
  printf("╔═══════════════════════════╗\n");
  printf("║        W O R D L E        ║\n");
  printf("╚═══════════════════════════╝\n");
  printf("║                           ║\n");
  printf("║     _   _   _   _   _     ║\n");
  printf("║                           ║\n");
  printf("║     _   _   _   _   _     ║\n");
  printf("║                           ║\n");
  printf("║     _   _   _   _   _     ║\n");
  printf("║                           ║\n");
  printf("║     _   _   _   _   _     ║\n");
  printf("║                           ║\n");
  printf("║     _   _   _   _   _     ║\n");
  printf("║                           ║\n");
  printf("║     _   _   _   _   _     ║\n");
  printf("║                           ║\n");
  printf("╚═══════════════════════════╝\n");
  fflush(stdout);
}

