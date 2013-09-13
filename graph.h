/* Programmer: George Mausshardt
 * 
 * Purpose: Header File for a graph implementation
 * File: graph.h
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "templates.h"
#include "vertex.h"

using std::endl;
using std::cout;

template <class T>
class Graph
{
  public:
	  Graph();
	  ~Graph();
	  
	  Graph<T>& operator=(const Graph<T>& input_graph);
	  nsize size(){ return m_size; }

	  template <class U>
	  friend ostream& operator<<(ostream& out, const Graph<U>& calling_graph)
	  {
		  for(int i = 0; i < calling_graph.m_size; i++)
		  {
			  out << calling_graph.m_data[i].id << ": " << endl;//calling_graph.m_data[i].connections << endl;
		  }
		  return out;
	  }

	  void remove(long index);
	  void insert(long id, List<long> connections);
	  void attach_directed(long id, long end_id);
	  void attach_undirected(long id, long end_id); // Attches/Detaches directed and undirected graph vertices
	  void detach(long id, long end_id);
	  void detach_both(long id, long end_id);
	  
	  void clear();

  private:
	  nsize m_size;
	  List<Vertex> m_data;
	  
	  void copy(const Graph<T> input_graph);
};

#include "graph.hpp"
#endif /*GRAPH_H_*/
