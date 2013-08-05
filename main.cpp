#include "list.h"
#include "graph.h"
#include <iostream>

#include <stdlib.h>

using std::cout;
using std::endl;

int main()
{
	List<short> myList(20);
	myList.append(21);
	myList.append(22);

	myList.insert(50, 0);
	myList.append(23);
	myList.removeAtIndex(3);
	
	Graph<short> myGraph;
	myGraph.m_data.append(myList);
	cout << myGraph.m_data << endl;
	return 0;
}

