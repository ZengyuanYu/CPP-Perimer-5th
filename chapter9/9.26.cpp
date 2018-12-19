#include<iostream>
#include<vector>
#include<list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	list<int> list_nums;
	vector<int> vec_nums;
	for (int i = 0; i < (sizeof(ia) / sizeof(ia[0])); ++i)
	{
		list_nums.push_back(ia[i]);
		vec_nums.push_back(ia[i]);
	}
	auto ite1 = list_nums.begin();
	while (ite1 != list_nums.end())
	{
		if (*ite1 % 2 == 1)
			ite1 = list_nums.erase(ite1);
		else
			++ite1;
	}
	auto ite2 = vec_nums.begin();
	while (ite2 != vec_nums.end())
	{
		if (*ite2 % 2 == 0)
			ite2 = vec_nums.erase(ite2);
		else
			++ite2;
	}
	for (auto ptr : list_nums)
		cout << ptr << " ";
	cout << endl;
	for (auto ptr1 : vec_nums)
		cout << ptr1 << " ";
		return 0;
}