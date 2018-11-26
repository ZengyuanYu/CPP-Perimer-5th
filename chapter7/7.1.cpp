//#include<iostream>
//#include<string>
//
//using std::cin;
//using std::cout;
//using std::endl;
//using std::string;
//
//struct Sales_data
//{
//	string bookNo;
//	unsigned unit_sold = 0;
//	double price = 0.0;
//};
//
//int main()
//{
//	Sales_data total;
//	if (cin >> total.bookNo >> total.unit_sold >> total.price)
//	{
//		Sales_data trans;
//		while (cin >> trans.bookNo >> trans.unit_sold >> trans.price)
//		{
//			if (total.bookNo == trans.bookNo)
//			{
//				//++cout << "此时的值：" << total.price << " " << trans.price;
//				total.price += trans.price;
//				total.unit_sold += trans.unit_sold;		
//			}
//			else
//			{
//				cout << total.bookNo << " " << total.unit_sold << " "
//					<< total.price << endl;
//				total = trans;
//			}
//		}
//		cout << total.bookNo << " " << total.unit_sold << " "
//			<< total.price << endl;
//	}
//	else
//	{
//		cout << "No data" << endl;
//		return - 1;
//	}
//	return 0;
//}
////#include <iostream>
////#include <string>
////using std::cin; using std::cout; using std::endl; using std::string;
////
////struct Sales_data
////{
////	string bookNo;
////	unsigned units_sold = 0;
////	double revenue = 0.0;
////};
////
////int main()
////{
////	Sales_data total;
////	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
////	{
////		Sales_data trans;
////		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
////		{
////			if (total.bookNo == trans.bookNo)
////			{
////				total.units_sold += trans.units_sold;
////				total.revenue += trans.revenue;
////			}
////			else
////			{
////				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
////				total = trans;
////			}
////		}
////		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
////	}
////	else
////	{
////		std::cerr << "No data?!" << std::endl;
////		return -1;
////	}
////	return 0;
////}