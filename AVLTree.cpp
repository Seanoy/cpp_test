#include <iostream>
#include <algorithm>

using namespace std;

typedef int ElementType;

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
Position SingleRotateWithLeft(Position K2);
Position SingleRotateWithRight(Position K2);
Position DoubleRotateWithLeft(Position K3);
Position DoubleRotateWithRight(Position K3);
int Height(Position P);//返回节点高度值
void PrintTree(AvlTree T);

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, AvlTree T)
{
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}

Position FindMin(AvlTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)//已经找不到最小值了
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(AvlTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)//已经找不到最大值了
		return T;
	else
		return FindMax(T->Right);
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		//创建并返回一个单节点树
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL)
			cerr << "Out of space" << endl;
		else
		{
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else
	{
		if (X < T->Element)
		{
			T->Left = Insert(X, T->Left);
			if (Height(T->Left) - Height(T->Right) == 2)
			{
				if (X < T->Left->Element)
					T = SingleRotateWithLeft(T);
				else
					T = DoubleRotateWithLeft(T);
			}
		}
		else if (X>T->Element)
		{
			T->Right = Insert(X, T->Right);
			if (Height(T->Right) - Height(T->Left) == 2)
			{
				if (X > T->Right->Element)
					T = SingleRotateWithRight(T);
				else
					T = DoubleRotateWithRight(T);
			}
		}
	}
	//如果元素相同则不进行操作
	T->Height = max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

/*
删除需要考虑几种情况：
1、节点是树叶，则可直接删除
2、节点有一个子节点，则该子节点可以在其父节点调整指针绕过该节点后被删除
3、节点有两个子节点，一般的策略是用其右子树的最小数据（又或者使用左子树的最大数据）代替该节点的数据并递归删除那个节点。因为右子树中的最小节点不可能有左节点，所以第二次删除要简单些。
*/
AvlTree Delete(ElementType X, AvlTree T)
{
	Position TmpCell;

	if (T == NULL)
		cerr << "Element not found" << endl;
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else//找到了节点位置，接下来就要根据几种情况进行处理
	{
		if (T->Left && T->Right)//两个儿子，使用右子树最小元素代替该节点
		{
			TmpCell = FindMin(T->Right);
			T->Element = TmpCell->Element;
			T->Right = Delete(T->Element, T->Right);
		}
		else//有一个或零个子节点
		{
			TmpCell = T;
			if (T->Left == NULL)//同时处理节点为左/右树叶的情况
				T = T->Right;
			else if (T->Right == NULL)
				T = T->Left;
			free(TmpCell);
		}
	}
	return T;
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

static int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = max(Height(K1->Left), K2->Height) + 1;

	return K1;
}

Position SingleRotateWithRight(Position K2)
{
	Position K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = max(Height(K1->Right), K2->Height) + 1;

	return K1;
}

Position DoubleRotateWithLeft(Position K3)
{
	K3->Left = SingleRotateWithRight(K3->Left);

	return SingleRotateWithLeft(K3);
}

Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);

	return SingleRotateWithRight(K3);
}

void PrintElement(ElementType X)
{
	cout << X << endl;
}

void PrintTree(AvlTree T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		PrintElement(T->Element);
		PrintTree(T->Right);
	}
}

int main(int argc, char* argv[])
{

	return 0;
}
