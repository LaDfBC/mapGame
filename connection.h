/*Programmer: George Mausshardt
* File: connection.h
* Generated on: Thursday September 12, 2013
*/

#ifndef CONNECTION_H
#define CONNECTION_H

#include "list.h"
#include <string>

using std::string;

class Connection
{
  public:
	Connection(){ weight = 1.0; }
	  
    float weight;
    List<string> statuses;
    long connecting_vertex;
};

#endif //CONNECTION_H