//Programmer: George Maussahardt
//File: vertex.h
//Generated on: Sunday August 25, 2013

#include <iostream>
#include "templates.h"
#include "vertex.h"
#include <string.h>
using std::cout;
using std::endl;

struct Connection
{
	Connection(long input_end_vertex, double input_weight=1.0)
	{
		end_vertex = input_end_vertex;
		weight = input_weight;
	}

	long getVertex()
	{
		return end_vertex;
	}

	List<string> statuses;
	double weight;
	long end_vertex;
};