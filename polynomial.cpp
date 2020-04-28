#include <iostream>
#include <cstdlib>
using namespace std;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Polynormial;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

//����ʽ����ṹ��
struct Node
{
	ElementType Coefficient;//ϵ��
	ElementType Exponent;//��ָ��
	PtrToNode Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position FindCoef(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Coefficient != X)
		P = P->Next;
	return P;
}

Position FindExp(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Exponent != X)
		P = P->Next;
	return P;
}

Position FindPreviousCoef(ElementType X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Coefficient != X)
		P = P->Next;
	return P;
}

Position FindPreviousExp(ElementType X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Exponent != X)
		P = P->Next;
	return P;
}

void DeleteCoef(ElementType X, List &L)
{
	Position P, TmpCell;
	P = FindPreviousCoef(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void DeleteExp(ElementType X, List &L)
{
	Position P, TmpCell;

	P = FindPreviousExp(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void Delete(Position &P, List L)
{
	Position TmpCell;

	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void Insert(ElementType X_Coef, ElementType X_Exp, List L, Position &P)
{
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		exit(OVERFLOW);
	TmpCell->Coefficient = X_Coef;
	TmpCell->Exponent = X_Exp;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
	P = P->Next;
}

//��ʼ������ ���header
void InitPolynomial(Polynormial &Poly)
{
	Poly = (Polynormial)malloc(sizeof(struct Node));
	if (Poly == NULL)
		exit(OVERFLOW);//ջ���

	Poly->Next = NULL;
}

//����ʽ�������
void AddPolynomial(Polynormial Poly1, Polynormial Poly2, Polynormial &PolySum)
{
	//assume the input params are their header 
	Polynormial TempPoly = NULL;
	Polynormial TempSum = PolySum;
	Poly1 = Poly1->Next;

	while (Poly1 != NULL)//����Poly1
	{
		if ((TempPoly = FindExp(Poly1->Exponent, Poly2)) != NULL)
		{
			//�й�������е��Ӵ���
			Insert(Poly1->Coefficient + TempPoly->Coefficient, Poly1->Exponent, PolySum, PolySum);
		}
		else
			//����ֻ��������1��Ԫ��
			Insert(Poly1->Coefficient, Poly1->Exponent, PolySum, PolySum);

		Poly1 = Poly1->Next;
	}

	Poly2 = Poly2->Next;
	PolySum = TempSum;
	while (Poly2 != NULL)
	{
		//�����sum���Ҳ���poly2��Ӧ��exponent
		if (FindExp(Poly2->Exponent, PolySum) == NULL)
		{
			Insert(Poly2->Coefficient, Poly2->Exponent, PolySum, PolySum);
			PolySum = PolySum->Next;
		}
		Poly2 = Poly2->Next;
	}
	PolySum = TempSum;
}

//������������ʽ
void SwapPolynomial(Polynormial Poly1, Polynormial Poly2)
{
	Node temp;
	temp.Coefficient = Poly1->Coefficient;
	temp.Exponent = Poly1->Exponent;

	Poly1->Coefficient = Poly2->Coefficient;
	Poly1->Exponent = Poly2->Exponent;

	Poly2->Coefficient = temp.Coefficient;
	Poly2->Exponent = temp.Exponent;
}

//�����ݴ�����
void SortPolynomial(Polynormial &Poly)
{
	for (Polynormial Poly1 = Poly->Next; Poly1 != NULL; Poly1 = Poly1->Next)
	{
		for (Polynormial Poly2 = Poly->Next; Poly2->Next != NULL; Poly2 = Poly2->Next)
		{
			if (Poly1->Exponent < Poly2->Exponent) // ��С����ð������
				SwapPolynomial(Poly1, Poly2);
		}
	}
}

//�ϲ�ͬ����
void CombinePolynomial(Polynormial &Poly)
{
	Polynormial TempPoly;
	Position P;
	TempPoly = Poly->Next;
	while (TempPoly != NULL)
	{
		if (!IsLast((P = FindPreviousExp(TempPoly->Exponent, TempPoly)), TempPoly))//��ͬ����
		{
			TempPoly->Coefficient += P->Next->Coefficient;
			Delete(P, TempPoly);
		}
		TempPoly = TempPoly->Next;
	}
}

//����ʽ�������
void MultPolynomial(Polynormial Poly1, Polynormial Poly2, Polynormial &PolyMultiply)
{
	//assume the input params are their header 
	Polynormial TempPoly1 = Poly1->Next;
	Polynormial TempPoly2 = Poly2->Next;
	Polynormial TempMultiply = PolyMultiply;

	//���Ȼ����뵽����
	while (TempPoly1 != NULL)
	{
		while (TempPoly2 != NULL)
		{
			Insert(TempPoly1->Coefficient * TempPoly2->Coefficient, TempPoly1->Exponent + TempPoly2->Exponent, PolyMultiply, PolyMultiply);
			TempPoly2 = TempPoly2->Next;
		}
		TempPoly2 = Poly2->Next;
		TempPoly1 = TempPoly1->Next;
	}

	//���������ϲ�ͬ�������
	PolyMultiply = TempMultiply;
	CombinePolynomial(PolyMultiply);
	PolyMultiply = TempMultiply;
	SortPolynomial(PolyMultiply);

	PolyMultiply = TempMultiply;
}

int main(int argc, char* argv[])
{
	Polynormial poly1, poly2;
	Polynormial sum;
	Polynormial multiply;
	Position P1, P2;
	poly1 = NULL;
	poly2 = NULL;
	sum = NULL;
	multiply = NULL;

	InitPolynomial(poly1);
	InitPolynomial(poly2);
	InitPolynomial(sum);
	InitPolynomial(multiply);

	P1 = poly1;
	P2 = poly2;

	Insert(1, 1, poly1, P1);
	Insert(3, 2, poly1, P1);

	Insert(2, 2, poly2, P2);
	Insert(1, 1, poly2, P2);

	//	AddPolynomial(poly1, poly2, sum);
	MultPolynomial(poly1, poly2, multiply);
	return 0;
}
