#include<iostream>
#include<iterator>

using namespace std;

int main()
{
	int a[] = {1,2,3,4,5};
	int b[] = {1,2,3,4};
	int *pabeg = begin(a);
	int *paend = end(a);
	int *pbbeg = begin(b);
	int *pbend = end(b);
	if ((paend - pabeg) != (pbend - pbbeg))
	{
		cout << "���Ȳ����" << endl;
		return 0;
	}
	for (; pabeg < paend; ++pabeg)
	{
		if (*pabeg != *pbbeg) cout << "��ֵ�����" << endl;
		++pbbeg;
		
	}
	//if (pabeg == paend) cout << "eq";
	//else cout << "no";
	return 0;
}