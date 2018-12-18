//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//
//using std::string;
//using std::vector;
//using std::ifstream;
//using std::cout;
//using std::endl;
//
//void ReadFileToVec(const string& filename, vector<string>& vec)
//{
//	ifstream file(filename);
//	if (file)
//	{
//		string buf;
//		while (std::getline(file, buf))
//			vec.push_back(buf);
//	}
//}
//
//void ReadFileWordToVec(const string& filename, vector<string>& vec)
//{
//	ifstream file(filename);
//	if (file)
//	{
//		string word;
//		while(file >> word)
//			vec.push_back(word);
//	}
//}
//int main()
//{
//	vector<string> vec;
//	ReadFileToVec("1.txt", vec);
//	for (const auto &str : vec)
//		cout << str << endl;
//
//	vector<string> vec1;
//	ReadFileWordToVec("1.txt", vec1);
//	for (const auto &str : vec1)
//		cout << str << endl;
//
//	return 0;
//}