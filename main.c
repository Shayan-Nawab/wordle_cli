#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#include "input.h"
#include "display.h"
#include "gamelogic.h"
#include "words.h"

void printHelpMessage(){
  printf("Usage: wordle [COMMAND] [FLAGS] \n \nCommands:\n");
  printf("%-15s %-15s\n", "help", "Print this message");
  printf("%-15s %-15s\n", "show-stats", "Print user stats");
  printf("%-15s %-15s\n", "reset-stats", "Reset user stats");
  printf("\nFlags:\n");
  printf("%-15s %-15s\n", "--random", "Play with random solution rather than daily solution");
  printf("%-15s %-15s\n", "--hard-mode", "Enable hard mode (guesses can't ignore any given letter clues)");
}

//move to userstats.c
void printUserStats(){ printf("user stats filler\n"); }
void resetUserStats(){ printf("reset stats filler\n"); }

void playGame(bool isRandom){
  genWord(isRandom);
  enableRawMode();
  startDisplay();
  readInput();
  
  restoreScreen();
};

void parseInput(const int args, char **argsList){
  for (int i = 1; i < args; i++){
    if (strcmp(argsList[i], "help") == 0) { printHelpMessage(); exit(0); }
    else if (strcmp(argsList[i], "show-stats") == 0) { printUserStats(); exit(0); }
    else if (strcmp(argsList[i], "reset-stats") == 0) { resetUserStats(); exit(0); }
    else if (strcmp(argsList[i], "--hard-mode") == 0) { hardMode = true; }
    else if (strcmp(argsList[i], "--random") == 0) { playGame(true); }
    else { fprintf(stderr, "wordle_cli: Unknown argument \"%s\" in input. Use \"wordle help\" for usage instructions.\n", argsList[i]); exit(1); }
  }

  playGame(false);
}

int main(int argc, char **argv){
  parseInput(argc, argv);
  exit(0);
}


