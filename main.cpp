#include "list.h"
#include "graph.h"
#include <iostream>

#include <stdlib.h>

using std::cout;
using std::endl;

int main()
{	
	Graph<short> myGraph;
	myGraph.insert(0);
	myGraph.insert(1);
	cout << myGraph << endl;
	return 0;
}
