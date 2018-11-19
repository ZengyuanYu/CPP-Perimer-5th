#include<string>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	/*string concate;
	for (string buffer; cin >> buffer; concate += buffer);
	cout << concate;*/
	string concate;
	for (string buffer; cin >> buffer; concate += (concate.empty() ? "":"") + buffer);
	cout << concate << endl;
	return 0;
}