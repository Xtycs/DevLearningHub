
#include "game.h"


void menu()
{
    printf("******************\n");
    printf("******1. play*****\n");
    printf("******0. exit*****\n");
    printf("******************\n");
}

void game()
{
    char mine[Rows][Columns] = {0};
    char show[Rows][Columns] = {0};

    //初始化棋盘
    InitBoard(mine, Rows, Columns, '0');
    InitBoard(show, Rows, Columns, '*');

    //展示棋盘
    //DisplayBoard(mine, Row, Column);
    DisplayBoard(show, Row, Column);

    //设置雷，在9*9棋盘上随机布置10颗雷
    SetMine(mine, Row, Column);

    FindMine(mine, show, Row, Column);
}

void test()
{
    int input = 0;

    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("Please choose: \n");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("Game over, exit\n");
                break;
            default:
                printf("invalid input\n");
        }
    } while (input);
}


int main()
{
    test();
    return 0;
}