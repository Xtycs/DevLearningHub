#include"Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	// 初始条件
	// 中间过程
	// 结束条件
	int parent = (child - 1) / 2;
	//while (parent >= 0) 这个凑巧也可行，但是由于除法取整问题parent实际上只能变为0
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		php->a = tmp;
		php->capacity = newcapacity;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

//                              n是size， parent是0
void AdjustDown(HPDataType* a, int n, int parent)
{
	// 先假设左孩子小,与最小的child交换才能满足minHeap的性质
	int child = parent * 2 + 1;

	while (child < n)  // child >= n 说明child已经越界了
	{
		//                      child+1 在这里可能越界
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// Pop删除尾部数据没有意义，默认要求删除堆顶数据（root）
// logN
//! 交换了头尾元素然后size--删除，最大程度保证了原本小堆的结构（大小亲缘关系），左子树和右子树都仍然是minHeap，所以只需要向下调整一次即可
//! 如果直接删除头元素，或直接进行内存位置调整，亲缘关系会被破坏，需要重新调整
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

bool HPEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}