//#include <iostream>
//
//using namespace std;
//
//template <class T>
//class MinHeap {//��С��ADT����
//private :
//	T* heapArray;//��Ŷ����ݵ�����
//	int CurrentSize;//��ǰ����Ԫ�ص���Ŀ
//	int MaxSize;//������������Ԫ�ظ���
//	void BuildHeap();//����
//
//public:
//	MinHeap(const int n);//���캯��
//	virtual ~MinHeap() { delete[]heapArray; };//��������
//	bool isLeaf(int pos)const;//�����Ҷ�ڵ㣬����true
//	int leftchild(int pos)const;//��������λ��
//	int rightchild(int pos)const;//�����Һ���λ��
//	int parent(int pos)const;//���ظ��ڵ�λ��
//	bool Remove(int pos, T& node);//ɾ�������±�Ԫ��
//	bool Insert(const T& newNode);//����в�����Ԫ��newNode
//	T& RemoveMin();//�ӶѶ�ɾ����Сֵ
//	void SiftUp(int position);//��position���Ͽ�ʼ������ʹ���г�Ϊ��
//	void SiftDown(int left);//ɸѡ������������left��ʾ��ʼ����������±�
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
//	int i = position;//��Ǹ��ڵ�
//	int j = 2 * i + 1;//��ǹؼ�ֵ��С���ӽڵ�
//	T temp = heapArray[i];//���游�ڵ�
//	while (j<CurrentSize){
//		//�ж����Һ���
//		if ((j < CurrentSize - 1) &&
//			(heapArray[j] > heapArray[j + 1]))
//			j++;
//		//���Ƽ����ж�����
//		if (temp > heapArray[j]) {
//			heapArray[i] = heapArray[j];
//			i = j;
//			j = 2 * i + 1;//���¼���
//		}
//		else
//			break;
//	}
//	//�ҵ�����λ��
//	heapArray[i] = temp;
//}
//
//template <class T>
//void MinHeap<T>::SiftUp(int position) {
//	//��position���Ͽ�ʼ������ʹ���г�Ϊ��
//	int temppos = position;
//	//���Ǹ��ӽڵ�ֱ��swap
//	int j = 2 * i + 1;//��ǹؼ�ֵ��С���ӽڵ�
//	T temp = heapArray[temppos];//���游�ڵ�
//	while ((temppos > 0) && heapArray[parent(temppos)] > temp) {//�����ڵ��ֵ�����ӽڵ��ֵ�����ӽڵ�SiftUp
//		heapArray[temppos] = heapArray[parent(temppos)];
//		temppos = parent(temppos);
//	}
//	//�ҵ�����λ��
//	heapArray[temppos] = temp;
//}
//
////��С��ɾ��Ԫ��
//template <class T>
//bool MinHeap<T>::Remove(int pos, T&node){
//	if ((pos < 0) || (pos >= CurrentSize))
//		return false;
//	T temp = heapArray[pos];
//	heapArray[pos] = heapArray[--CurrentSize];
//	if (heapArray[parent(pos)] > heapArray[pos])
//		SiftUp(pos);//����ɸ
//	else
//		SiftDown(pos);//����ɸ
//	node = temp;
//	return true;
//}
//
//template<class T>
//void MinHeap<T>::BuildHeap(void)
//{
//	//��������ɸѡ����
//	for (int i = CurrentSize / 2 - 1; i >= 0; i--)
//	{
//		SiftDown(i);
//	}
//}
//
////����в�����Ԫ��newMode
//template<class T>
//bool MinHeap<T>::Insert(const T& newMode)
//{
//	if (CurrentSize == MaxSize)//���Ѿ�����
//		return false;
//	heapArray[CurrentSize] = newMode;
//	SiftUp(CurrentSize);//���ϵ���
//	CurrentSize++;
//}
//
//
//int main(void)
//{
//	char str[2][3] = { {'a','b','c'},{'d','e','f'} };
//	return 0;
//}
