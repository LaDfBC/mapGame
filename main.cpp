#include "list.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using std::cout;
using std::endl;

int main()
{
	List<short> myList(20);
	myList.append(21);
	myList.append(21);
	myList.append(21);
	
	List<short> secondList = myList;
	cout << secondList << endl;
	myList.clear();
	cout << "size: " << myList.size() << endl;
	return 0;
}

