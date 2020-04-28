#include <iostream>
#include <algorithm>
using namespace std;

typedef int ElementType;

//��������ÿ���ڵ㲻���ж��������Ķ���
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);
void PrintTree(SearchTree T);
int Height(Position P);

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};


SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);//�ݹ�����ӽڵ�
		MakeEmpty(T->Right);
		free(T);//�������ն��������
	}
	return NULL;
}
//�ڵ�������ӽڵ� С�����ӽڵ�
Position Find(ElementType X, SearchTree T)
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

Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)//�Ѿ��Ҳ�����Сֵ��
		return T;
	else
		return FindMin(T->Left);
}


Position FindMax(SearchTree T)
{
	//�ݹ鷽ʽ
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)//�Ѿ��Ҳ������ֵ��
		return T;
	else
		return FindMax(T->Right);
	/*
	//�ǵݹ鷽ʽ
	if(T!=NULL)
		while(T->Right != NULL)
			T=T->Right;
	return T;
	*/
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		//����������һ�����ڵ���
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if (T == NULL)
		{
			cerr << "Out of space" << endl;
		}
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else
	{
		if (X < T->Element)
			T->Left = Insert(X, T->Left);
		else if (X > T->Element)
			T->Right = Insert(X, T->Right);
		//else //do nothing
			//������Ѿ�������ͬ��Ԫ�����¼�ظ����������ǿ��������Ľṹ��������һ����Ա
	}
	return T;
}

/*
ɾ����Ҫ���Ǽ��������
1���ڵ�����Ҷ�����ֱ��ɾ��
2���ڵ���һ���ӽڵ㣬����ӽڵ�������丸�ڵ����ָ���ƹ��ýڵ��ɾ��
3���ڵ��������ӽڵ㣬һ��Ĳ�������������������С���ݣ��ֻ���ʹ����������������ݣ�����ýڵ�����ݲ��ݹ�ɾ���Ǹ��ڵ㡣��Ϊ�������е���С�ڵ㲻��������ڵ㣬���Եڶ���ɾ��Ҫ��Щ��
*/
SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
		cerr << "Element not found" << endl;
	else if (X < T->Element)//Ѱ�Ҷ�ӦԪ�صĽڵ�
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else //�ҵ���Ԫ�ز�ִ��ɾ������
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
			if (T->Left == NULL)//ͬʱ����ڵ�Ϊ��Ҷ�����
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

static void PrintElement(ElementType X)
{
	cout << X << endl;
}

void PrintTree(SearchTree T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		PrintElement(T->Element);
		PrintTree(T->Right);
	}
}

static int Height(SearchTree T)
{
	if (T == NULL)
		return -1;
	else
		return 1 + max(Height(T->Left), Height(T->Right));
}

int main(int argc, char* argv[])
{

	return 0;
}
