#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::unique;
using std::stable_sort;

void print(vector<string> &words)
{
	for (auto i : words)
		cout << i << " ";
	cout << endl;
}

bool isShoter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	print(words);
	auto end_unique = unique(words.begin(), words.end());
	print(words);
	words.erase(end_unique, words.end());
	print(words);
}


int main()
{
	vector<string> list;
	string word;
	while (cin >> word)
	{
		if (word == "end")
			break;
		list.push_back(word);
	}
	print(list);
	elimDups(list);
	stable_sort(list.begin(), list.end(), isShoter);
	print(list);
	return 0;
}