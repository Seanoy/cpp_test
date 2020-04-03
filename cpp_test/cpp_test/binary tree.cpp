#include <iostream>
using namespace std;

typedef int ElementType;

//二叉树的每个节点不能有多于两个的儿子
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
		MakeEmpty(T->Left);//递归清空子节点
		MakeEmpty(T->Right);
		free(T);//最后再清空二叉查找树
	}
	return NULL;
}
//节点大于左子节点 小于右子节点
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
	//递归方式
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
	/*
	//非递归方式
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
