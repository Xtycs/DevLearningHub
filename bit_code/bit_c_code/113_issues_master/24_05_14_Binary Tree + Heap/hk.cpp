#include <iostream>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity; 
}Heap;

void HeapInit(Heap* hp);
void HeapDestory(Heap* hp);

void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
void AdjustUp(HPDataType *hp, int child);
void AdjustDown(HPDataType *hp, int parents, int end);

HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);




void Switch(HPDataType* hp, int e1, int e2)
{
    HPDataType current = hp[e1];
    hp[e1] = hp[e2];
    hp[e2] = current;
}

void HeapInit(Heap* hp)
{
    assert(hp);
    hp->_a = nullptr;
    hp->_size = hp->_capacity = 0;
}

void HeapDestory(Heap* hp)
{
    assert(hp);
    free(hp->_a);
    hp->_a = nullptr;
    hp->_size = hp->_capacity = 0;
}

void HeapPush(Heap* hp, HPDataType x)//Heap还是原来的，所以不需要考虑扩容size和capacity的数据
{
    assert(hp);
    if (hp->_size == hp->_capacity)
    {
        int new_capacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
        HPDataType *tmp = (HPDataType *)realloc(hp->_a, new_capacity * sizeof(HPDataType));
        if(!tmp)
        {
            perror("realloc fail");
            return;
        }

        hp->_capacity = new_capacity;
    }

    hp->_a[hp->_size] = x;
    hp->_size++;

    AdjustUp(hp->_a, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
    assert(hp);
    assert(hp->_size != 0);

    Switch(hp->_a, 0, hp->_size - 1);
    hp->_size--;
    AdjustDown(hp->_a, 0, hp->_size - 1);
}

void AdjustUp(HPDataType *rhp, int child)
{
    assert(rhp);

    int parents = (child - 1) / 2;
    while(child > 0)//parents >= 0 由于取整问题parents最小就是0， 不会变成负数
    {
        if(rhp[child] < rhp[parents])
        {
            Switch(rhp, child, parents);
            child = parents;
            parents = (child - 1) / 2;
        }
        else
            break;
    }
}

void AdjustDown(HPDataType *rhp, int parents, int end)
{
    assert(rhp);

    int child = parents * 2 + 1;//assume left child is the target
    while(child <= end)
    {
        if (child + 1 <= end && rhp[child + 1] < rhp[child])//end is the index of last element, not the size (actually size - 1)
        {
            child++;
        }

        if(rhp[child] < rhp[parents])
        {
            Switch(rhp, child, parents);
            parents = child;
            child = parents * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

HPDataType HeapTop(Heap* hp)
{
    assert(hp);
    assert(hp->_size > 0);

    return hp->_a[0];
}

int HeapSize(Heap* hp)
{
    assert(hp);
    return hp->_size;
}

int HeapEmpty(Heap* hp)
{
    assert(hp);
    return hp->_size == 0;
}




void MyHeapSort(int *a, int n)
{
	int end = n - 1;
	for (int i = (end - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, end);//我的ADjustDown和老师写的不同，参数顺序改变，且end就是末尾元素下标
	}

	while (end > 0)//end == 0 会导致向下调整越界
	{
		Switch(a, 0, end);
		end--;
		AdjustDown(a, 0, end);
	}
}

void AdjustDown(HPDataType *rhp, int parents, int end)
{
    assert(rhp);

    int child = parents * 2 + 1;//assume left child is the target
    while(child <= end)
    {
        if (child + 1 <= end && rhp[child + 1] < rhp[child])//end is the index of last element, not the size (actually size - 1)
        {
            child++;
        }

        if(rhp[child] < rhp[parents])
        {
            Switch(rhp, child, parents);
            parents = child;
            child = parents * 2 + 1;
        }
        else
        {
            break;
        }
    }
}