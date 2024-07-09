#include <cstdio>




bool is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int get_day_of_month(int year, int month)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = days[month];
    if(is_leap_year(year) && month == 2)
    {
        day++;
    }

    return day;
}

// int main()
// {
//     test();
//     printf("Hello, World!\n");
//     return 0;
// }


// #include <stdio.h>
// int main()
// {
//     printf("%d\n", printf("%d", printf("%d", 43)));
// }

// void test()
// {
//     //int i = 0;
//     static int i = 0;
//     i++;
//     printf("%d\n", i);
// }

// int main()
// {
//     int i = 0;
//     for (int i = 0; i < 5; i++)
//         test();
//     return 0;
// }

// extern int g_val;
// int main()
// {
//     printf("%d\n", g_val);
//     return 0;
// }

extern int Add(int a, int b);
int main()
{
    printf("%d\n", Add(1, 2));
    return 0;
}