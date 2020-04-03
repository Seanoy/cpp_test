#include <iostream>
using namespace std;

typedef int ElementType;

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity;
}

Stack CreateStack(int MaxElements)
{
	Stack S;

	if (MaxElements < MinStackSize)
	{
		cerr << "Stack size is too small" << endl;
	}
	S = (Stack)malloc(sizeof(struct StackRecord));

	if (S == NULL)
		cerr << "Out of space" << endl;

	S->Array = (ElementType*)malloc(sizeof(ElementType)*MaxElements);

	if(S->Array ==NULL)
		cerr << "Out of space" << endl;
	S->Capacity = MaxElements;

	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);//先释放数组
		free(S);//再释放指针
	}
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
	{
		cerr << "Full stack" << endl;
	}
	else
		S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];
	else
		cerr << "Empty stack" << endl;
	return 0;
}

void Pop(Stack S)
{
	if (!IsEmpty(S))
		cerr << "Empty stack" << endl;
	else
		S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	else
		cerr << "Empty stack" << endl;
	return 0;
}

int main(int argc, char* argv[])
{
	
	return 0;
}
