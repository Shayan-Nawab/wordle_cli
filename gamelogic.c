#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "display.h"

bool hardMode = false;
bool gameFinished = false;
char solution[] = "SLIDE";
int writePos = 0;
int activeRow = 0;
char activeRowText[] = "_____";


void winGame(){
  printf("You won!\n"); gameFinished = true;
}


void loseGame(){
  printf("You Lost!\n"); gameFinished = true;
}


void printColors(){

  char solution2[sizeof solution];
  strcpy(solution2, solution);

  int colors[5] = {0};
  for (int i = 0; i < 5; i++){ //mark all chars in the right spot
    if ( activeRowText[i] == solution2[i] ) { colors[i] = 2; solution2[i] = '?';}
  }

  for (int i = 0; i < 5; i++){
    if ( colors[i] == 2 ) { continue; }
    for (int j = 0; j < 5; j++){
      if (activeRowText[i] == solution2[j]){
        colors[i] = 1;
        solution2[j] = '?';
        break;
      }
    }
  }

  char *coloredLetters[5];
  for (int i = 0; i < 5; i++){
    switch (colors[i]){
      case 2:
        coloredLetters[i] = "\033[1;32m"; break;
      case 1:
        coloredLetters[i] = "\033[1;33m"; break;
      default:
        coloredLetters[i] = "\033[1:37m";
    }
  }

  editRowWithColors(5+2*activeRow, activeRowText, coloredLetters);
}


void submitRow(char *activeRowText){
  printColors();
  int didWordWin = strcmp(activeRowText, solution);
  if (didWordWin == 0) { winGame();}
  else if (activeRow == 5) { loseGame(); }
  else {
    activeRow++;
    writePos = 0;
    memset(activeRowText, '_', 5);
  }
}
