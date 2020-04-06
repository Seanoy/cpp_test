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
int Height(Position P);//���ؽڵ�߶�ֵ
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
	else if (T->Left == NULL)//�Ѿ��Ҳ�����Сֵ��
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(AvlTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)//�Ѿ��Ҳ������ֵ��
		return T;
	else
		return FindMax(T->Right);
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		//����������һ�����ڵ���
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
	//���Ԫ����ͬ�򲻽��в���
	T->Height = max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

/*
ɾ����Ҫ���Ǽ��������
1���ڵ�����Ҷ�����ֱ��ɾ��
2���ڵ���һ���ӽڵ㣬����ӽڵ�������丸�ڵ����ָ���ƹ��ýڵ��ɾ��
3���ڵ��������ӽڵ㣬һ��Ĳ�������������������С���ݣ��ֻ���ʹ����������������ݣ�����ýڵ�����ݲ��ݹ�ɾ���Ǹ��ڵ㡣��Ϊ�������е���С�ڵ㲻��������ڵ㣬���Եڶ���ɾ��Ҫ��Щ��
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
	else//�ҵ��˽ڵ�λ�ã���������Ҫ���ݼ���������д���
	{
		if (T->Left && T->Right)//�������ӣ�ʹ����������СԪ�ش���ýڵ�
		{
			TmpCell = FindMin(T->Right);
			T->Element = TmpCell->Element;
			T->Right = Delete(T->Element, T->Right);
		}
		else//��һ��������ӽڵ�
		{
			TmpCell = T;
			if (T->Left == NULL)//ͬʱ����ڵ�Ϊ��/����Ҷ�����
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
