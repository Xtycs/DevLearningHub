
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define Row 9
#define Column 9

#define Rows Row + 2
#define Columns Column + 2
#define EASY_COUNT 10

void InitBoard(char arr[Rows][Columns], int rows, int cols, char input);

void DisplayBoard(char arr[Rows][Columns], int row, int col);

void SetMine(char arr[Rows][Columns], int row, int col);

void FindMine(char mine[Rows][Columns], char show[Rows][Columns], int row, int col);

