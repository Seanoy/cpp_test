#include <iostream>
#include <string>
using namespace std;
//���Ŷ�ַ����������ƽ��̽�ⷨ
//��������ͻ�ĺ���F(i)=i^2
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

//�����ϣֵ
Index Hash(const string Key, int TableSize)
{
	unsigned int HashVal = 0;
	int i = 0;
	for (int i = 0; i < Key.length(); i++)
		HashVal = (HashVal << 5) ^ Key.at(i);//ʹ�����ȡ���ӷ�

	return (HashVal % TableSize);
}

//���ش��ڸ�����������
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

//������ϣ��
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

//�Ӻ���ǰ�ͷŹ�ϣ��
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
		//ƽ��̽��Ŀ��ٷ��� F(i)=F(i-1)+2i-1
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

//���ɢ��ֵ��ͬ�ĳ�ͻ�������������ӷ���separate chaining���Ϳ��Ŷ�ַ����open addressing��
//����˫ɢ��F(i)=i*hash2(X)
int main(int argc, char* argv[])
{
	//cout << NextPrime(5) << endl;;

	return 0;
}
