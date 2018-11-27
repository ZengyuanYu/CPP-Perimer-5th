#include"7.22.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
	Person total_person;
	if (read(std::cin, total_person))
	{
		Person trans;
		while (read(std::cin, trans))
		{
			if (total_person.isName() != trans.isName())
			{
				total_person.Norm_upper();
				total_person.display();
			}
			else
			{
				total_person.display();
				total_person = trans;
			}
		}
		total_person.display();
	}
	else
	{
		cout << "no data" << endl;
		return -1;
	}
	return 0;
}