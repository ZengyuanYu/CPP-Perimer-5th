#include"Chapter6.h"
#include<iostream>
#include<string>

using namespace std;

//��׳�
int fact(int nums)
{
	int sum = 1;
	while (nums > 0)
	{
		sum *= nums--;
	}
	return sum;
}

//�����ֵ
int _abs(int nums)
{
	return nums >= 0 ? nums : -nums;
}