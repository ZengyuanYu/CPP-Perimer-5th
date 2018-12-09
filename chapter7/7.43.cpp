#include<iostream>
#include<string>

using std::cin;
using std::cout;

class NoDefault
{
public:
	NoDefault(int val);
};


class C
{
	friend NoDefault;
public:
	//NoDefault item;
	////¹¹Ôìº¯Êý
	C() :item(0) {};
	//C(NoDefault item) : item(item) {};
private:
	NoDefault item;

};


int main()
{
	
	return 0;
}