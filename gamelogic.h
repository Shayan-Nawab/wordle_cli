#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <stdbool.h>

extern bool gameFinished;
extern char solution[];
extern int writePos;
extern int activeRow;
extern char activeRowText[];

void winGame();
void loseGame();
void submitRow(char *activeRowText);

#endif
