#ifndef SALES_DATA
#define SALES_DATA
#include<iostream>
#include<string>

class Sales_data
{
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, Sales_data &item);
	friend Sales_data add(const Sales_data &book1, const Sales_data &book2);
public:
	// ���캯��
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), unit_sold(n), price(p) {}	
	Sales_data(std::istream &is) { read(is, *this); }
	
	// �������� book.isbn()
	std::string isbn() { return bookNo; }
	// ����������� book(new_book)
	Sales_data& combine(const Sales_data& new_book);
	// ��ʾ���
	Sales_data& display();
private:
	// ��Ա����
	std::string bookNo;
	unsigned unit_sold = 0;
	double price = 0.0;
};

//��Ա����
Sales_data& Sales_data::combine(const Sales_data& new_book)
{
	unit_sold += new_book.unit_sold;
	price += new_book.price;
	return *this;
}

Sales_data& Sales_data::display()
{
	std::cout << this->bookNo << " " << this->unit_sold << " "
		<< this->price << std::endl;
	//std::cout << "hhh" << std::endl;
	return *this;
}

//��Ԫ����
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

#endif