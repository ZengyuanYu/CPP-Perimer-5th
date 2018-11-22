#include"Chapter6.h"
#include<iostream>
#include<string>

using namespace std;

//求阶乘
int fact(int nums)
{
	int sum = 1;
	while (nums > 0)
	{
		sum *= nums--;
	}
	return sum;
}

//求绝对值
int _abs(int nums)
{
	return nums >= 0 ? nums : -nums;
}