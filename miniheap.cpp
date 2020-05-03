//#include <iostream>
//
//using namespace std;
//
//template <class T>
//class MinHeap {//最小堆ADT定义
//private :
//	T* heapArray;//存放堆数据的数组
//	int CurrentSize;//当前堆中元素的数目
//	int MaxSize;//堆能容纳最多的元素个数
//	void BuildHeap();//建堆
//
//public:
//	MinHeap(const int n);//构造函数
//	virtual ~MinHeap() { delete[]heapArray; };//析构函数
//	bool isLeaf(int pos)const;//如果是叶节点，返回true
//	int leftchild(int pos)const;//返回左孩子位置
//	int rightchild(int pos)const;//返回右孩子位置
//	int parent(int pos)const;//返回父节点位置
//	bool Remove(int pos, T& node);//删除给定下标元素
//	bool Insert(const T& newNode);//向堆中插入新元素newNode
//	T& RemoveMin();//从堆顶删除最小值
//	void SiftUp(int position);//从position向上开始调整，使序列成为堆
//	void SiftDown(int left);//筛选法函数，参数left表示开始处理的数组下标
//
//	MinHeap(const int n)
//	{
//		heapArray = new T[n];
//		MaxSize = n;
//		CurrentSize = 0;
//	}
//};
//
//template <class T>
//void MinHeap<T>::SiftDown(int position){
//	int i = position;//标记父节点
//	int j = 2 * i + 1;//标记关键值较小的子节点
//	T temp = heapArray[i];//保存父节点
//	while (j<CurrentSize){
//		//判断左右孩子
//		if ((j < CurrentSize - 1) &&
//			(heapArray[j] > heapArray[j + 1]))
//			j++;
//		//下移继续判断左孩子
//		if (temp > heapArray[j]) {
//			heapArray[i] = heapArray[j];
//			i = j;
//			j = 2 * i + 1;//向下继续
//		}
//		else
//			break;
//	}
//	//找到最终位置
//	heapArray[i] = temp;
//}
//
//template <class T>
//void MinHeap<T>::SiftUp(int position) {
//	//从position向上开始调整，使序列成为堆
//	int temppos = position;
//	//不是父子节点直接swap
//	int j = 2 * i + 1;//标记关键值较小的子节点
//	T temp = heapArray[temppos];//保存父节点
//	while ((temppos > 0) && heapArray[parent(temppos)] > temp) {//当父节点的值大于子节点的值，把子节点SiftUp
//		heapArray[temppos] = heapArray[parent(temppos)];
//		temppos = parent(temppos);
//	}
//	//找到最终位置
//	heapArray[temppos] = temp;
//}
//
////最小堆删除元素
//template <class T>
//bool MinHeap<T>::Remove(int pos, T&node){
//	if ((pos < 0) || (pos >= CurrentSize))
//		return false;
//	T temp = heapArray[pos];
//	heapArray[pos] = heapArray[--CurrentSize];
//	if (heapArray[parent(pos)] > heapArray[pos])
//		SiftUp(pos);//向上筛
//	else
//		SiftDown(pos);//向下筛
//	node = temp;
//	return true;
//}
//
//template<class T>
//void MinHeap<T>::BuildHeap(void)
//{
//	//反复调用筛选函数
//	for (int i = CurrentSize / 2 - 1; i >= 0; i--)
//	{
//		SiftDown(i);
//	}
//}
//
////向堆中插入新元素newMode
//template<class T>
//bool MinHeap<T>::Insert(const T& newMode)
//{
//	if (CurrentSize == MaxSize)//堆已经满了
//		return false;
//	heapArray[CurrentSize] = newMode;
//	SiftUp(CurrentSize);//向上调整
//	CurrentSize++;
//}
//
//
//int main(void)
//{
//	char str[2][3] = { {'a','b','c'},{'d','e','f'} };
//	return 0;
//}
