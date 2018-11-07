//#include<iostream>
//
//
//
////int main()
////{
////	int val1 = 0, val2 = 0;
////	std::cin  >> val1 >> val2;
////	std::cout << "两数之和是：" << val1 + val2 << std::endl;
////
////	return 0;
////}
//
//// 1.3 
///*
//ashdjashd 
///**/
////int main()
////{
////	std::cout << "Hello, World!" << std::endl;
////	int val1 = 0, val2 = 0;
////	std::cin >> val1 >> val2;
////	std::cout << "数" << val1 << "数" << val2 << "相乘为" << val1*val2 << std::endl;
////
////	return 0;
////}
//
//// 1.4
////int main()
////{
////	int sum = 0, val = 1;
////	while (val <= 10)
////	{
////		sum += val;
////		++val;
////	}
////	std::cout << "1-10之和为：" << sum << std::endl;
////	return 0;
////}
////1.10
////int main()
////{
////	int val1, val2, tmp;
////	std::cin >> val1 >> val2;
////	if (val1 > val2)
////	{
////		tmp = val2 + 1;
////		
////		while (tmp < val1)
////		{
////			std::cout << tmp;
////			++tmp;
////		}
////	}
////	else
////	{
////		tmp = val1 + 1;
////		while (tmp < val2)
////		{
////			/*++tmp;*/
////			std::cout << tmp++;
////		}
////	}
////	std::cout << std::endl;
////	return 0;
////}
////1.16
////int main()
////{
////	int sum = 0, val;
////	while (std::cin >> val)
////	{
////		sum += val;
////	}
////	std::cout << sum << std::endl;
////	return 0;
////}
//
//int main()
//{
//	//currVal正在统计得值 val读取得新值
//	int currVal, val;
//	if (std::cin >> currVal) 
//	{
//		int cnt = 1;
//		while (std::cin >> val)
//		{
//			if (val == currVal)
//			{
//				++cnt;
//			}
//			else
//			{
//				std::cout << currVal << "出现" << cnt << "次" << std::endl;
//				currVal = val;
//				cnt = 1;
//			}
//		}
//		std::cout << currVal << "出现" << cnt << "次" << std::endl;
//	}
//	return 0;
//}

//1.21
//#include"Sales_item.h"
//
//
//int main()
//{
//	//Sales_item book;
//
//	////std::ofstream outfile("outfile");
//	////book = infile;
//	///*std::cin >> book;
//	//std::cout << book << std::endl;*/
//	//while (std::cin >> book)
//	//	std::cout << book << std::endl;
//
//	Sales_item book1, book2;
//	std::cin >> book1 >> book2;
//	if (book1.isbn() == book2.isbn())
//	{
//		std::cout << book1 + book2 << std::endl;
//		return 0;
//	}
//	else
//	{
//		std::cout << "二者ISBN不相同" << std::endl;
//		return -1;
//	}
//		
//}

// 1.22
//#include"Sales_item.h"
//
//
//int main()
//{
//	Sales_item total_book;
//	int count;
//	if (std::cin >> total_book)
//	{
//		Sales_item book;
//		while (std::cin >> book)
//		{
//			if (total_book.isbn() == book.isbn())
//			{
//				total_book += book;
//			}
//			else
//			{
//				std::cout << total_book << std::endl;
//				total_book = book;
//			}	
//		}
//		std::cout << total_book << std::endl;
//	}
//	else
//	{
//		std::cout << "no data" << std::endl;
//		return -1;
//	}
//
//	return 0;
//}
#include<iostream>
#include"Sales_item.h"

int main()
{
	//currBook为正在统计的书 valBook为新读进来的书
	Sales_item currBook, valBook;
	if (std::cin >> currBook)
	{
		int cnt = 1;
		while (std::cin >> valBook)
		{
			if (valBook.isbn() == currBook.isbn())
			{
				cnt += 1;
			}
			else
			{
				std::cout << currBook << "有" << cnt << "条记录" << std::endl;
				currBook = valBook;
				cnt = 1;
			}
		}
		std::cout << currBook << "有" << cnt << "条记录" << std::endl;
	}
	else
	{
		std::cout << "no data" << std::endl;
		return -1;
	}
	return 0;
}