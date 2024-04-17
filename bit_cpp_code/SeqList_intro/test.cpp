#include <iostream>
#include "SeqList.h"
//* The static Sequence List
// struct SeqList1
// {
//     int arr[100];
//     int size;
// };

//* The Dynamic Sequence List
// struct SeqList
// {
//     int *arr;
//     int size; //current valid data number
//     int capacity; //total storage capacity(maximum number of element)
// };


//.h file will delear function and struct
//.cpp file will define function

void SLTest()
{
    SL s1;
    SLInit(s1);

    SLPushback(s1, 1);
    SLPushback(s1, 2);
    SLPushback(s1, 3);
    SLPushback(s1, 4);

    SLPushfront(s1, 5);
    SLPushfront(s1, 6);
}

void SLTest02()
{
    SL s1;
    SLInit(s1);
    SLPushback(s1, 1);
    SLPushback(s1, 2);
    SLPushback(s1, 3);
    SLPushback(s1, 4);
    SLPrint(s1);
    std::cout << std::endl;

    SLInsert(s1, 0, 99);
    SLPrint(s1);
}

int main()
{
    SLTest02();
    return 0;
}