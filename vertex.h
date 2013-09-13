//Programmer: George Mausshardt
//File: vertex.h
//Generated on: Thursday September 12, 2013

#ifndef VERTEX_H
#define VERTEX_H

#include "connection.h"


class Vertex
{
  public:
	  long id;
	  List<Connection> connections;
};

#endif // VERTEX_H