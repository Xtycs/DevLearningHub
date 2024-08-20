<img src = ./5-19--下午.png>

### Test.c
```c
#include"Heap.h"
#include<time.h>


typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//还没有学搜索二叉树，写不了初始化函数，这里手动创建一个二叉树
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(6);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//如果调用fun(10000)会导致栈溢出（Stack Overflow）
int fun(int n)
{
	if (n == 0)
		return 0;

	return fun(n - 1) + n;
}

//todo 方法一
//有问题，多次调用会导致size一直累加
int TreeSize(BTNode* root)
{
	static int size = 0;
	if (root == NULL)
		return 0;
	else
		++size;

	TreeSize(root->left);
	TreeSize(root->right);

	return size;
}

//todo 方法二
//在main函数中每次调用前都要将size置为0
int size = 0;
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		++size;

	TreeSize(root->left);
	TreeSize(root->right);

	return size;
}

//todo 方法三（不使用全局变量且没有返回值）
//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++(*psize);
//
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

//todo 方法四（分治思想）
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}



//todo 求叶子节点个数
int TreeLeafSize(BTNode* root)
{
	//这一步可以有效处理空树的情况，是必要的
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left)
		+ TreeLeafSize(root->right);
}



//todo 求二叉树的高度 方法一
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ?
		leftHeight + 1 : rightHeight + 1;
}
//以下会多次调用递归函数，效率低
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	return TreeHeight(root->left) > TreeHeight(root->right) ?
		TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;//每次比较大小后由于没记录，会再次向后求一次
}

//todo 求二叉树的高度 方法二
int fmax(int x, int y)
{
	return x > y ? x : y;
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}





int main()
{
	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");
	
	//printf("%d\n", fun(10000));

	/*int size = 0;
	TreeSize(root, &size);
	printf("TreeSize:%d\n",size);

	size = 0;
	TreeSize(root, &size);
	printf("TreeSize:%d\n", size);*/

	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeLeafSize:%d\n", TreeLeafSize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));

	return 0;
}

// int LeafSize(BTNode* root)
// {
// 	if(root == NULL)
// 		return 0;
// 	if (root->left == NULL && root->right == NULL)
// 		return 1;

// 	return LeafSize(root->left) + LeafSize(root->right);
// }


int TreeKNode(BTNode* root, int k)
{
	if(root == NULL)
		return 0;
	if (!root && k == 1)
		return 1;
	if (!root && k > 1)
		return TreeKNode(root->left, k - 1) + TreeKNode(root->right, k - 1);
}

bool isUnivalTree(struct TreeNode* root){
	return _isUnivalTree(root, root->val);
}

bool _isUnivalTree(struct TreeNode* root, int val)
{
}
```