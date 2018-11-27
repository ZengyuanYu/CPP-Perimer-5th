#ifndef SALES_DATA
#define SALES_DATA
#include<iostream>
#include<string>

std::istream &read(std::istream&, Sales_data&);

struct Sales_data
{
	// 成员变量
	std::string bookNo;
	unsigned unit_sold = 0;
	double price = 0.0;
	
	// 构造函数
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) {}
	/*Sales_data(const std::string &s) :bookNo(s), unit_sold(0),
				price(0) {}*/
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s),
				unit_sold(n), price(p){}
	Sales_data(std::istream &is) { read(is, *this); }
	// 返回书编号 book.isbn()
	const std::string isbn() { return bookNo; }
	// 将两本书相加 book(new_book)
	Sales_data& combine(const Sales_data& new_book)
	{
		unit_sold += new_book.unit_sold;
		price += new_book.price;
		return *this;
	}

	Sales_data& display()
	{
		std::cout << this->bookNo << " " << this->unit_sold << " "
			<< this->price << std::endl;
		//std::cout << "hhh" << std::endl;
		return *this;
	}
};
std::istream &read(std::istream &is, Sales_data &item)
{
	//double price = 0.0;
	is >> item.bookNo >> item.unit_sold >> item.price;
	return is;
}
std::ostream &print(std::ostream &os, Sales_data &item)
{
	os << item.bookNo << " " << item.unit_sold << " " << item.price;
	return os;
}
Sales_data add(const Sales_data &book1, const Sales_data &book2)
{
	Sales_data sum = book1;
	sum.combine(book2);
	return sum;
}

// 构造函数
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}
#endif