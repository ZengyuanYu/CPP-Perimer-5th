//#include<iostream>
//#include<fstream>
//#include<vector>
//#include<string>
//#include<sstream>
//
//using std::string;
//using std::vector;
//using std::ifstream;
//using std::istringstream;
//using std::endl;
//using std::cout;
//
//void ReadLineToVec(const string& filename, vector<string>& vec)
//{
//	ifstream file(filename);
//	if (file)
//	{
//		string line;
//		while (std::getline(file, line))
//			vec.push_back(line);
//	}
//	for (const auto &s : vec)
//	{
//		istringstream iss(s);
//		string word;
//		while (iss >> word)
//			cout << word << endl;
//	}
//}
//
//int main()
//{
//	vector<string> vec;
//	ReadLineToVec("1.txt", vec);
//	return 0;
//}