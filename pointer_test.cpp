int main(void)
{

	int i = 0;
	int *p = &i;
	int **pp = (&p);
	cout << &i << endl;//����i�ĵ�ַ
	cout << p << endl;//ָ��pָ�����i�ĵ�ַ
	cout << *p << endl;//ָ��pָ�����i�ĵ�ַ��Ӧ��ֵ
	cout << &p << endl;//ָ��p����ĵ�ַ
	cout << pp << endl;//ָ��ppָ��ָ��p�ĵ�ַ
	cout << *pp << endl;//ָ��ppָ��ָ��p�ĵ�ַ��Ӧ��ֵ��������i�ĵ�ַ
	cout << &pp << endl;//ָ��pp����ĵ�ַ
	return 0;
}
