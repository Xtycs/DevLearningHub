# Chapter 7 MineSweeper

## Outline：

### 1. Analyse and Design

### 2. Code

### 3. Expansion
***—————————————————————————————————————————————————————————————————————————***
### 1. Analyse and Design

#### 1.1 Need menu and entrance

- Implement a user interface menu for game start, difficulty selection, and game exit.
- The entrance of the game should welcome players and guide them through the menu options.

#### 1.2 All the mines which have been detected and not detected should be stored into a data structure. A 9*9 array is a good choice

- ***'0' represents empty and '1' represents the mine.***
- The `mine` array stores the mine placement information, while the `show` array is displayed to the player.
- Using `srand((unsigned int)time(NULL));` or `srand(time(0));` for random number generation. The former is more cautious but both are essentially similar in functionality.

### 2. Code
```
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
```

#### ASCII Codes

- '0' - 48
- '1' - 49
- '2' - 50
- Subtracting '0' from a character converts it into a digit. This technique is used to calculate the number of mines surrounding a cell by adding up the characters of the eight surrounding cells and then subtracting 8*'0', converting `mine_num` to a character before storing it is necessary.

### 3. Expansion: 

#### Choose Game Difficulty

- Easy: 9x9 grid with 10 mines
- Medium: 16x16 grid with 40 mines
- Hard: 30x16 grid with 99 mines

#### Game Mechanics

1. **Exploration Mechanic**: If the checked position is not a mine and has no surrounding mines, the area around the coordinate can be revealed:
   - The coordinate is not a mine.
   - There are no mines surrounding the coordinate.
   - The coordinate has not been checked before.
2. **Mine Marking**: Players can mark suspected mine locations.
3. **Time Tracking**: Implement a timer to display the time taken to clear the mines.