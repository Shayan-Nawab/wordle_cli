#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h> //Used to change terminal input state
#include <ctype.h> // for toupper()

#include "gamelogic.h"
#include "words.h"
#include "display.h"

struct termios original_state;

void disableRawMode(){
  tcsetattr(0, TCSAFLUSH, &original_state); //0 means read from stdin
}


void enableRawMode(){
  tcgetattr(0, &original_state);
  atexit(disableRawMode);

  struct termios raw = original_state;
  raw.c_lflag &= ~(ICANON | ECHO); //No line buffering, echo
  raw.c_iflag &= ~(ICRNL); //No newline on enter
  raw.c_cc[VMIN] = 1; //read 1 byte at a time
  raw.c_cc[VTIME] = 0; //no timeout
  
  tcsetattr(0, TCSAFLUSH, &raw);
}


void moveWritePos(int distance){ //only needs to accept 1 or -1
  if ( 
    ((writePos + distance) > 4 ) ||
    ((writePos + distance) < 0 )) { return; }
  writePos = writePos + distance;
}


void writeCharacter(char character){
  if (activeRowText[4] != '_' ) { return; }
  activeRowText[writePos] = character;
  editRow(5 + 2*(activeRow), activeRowText);
  moveWritePos(1);
}


void performBackspace(){
  if (writePos == 4 && activeRowText[writePos] != '_'){
    activeRowText[writePos] = '_';
  }
  else{
    moveWritePos(-1);
    activeRowText[writePos] = '_';
  }
  editRow(5 + 2*(activeRow), activeRowText);
}


void performEnter(){
  if (!(writePos == 4 && activeRowText[writePos] != '_')) { return; }
  else if (isWord(activeRowText)) { submitRow(activeRowText); }
}


void readInput(){
  enableRawMode();
  char input;

  while(!gameFinished){
    int read_successful = read(0, &input, 1);
    if (read_successful != 1) { perror("debug: unsuccessful read\n"); exit(1); }
    else if (input == 127 || input == '\b') { performBackspace(); }
    else if (input == '\r') { performEnter(); }
    else if ( (input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z') ){
      writeCharacter(toupper(input));
    }
  }
}


