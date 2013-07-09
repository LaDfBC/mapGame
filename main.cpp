#include "list.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	List<short> myList(20);
	myList.append(21);
	myList.append(21);
	myList.append(21);
	cout << myList[0] << endl;
	myList.clear();
	cout << "size: " << myList.size() << endl;
	return 0;
}

