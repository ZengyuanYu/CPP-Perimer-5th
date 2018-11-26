#ifndef SALES_DATA
#define SALES_DATA
#include<iostream>
#include<string>

struct Sales_data
{
	std::string bookNo;
	unsigned unit_sold = 0;
	double price = 0.0;
	
	// 返回书编号 book.isbn()
	const std::string isbn() { return bookNo; }
	// 将两本书相加 book(new_book)
	Sales_data& combine(const Sales_data& new_book)
	{
		unit_sold += new_book.unit_sold;
		price += new_book.price;
		return *this;
	}
	// 输出 
	//const void print(Sales_data& book)
	//{
	//	std::cout << book.bookNo << " " << book.unit_sold << " "
	//		<< book.price << std::endl;
	//}

	Sales_data& display()
	{
		std::cout << this->bookNo << " " << this->unit_sold << " "
			<< this->price << std::endl;
		//std::cout << "hhh" << std::endl;
		return *this;
	}
};

#endif