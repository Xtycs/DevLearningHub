#include "game.h"



void InitBoard(char arr[Rows][Columns], int rows, int cols, char input)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = input;
        }
    }
}

void DisplayBoard(char arr[Rows][Columns], int row, int col)
{
    printf("----MineSweeper----\n");

    //先打印列号
    for (int m = 0; m <= col; m++)
    {
        printf("%d  ", m);
    }
    printf("\n");

    int num = 1;
    for (int i = 1; i <= row; i++)
    {
        printf("%d ", num);
        num++;

        for (int j = 1; j <= col; j++)
        {
            printf(" %c ", arr[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char arr[Rows][Columns], int row, int col)
{
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (arr[x][y] == '0')
        {
            arr[x][y] = '1';
            count--;
        }
    }
}

static int MineNum(char arr[Rows][Columns], int x, int y)
{
    return arr[x + 1][y - 1] + 
    arr[x + 1][y] + 
    arr[x + 1][y + 1] + 
    arr[x][y - 1] + 
    arr[x][y + 1] + 
    arr[x + 1][y - 1] + 
    arr[x + 1][y] + 
    arr[x + 1][y + 1] - 8 * '0';
}


void FindMine(char mine[Rows][Columns], char show[Rows][Columns], int row, int col)
{
    int x = 0;
    int y = 0;
    int remain = 0;
    while (remain < row * col - EASY_COUNT)
    {
        printf("Please input the position x and y:");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '*')
            {
                if (mine[x][y] == '1')
                {
                    printf("BOOOOON!!! Game Over");
                    DisplayBoard(mine, row, col);
                    break;
                }
                else
                {
                    int mine_num = MineNum(mine, row, col);
                    show[x][y] = mine_num + '0';
                    DisplayBoard(show, row, col);
                    remain++;
                }
            }
            else
            {
                printf("This position is already selected\n");
            }
        }
        else
        {
            printf("invalid position, please input again\n");
        }
    }

    if(remain == row * col - EASY_COUNT)
    {
        printf("Congratulation, you have won the game\n");
        DisplayBoard(mine, row, col);
    }
}

// static int MineNum(char arr[Rows][Columns], int x, int y)
// {
//     int mineCount = 0;
//     for (int dx = -1; dx <= 1; dx++) {
//         for (int dy = -1; dy <= 1; dy++) {
//             // Skip the center cell, if count there is nothing happend since center is '0'
//             if (dx == 0 && dy == 0) continue;
//             mineCount += arr[x + dx][y + dy] - '0';
//         }
//     }
//     return mineCount;
// }