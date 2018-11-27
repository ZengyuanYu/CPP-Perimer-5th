//#include"Person.h"
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::string;
//
//
//int main()
//{
//	Person total_person;
//	if (cin >> total_person.name >> total_person.address)
//	{
//		Person trans;
//		while (cin >> trans.name >> trans.address)
//		{
//			if (total_person.isName() != trans.isName())
//			{
//				total_person.Norm_upper();
//				total_person.display();
//			}
//			else
//			{
//				total_person.display();
//				total_person = trans;
//			}
//		}
//		total_person.display();
//	}
//	else
//	{
//		cout << "no data" << endl;
//		return -1;
//	}
//	return 0;
//}