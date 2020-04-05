#include <iostream>
using namespace std;

//队列基本操作是入队操作enqueue，它在表的末尾（rear）插入元素，在表的开头（front）删除/返回元素
typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#define MinQueueSize (5)

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

Queue CreateQueue(int MaxElements)
{
	Queue Q;
	if (MaxElements < MinQueueSize)
	{
		cerr << "Queue size is too small" << endl;
		return NULL;
	}
	else
	{
		Q = (Queue)malloc(sizeof(struct QueueRecord));
		if (Q == NULL)
			cerr << "Out of space" << endl;

		Q->Array = (ElementType*)malloc(sizeof(ElementType)*MaxElements);
		if (Q->Array == NULL)
			cerr << "Out of space" << endl;

		Q->Capacity = MaxElements;
		MakeEmpty(Q);
		return Q;
	}
}

void DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}

static int Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)
		Value = 0;
	return Value;
}

void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
		cerr << "Full queue" << endl;
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

ElementType Front(Queue Q)
{
	return Q->Array[Q->Front];
}

void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
		cerr << "Empty queue" << endl;
	else
	{
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
	}
}

ElementType FrontAndDequeue(Queue Q)
{
	if (IsEmpty(Q))
		cerr << "Empty queue" << endl;
	else
	{
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
		return Q->Array[Q->Front];
	}
}

int main(int argc, char argv[])
{

	return 0;
}
