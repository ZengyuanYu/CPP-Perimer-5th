//#include"Sales_data.h"
//
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::string;
//
//int main()
//{
//	Sales_data total;
//	if (cin >> total.bookNo >> total.unit_sold >> total.price)
//	{
//		Sales_data trans;
//		while (cin >> trans.bookNo >> trans.unit_sold >> trans.price)
//		{
//			if (total.isbn() == trans.isbn())
//			{
//				total.combine(trans);
//			}
//			else
//			{
//				total.display();
//				
//				total = trans;
//			}
//		}
//		total.display();
//		//print(total);
//	}
//	else
//	{
//		cout << "No data" << endl;
//		return - 1;
//	}
//	return 0;
//}
