//#include<vector>
//#include<iostream>
//#include<list>
//
//using std::cout;
//using std::endl;
//using std::vector;
//using std::list;
//
//bool compare(vector<int> const item1, vector<int> const item2)
//{
//	if (item1 == item2)
//		return true;
//	return false;
//}
//
//void compare(vector<int> const item1, list<int> const item2)
//{
//	vector<int> item3(item2.begin(), item2.end());
//	if (item1 == item3)
//		cout << "二者相等" << endl;
//	else if (item1 > item3)
//		cout << "vector<int>元素大" << endl;
//	else
//		cout << "list<int>元素大" << endl;
//}
//
//int main()
//{
//	vector<int> item1(10);
//	vector<int> item2(10);
//	list<int> item3(12);
//	compare(item1, item3);
//	/*bool flag;
//	flag = compare(item1, item2);
//	if (flag)
//		cout << "二者相等" << endl;
//	else
//		cout << "二者不等" << endl;*/
//	return 0;
//}