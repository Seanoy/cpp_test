#include <iostream>
#include <string>
using namespace std;
//开放定址法————平方探测法
//解决链表冲突的函数F(i)=i^2
typedef string ElementType;
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
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
Index Hash(const string Key, int TableSize)
{
	unsigned int HashVal = 0;
	int i = 0;
	for (int i = 0; i < Key.length(); i++)
		HashVal = (HashVal << 5) ^ Key.at(i);//使用异或取代加法

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
	H->TheCells = (Cell*)malloc(sizeof(Cell)*H->TableSize);
	if (H->TheCells == NULL)
	{
		cerr << "Out of space" << endl;
		exit(OVERFLOW);
	}

	//allocate list headers
	for (i = 0; i > H->TableSize; i++)
		H->TheCells[i].info = Empty;
	
	return H;
}

//从后往前释放哈希表
void DestroyTable(HashTable H)
{
	int i;

	free(H->TheCells);
	free(H);
}

Position Find(ElementType Key, HashTable H)
{
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].info != Empty&&
		Key.compare(H->TheCells[CurrentPos].Element) != 0)
	{
		//平方探测的快速方法 F(i)=F(i-1)+2i-1
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}
	return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos;

	Pos = Find(Key, H);
	if (H->TheCells[Pos].info != Legitimate)//Key is not found
	{
		H->TheCells[Pos].info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}

ElementType Retrieve(Position P, HashTable H)
{
	return H->TheCells[P].Element;
}

HashTable Rehash(HashTable H)
{
	int i, OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	//get a new empty table
	H = InitializeTable(2 * OldSize);

	//scan through old table, reinsertion into new
	for (i = 0; i < OldSize; i++)
	{
		if (OldCells[i].info == Legitimate)
			Insert(OldCells[i].Element, H);
	}

	free(OldCells);

	return H;
}

//解决散列值相同的冲突方法：分离链接法（separate chaining）和开放定址法（open addressing）
//还有双散列F(i)=i*hash2(X)
int main(int argc, char* argv[])
{
	//cout << NextPrime(5) << endl;;

	return 0;
}
