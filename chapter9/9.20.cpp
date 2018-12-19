//#include<iostream>
//#include<deque>
//#include<list>
//#include<string>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::deque;
//using std::list;
//
//int main()
//{
//	int value;
//	list<int> nums;
//	deque<int> o, q;
//	while (cin >> value)
//	{
//		if (value == -1) break;
//		nums.push_back(value);
//	}
//	for (auto nums_value : nums)
//		if (nums_value % 2 == 0)
//			o.push_back(nums_value);
//		else q.push_back(nums_value);
//	for (auto o_value : o)
//		cout << o_value << endl;
//	for (auto q_value : q)
//		cout << q_value << endl;
//	//cout << o.max_size << q.max_size << endl;
//	/*list<string>::iterator begin = words.begin(), end = words.end();
//	for (; begin != end; ++begin)
//		cout << *(begin) << endl;*/
//	return 0;
//}