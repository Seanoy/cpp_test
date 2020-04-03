#include <iostream>
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
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}


Position FindMax(SearchTree T)
{
	//�ݹ鷽ʽ
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
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

SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);



int main(int argc, char* argv[])
{

	return 0;
}
