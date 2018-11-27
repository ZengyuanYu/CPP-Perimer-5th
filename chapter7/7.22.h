#ifndef PERSON
#define PERSON
#include<iostream>
#include<string>

class Person
{
	//��Ԫ����
	friend std::istream &read(std::istream &is, Person& new_person);
public:
	//���캯��
	Person() = default;
	Person(std::string &name, std::string &address) :name(name), address(address) {}
	const std::string isName() { return name; }
	Person(std::istream &is) { read(is, *this); }
	//��Ա����
	Person& Norm_upper();
	Person& display();
private:
	std::string name = "zhangsan";
	std::string address = "beijing";
};
//��Ա����
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
//��Ԫ����
std::istream &read(std::istream &is, Person& new_person)
{
	is >> new_person.name >> new_person.address;
	return is;
}

#endif
