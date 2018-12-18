#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<fstream>
#include "ctype.h"

using std::cout;
using std::endl;
using std::cerr;
using std::getline;
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;


struct PersonInfo 
{
	string name;
	vector<string> phones;
};

bool valid(const string& str)
{
	return isdigit(str[0]);
}

string format(const string& str)
{
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
	ifstream ifs("2.txt");
	if (!ifs)
	{
		cerr << "no phone number" << endl;
		return - 1;
	}
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(ifs, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	for (const auto& entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones)
			if (!valid(nums))
				badNums << " " << nums;
			else
				formatted << " " << formatted.str() << endl;
		if (badNums.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error" << entry.name << "invalid number" << badNums.str() << endl;
	}
	return 0;
}