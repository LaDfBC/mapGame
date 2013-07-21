/* Programmer: George Mausshardt
 * 
 * Purpose: Implementation File for a graph implementation
 * File: graph.hpp
 */


template <class T>
Graph<T>::Graph()
{
	m_size = 0;
}

template <class T>
Graph<T>::Graph(const nsize input_size)
{
	m_size = input_size;
}

template <class T>
Graph<T>::~Graph()
{
	m_size = 0;
	m_data.clear();
}

template <class T>
Graph<T>& Graph<T>::operator=(const Graph<T>& input_graph)
{
	Graph<T> ret_graph;
	ret_graph.copy(input_graph);
	return ret_graph;
}

template <class T>
void Graph<T>::copy(const Graph<T> input_graph)
{
	//We need a list implementation

}