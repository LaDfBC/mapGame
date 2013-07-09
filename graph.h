/* Programmer: George Mausshardt
 * 
 * Purpose: Header File for a graph implementation
 * File: graph.h
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "templates.h"

template <class T>
class Graph
{
  public:
	  Graph();
	  Graph(const Graph<T>& input_graph);
	  ~Graph()
	  
	  Graph<T>& operator=(const Graph<T>& input_graph);
	  nsize size(){ return m_size; }
  private:
	  nsize m_size;
	  Graph_Node m_root;
	  
	  copy(const Graph<T> input_graph);
};

#include "graph.hpp"
#endif /*GRAPH_H_*/
