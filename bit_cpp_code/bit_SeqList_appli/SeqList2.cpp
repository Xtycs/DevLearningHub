#include "SeqList2.h"
#include "Directory.h"
using namespace std;

void SLInit(SL &s)
{
    s.arr = NULL;
    s.size = 0;
    s.capacity = 0;
}

void SLDestroy(SL &s)
{
    if(s.arr)//equal to (s.arr != NULL)
    {
        free(s.arr);
    }
    s.arr = NULL;
    s.size = s.capacity = 0;
}

void SLCheckCapacity(SL &s)
{
    if (s.size == s.capacity)
    {
        //apply the memory
        //malloc calloc realloc(more space)
        int newCapacity = s.capacity == 0 ? 4 : 2 * s.capacity;

        SLDataType *temp = (SLDataType *)realloc(s.arr, newCapacity * sizeof(SLDataType));
        if (temp == NULL)
        {
            perror("realloc failed!");
            exit(1);
        }
        else 
        {
            s.arr = temp;
            s.capacity = newCapacity;
        }
    }
}

void SLPrint(const SL &s)
{
    for (int i = 0; i < s.size; i++)
    {
        cout << s.arr[i] << " ";//!the directory can't print straightly, I defined a new one.
    }
}

void SLPushback(SL &s, SLDataType x)
{
    // s.arr[s.size] = x;
    // s.size++;

    //todo if s is a pointer, need to test if s is NULL. but here i use reference.
    SLCheckCapacity(s);
    s.arr[s.size++] = x;
}

void SLPushfront(SL &s, SLDataType x)
{
    SLCheckCapacity(s);
    for (int i = s.size; i >= 1; i--)
    {
        s.arr[i] = s.arr[i - 1];//from rear to the front
    }
    s.arr[0] = x;
    s.size++;
}

void SLPopback(SL &s)
{
    assert(s.size);
    assert(s.capacity);

    //* this line is not necessary, since not affect add,delete,search,edit.
    // s.arr[s.size - 1] = -1;
    s.size--;
}

void SLPopfront(SL &s)
{
    assert(s.size);
    assert(s.capacity);

    for (int i = 0; i <= s.size - 2; i++)
    {
        s.arr[i] = s.arr[i + 1];
    }
    s.size--;
}

//insert data infront of the position(index).
void SLInsert(SL &ps, int pos, SLDataType x)
{
    assert(ps.size);
    assert(ps.capacity);
    assert(pos >= 0 && pos <= ps.size);

    //whenever insert data, check the space.
    SLCheckCapacity(ps);

    //move the data behind the pos.
    //move from the rear, avoid overlap
    for (int i = ps.size; i >= 1; i--)
    {
        ps.arr[i] = ps.arr[i - 1];
    }
    ps.arr[pos] = x;
    ps.size++;
}

void SLErase(SL &ps, int pos)
{
    assert(ps.size);
    assert(ps.capacity);
    assert(pos >= 0 && pos < ps.size);//pos can't equal to size

    for (int i = pos; i <= ps.size - 2; i++)
    {
        ps.arr[i] = ps.arr[i + 1];
    }
    ps.size--;
}
//0 1 2 3
//        4

int SLFind(SL &ps, SLDataType x)
{
    assert(ps.size);
    assert(ps.capacity);
    for (int i = 0; i < ps.size; i++)
    {
        if (ps.arr[i] == x)
        {
            std::cout << "the number" << x << "is found" << std::endl;
            return i;
        }
    }
    return -1;
}//! this function is not used, so ignore the error message.