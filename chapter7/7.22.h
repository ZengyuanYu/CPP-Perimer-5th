#ifndef PERSON
#define PERSON
#include<iostream>
#include<string>

class Person
{
	//友元函数
	friend std::istream &read(std::istream &is, Person& new_person);
public:
	//构造函数
	Person() = default;
	Person(std::string &name, std::string &address) :name(name), address(address) {}
	const std::string isName() { return name; }
	Person(std::istream &is) { read(is, *this); }
	//成员函数
	Person& Norm_upper();
	Person& display();
private:
	std::string name = "zhangsan";
	std::string address = "beijing";
};
//成员函数
Person& Person::Norm_upper()
{
	for (auto& c : this->name) c = toupper(c);
	for (auto& c : this->address) c = toupper(c);
	return *this;
}
Person& Person::display()
{
	std::cout << this->name << " " << this->address << std::endl;
	//std::cout << "hhh" << std::endl;
	return *this;
}
//友元函数
std::istream &read(std::istream &is, Person& new_person)
{
	is >> new_person.name >> new_person.address;
	return is;
}

#endif
