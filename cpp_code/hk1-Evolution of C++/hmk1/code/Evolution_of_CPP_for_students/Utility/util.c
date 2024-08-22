/********************** 
* Homework done by 
* Student1:Tingyang Xie(解汀阳)  Class:CS111 D2  Student ID:1230019461
*********************** 
*/


/************************************************ 
 * CS111/EIE111 2024
 * Project Designed by the teacher: Zhiyao Liang
 * zyliang@must.edu.mo
 * **********************************************
*/


#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for malloc

Bytes clone_bytes(Bytes bt)
{
    /***   provide the missing clode  here     ~~~~~~~~~ <Task 1>  ~~~~~~~~~  ***/
    Bytes new_bytes;
    new_bytes.addr = NULL;
    new_bytes.len = 0;

    if (bt.addr != NULL && bt.len > 0)
    {
        new_bytes.addr = malloc(bt.len);
        if (new_bytes.addr == NULL)
        {
            printf("Memory Allocation Faild.\n");
            exit(EXIT_FAILURE);
        }
        memcpy(new_bytes.addr, bt.addr, bt.len);
        new_bytes.len = bt.len;
    }

    return new_bytes;
}

Bytes make_bytes(void *addr, size_t len)
{
    /***   provide the missing clode  here     ~~~~~~~~~ <Task 2>  ~~~~~~~~~  ***/
    Bytes new_bytes;
    new_bytes.addr = addr;
    new_bytes.len = len;

    return new_bytes;
}

char *clone_str(const char *source)
{
    /***   provide the missing clode  here     ~~~~~~~~~ <Task 3>  ~~~~~~~~~  ***/
    char *cloned_arr = malloc(strlen(source) + 1);

    if (cloned_arr == NULL)
    {
        printf("Memory Allocation Faild.\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(cloned_arr, source);
    return cloned_arr;
}

void clear_input_queue(void)
{
    /***   provide the missing clode  here     ~~~~~~~~~ <Task 4>  ~~~~~~~~~  ***/
    int a;
    while ((a = getchar()) != '\n' && a != EOF){};
}

void pause(void)
{
    /***   provide the missing clode  here     ~~~~~~~~~ <Task 5>  ~~~~~~~~~  ***/
    printf("Please give the input to continue.\n");
    clear_input_queue();
}

// print each byte as a char. If a byte is 0, it is not printed.
void show_bytes_as_chars(Bytes bt)
{
    /***   provide the missing clode  here     ~~~~~~~~~ <Task 6>  ~~~~~~~~~  ***/
    unsigned char *ptr = bt.addr;
    for (int i = 0; i < bt.len; i++)
    {
        if(ptr[i]!='\0')
        {
            putchar(ptr[i]);
        }
    }
}

// print each byte as an unsigned int, separated by a space.
void show_bytes_as_nums(Bytes bt)
{
    /***   provide the missing clode  here     ~~~~~~~~~ <Task 7>  ~~~~~~~~~  ***/
    unsigned char *ptr = bt.addr;
    for (int i = 0; i < bt.len; i++)
    {
        if(ptr[i]!='\0')
        {
            printf("%u ", ptr[i]);
        }
    }
}
