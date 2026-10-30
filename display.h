#ifndef DISPLAY_H
#define DISPLAY_H

void editRow(const int row, const char *string);
void editRowWithColors(const int row, const char *string, char **colors);
void startDisplay();
void restoreScreen();

#endif
