#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#define OVERFLOW -2
typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkList;

int InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(Node));
	if (!L)
		exit(OVERFLOW);
	L->next = NULL;
	return 1;
}



void CreatList(LinkList &L, int n) {
	LinkList p, r;
	r = L;
	int a;
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		scanf("%d", &a);
		p->data = a;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void PrintList(LinkList &L) {//输出单链表 
	LinkList q;
	q = L->next;
	while (q) {
		printf("%d ", q->data);
		q = q->next;
	}
}

void Combine(LinkList La, LinkList Lb, LinkList Lc) {
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
	PrintList(Lc);
}

int main() {
	int m, n;
	LinkList LA, LB;
	InitList(LA);
	InitList(LB);
	cout << "请输入创建单链表LA的元素个数：";
	cin >> m;
	CreatList(LA, m);
	cout << "请输入创建单链表LB的元素个数：";
	cin >> n;
	CreatList(LB, n);
	cout << endl;
	cout << "     链表LA中的元素" << endl;
	cout << "-----------------------\n";
	PrintList(LA);
	cout << endl;
	cout << "\n\n     链表LB中的元素" << endl;
	cout << "-----------------------\n";
	PrintList(LB);
	cout << "\n\nLA、LB合并后的输出结果：" << endl;
	LinkList Lc;
	InitList(Lc);
	Combine(LA, LB, Lc);
	return 0;
}