#include <iostream>
using namespace std;

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S;

	S = (Stack)malloc(sizeof(struct Node));
	if (S == NULL)
		cerr << "Out of space" << endl;
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S)
{
	if (S == NULL)
		cerr << "Must use CreateStack first" << endl;
	else
		while (!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell;

	TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		cerr << "Out of space" << endl;
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Next->Element;
	else
		cerr << "Empty stack" << endl;
	return 0;
}

void Pop(Stack S)
{
	PtrToNode FirstCell;

	if (!IsEmpty(S))
		cerr << "Empty stack" << endl;
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}

int main(int argc, char* argv[])
{

	return 0;
}
