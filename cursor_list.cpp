#include <iostream>
using namespace std;

#define SpaceSize 10
typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitCursorSpace(void);
List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position FindPrevious(ElementType X, const List L);
void Insert(ElementType X, List L, Position p);
void DeleteList(List L);
ElementType Retrieve(const Position P);

struct Node
{
	ElementType Element;
	Position Next;
};
struct Node CursorSpace[SpaceSize];

void InitCursorSpace(void)
{
	for (int i = 0; i < SpaceSize - 1; i++)
	{
		CursorSpace[i].Next = i + 1;
	}
}

List MakeEmpty(List L)
{
	List TmpList;
	TmpList = L;
	while (TmpList!= 0)
	{
		CursorSpace[TmpList].Element = 0;
		TmpList = CursorSpace[TmpList].Next;
	}
}

static Position CursorAlloc(void)
{
	Position P;
	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;

	return P;
}

static void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

int IsEmpty(List L)
{
	return CursorSpace[L].Next == 0;
}

int IsLast(Position P, List L)
{
	return CursorSpace[P].Next == 0;
}

//规定Next成员值0表示为NULL
Position Find(ElementType X, List L)
{
	Position P;

	P = CursorSpace[L].Next;
	while (P && CursorSpace[P].Element != X)
		P = CursorSpace[P].Next;

	return P;
}

Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while (CursorSpace[P].Next != NULL && CursorSpace[CursorSpace[P].Next].Element != X)
		P = CursorSpace[P].Next;

	return P;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if (!IsLast(P, L))
	{
		TmpCell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;
		CursorFree(TmpCell);
	}
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = CursorAlloc();
	if (TmpCell == 0)
		exit(OVERFLOW);
	CursorSpace[TmpCell].Element = X;
	CursorSpace[TmpCell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = TmpCell;
}

void DeleteList(List L)
{
	CursorSpace[L].Next = 0;
}

ElementType Retrieve(const Position P)
{
	return CursorSpace[P].Element;
}

int main(int argc, char argv[])
{
	List L, M;
	InitCursorSpace();
	L = 0;
	M = 0;
	Insert(1, L, M);
	return 0;
}
