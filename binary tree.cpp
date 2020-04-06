#include <iostream>
#include <algorithm>
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
	else if (T->Left == NULL)//已经找不到最小值了
		return T;
	else
		return FindMin(T->Left);
}


Position FindMax(SearchTree T)
{
	//递归方式
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)//已经找不到最大值了
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

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		//创建并返回一个单节点树
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
			//如果树已经存在相同的元素想记录重复次数，我们可以在树的结构体内新增一个成员
	}
	return T;
}

/*
删除需要考虑几种情况：
1、节点是树叶，则可直接删除
2、节点有一个子节点，则该子节点可以在其父节点调整指针绕过该节点后被删除
3、节点有两个子节点，一般的策略是用其右子树的最小数据（又或者使用左子树的最大数据）代替该节点的数据并递归删除那个节点。因为右子树中的最小节点不可能有左节点，所以第二次删除要简单些。
*/
SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
		cerr << "Element not found" << endl;
	else if (X < T->Element)//寻找对应元素的节点
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else //找到该元素并执行删除操作
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
			if (T->Left == NULL)//同时处理节点为树叶的情况
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
