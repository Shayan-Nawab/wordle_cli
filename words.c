#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "gamelogic.h"

const char *words[] = {
  #include "wordlist.inc"
};

#define WORDS_LEN (sizeof words / sizeof words[0])

static int cmp(const void *a, const void *b){
  return strcmp(*(const char**)a, *(const char **)b);
}

bool isWord(const char *word){
  return bsearch(&word, words, WORDS_LEN, sizeof words[0], cmp) != NULL;
}

void genWord(bool isRandom) {
  char word[5];
  time_t raw_time = time(NULL);
  if (isRandom) {
    srand(raw_time);
    const char *random_word = *(words + rand() % WORDS_LEN);
    strcpy(word, random_word);
  }
  else {
    time_t day = raw_time/(60*60*24);
    const char *daily_word = *(words + day % WORDS_LEN);
    strcpy(word, daily_word);
  }
  strcpy(solution, word);
}
