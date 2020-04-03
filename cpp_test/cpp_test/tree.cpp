#include <iostream>
using namespace std;

typedef int ElementType;

typedef struct TreeNode *PtrToNode;

struct TreeNode
{
	ElementType Element;//元素值
	PtrToNode FirstChild;//第一个儿子
	PtrToNode NextSibling;//下一个兄弟节点
};

/*
列出分级文件系统中目录的例程 伪代码
这是一种先序遍历（preorder traversal），对节点的处理工作是在它的诸儿子节点被处理之前（pre）进行的
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
计算一个目录大小的例程 伪代码
这是一种后序遍历（postorder traverval），在一个节点处的工作是在它的诸儿子节点被计算后（post）进行的
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
