#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	vector<int> nums = {1,2,3};
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		//cout << *it << " ";
		cout << pow(*it, 2) << " ";
		*it = pow(*it, 2);
		cout << *it << " ";
		
	}
	return 0;
}