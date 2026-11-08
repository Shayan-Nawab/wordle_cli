#ifndef WORDS_H
#define WORDS_H
#include <stdbool.h>

extern const char *words[];
bool isWord(const char *word);
void genWord(bool isRandom);

#endif
