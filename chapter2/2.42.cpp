#include"Sales_data.h"
#include<iostream>

int main()
{
	Sales_data item1, item2;
	std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue;
	std::cin >> item2.bookNo >> item2.units_sold >> item2.revenue;
	//std::cout << item1.bookNo << std::endl;
	if (item1.bookNo == item2.bookNo) 
	{
		double all_price, avg_price;
		all_price = (item1.units_sold * item1.revenue + 
					 item2.units_sold * item2.revenue);
		avg_price = all_price / (item1.units_sold + item2.units_sold);
		std::cout << "�����۶�Ϊ��" << all_price << "ƽ���ۼ�Ϊ:" << avg_price << std::endl;
	}
	else 
	{
		std::cout << "�����鲻��ͬһ��" << std::endl;
	}
	return 0;
}