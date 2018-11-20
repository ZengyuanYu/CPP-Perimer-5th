//#include<string>
//#include<iostream>
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::string;
//using std::getline;
//
//int main()
//{
//	string s("asasdhjsahd,dsa.das.das!");
//	decltype(s.size()) i = 0,j= 0, k = 0;
//	for (auto &c : s)
//		if (ispunct(c))
//			++i;
//	string s_out((s.size()-i), 'n');
//	while (k < s.size()) 
//	{
//		if (ispunct(s[k]))
//			k++;
//		else
//		{
//			s_out[j] = s[k];
//			k++;
//			j++;
//		}
//	}
//	cout << "the remove punct is " << s_out << endl;
//	return 0;
//}