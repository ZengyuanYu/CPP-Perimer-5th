#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int nums[6] = {1,2,3,4,5,7};
	int i = 0, j = 0;
	vector<int> nums1;
	for (int i = 0; i < 6; i++)  nums1.push_back(nums[i]);
	for (auto i : nums1)
		cout << i << endl;
	while (i < nums1.size()-1)
	{
		cout << nums1[i] + nums1[i + 1] << " ";
		i++;
	}
	cout << endl;
	while (j < int(nums1.size() / 2))
	{
		cout << nums1[j] + nums1[nums1.size()- 1 - j] << " ";
		j++;
	}
	return 0;
}