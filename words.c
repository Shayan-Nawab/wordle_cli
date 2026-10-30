#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


static const char *words[3103] = {
  #include "allwords.inc"
};

static int cmp(const void *a, const void *b){
  return strcmp(*(const char**)a, *(const char **)b);
}

bool isWord(const char *word){
  int search_result = bsearch(&word, words, 3103, sizeof words[0], cmp) != NULL;
  return (search_result == 1);
}

