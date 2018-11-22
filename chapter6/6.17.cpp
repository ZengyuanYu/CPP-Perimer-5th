#include<iostream>
#include<string>

using namespace std;

void isUp(const string& s1)
{
	bool flag = false;
	auto i = s1.size();
	for (decltype(i) j = 0; j != s1.size(); ++j)
	{
		if (isupper(s1[j])) flag = true;
	}
	if (flag) cout << "有大写字母";
	else cout << "没有大写字母";
	//cout << "No";
}

string changeLower(string s)
{
	auto i = s.size();
	for (decltype(i) j = 0; j != s.size(); ++j)
	{
		if (isupper(s[j]))
		{
			cout << tolower(s[j]) << endl;
			s[j] = tolower(s[j]);
			cout << s[j] << endl;
		}
	}
	return s;
}
int main()
{
	const string& s1 = "Aashjadhjjj";
	isUp(s1);
	string s2 = "sahjashjHashjH";
	s2 = changeLower(s2);
	cout << s2 << endl;
	return 0;
}

