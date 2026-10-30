#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "input.h"
#include "display.h"

int main(void){
  enableRawMode();
  startDisplay();
  readInput();
  

  restoreScreen();
  exit(0);
}
