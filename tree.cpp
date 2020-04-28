#include <iostream>
using namespace std;

typedef int ElementType;

typedef struct TreeNode *PtrToNode;

struct TreeNode
{
	ElementType Element;//Ԫ��ֵ
	PtrToNode FirstChild;//��һ������
	PtrToNode NextSibling;//��һ���ֵܽڵ�
};

/*
�г��ּ��ļ�ϵͳ��Ŀ¼������ α����
����һ�����������preorder traversal�����Խڵ�Ĵ�����������������ӽڵ㱻����֮ǰ��pre�����е�
static void ListDir(DirectoryFile D ,int Depth)
{
	if(D is a legitimate entry)
	{
		PrintName(D, Depth);
		if(D is a directory)
			for each child C of D:
				ListDir(C, Depth + 1);
	}
}

void ListDirectory(DirectoryFile D)
{
	ListDir(D, 0);
}
*/

/*
����һ��Ŀ¼��С������ α����
����һ�ֺ��������postorder traverval������һ���ڵ㴦�Ĺ���������������ӽڵ㱻�����post�����е�
static int SizeDirectory(DirectoryFile D)
{
	int TotalSize=0;
	if(D is a legitimate entry)
	{
		TotalSize = FileSize(D);
		if(D is a Directory)
			for each child C of D:
				TotalSize += SizeDirectory(C);
	}
	return TotalSize;
}

*/

int main(int argc, char *argv[])
{

	return 0;
}
