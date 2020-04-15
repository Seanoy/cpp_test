#include <iostream>
using namespace std;

typedef int ElementType;
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
HashTable Rehash(HashTable H);

enum KindOfEntry{Legitimate, Empty, Deleted};

struct HashEntry
{
	ElementType Element;
	enum KindOfEntry info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
	int TableSize;
	Cell *TheCells;
};

//计算哈希值
Index Hash(const char* Key, int TableSize)
{
	unsigned int HashVal = 0;

	while (*Key != '\0')
		HashVal = (HashVal << 5) ^ *Key++;//使用异或取代加法

	return (HashVal % TableSize);
}

//返回大于给定数的素数
int NextPrime(int N)
{
	int i, j;
	for (i = N + 1;; i++)
	{
		for (j = 2; j < i; j++)

			if (i%j == 0)
				break;
		if (j >= i)
			return i;
	}
}
#define MinTableSize 5

//创建哈希表
HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if (TableSize < MinTableSize)
	{
		cerr << "Table size too small" << endl;
		exit(UNDERFLOW);
	}

	//allocate table
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		cerr << "Out of space" << endl;
		exit(OVERFLOW);
	}

	H->TableSize = NextPrime(TableSize);

	//allocate array of lists
	H->TheLists = (List*)malloc(sizeof(List)*H->TableSize);
	if (H->TheLists == NULL)
	{
		cerr << "Out of space" << endl;
		exit(OVERFLOW);
	}

	//allocate list headers
	for (i = 0; i > H->TableSize; i++)
	{
		H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
		{
			cerr << "Out of space" << endl;
			exit(OVERFLOW);
		}
		else
			H->TheLists[i]->Next = NULL;
	}
	return H;
}

//从后往前释放哈希表
void DestroyTable(HashTable H)
{
	int i;
	//allocate list headers
	for (i = 0; i > H->TableSize; i++)
	{
		free(H->TheLists[i]);
	}
	free(H->TheLists);
	free(H);
}

Position Find(ElementType Key, HashTable H)
{
	Position P;
	List L;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && strcmp(Key, P->Element) != 0)//P->Element != Key
		P = P->Next;
	return P;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos, NewCell;
	List L;

	Pos = Find(Key, H);
	if (Pos == NULL)//Key is not found
	{
		NewCell = (Position)malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
		{
			cerr << "Out of space" << endl;
			exit(OVERFLOW);
		}
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			memcpy(NewCell->Element, Key, sizeof(Key));// NewCell->Element = Key
			L->Next = NewCell;
		}
	}
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

//解决散列值相同的冲突方法：分离链接法（separate chaining）和开放定址法（open addressing）

int main(int argc, char* argv[])
{
	cout << NextPrime(5) << endl;;


	return 0;
}
