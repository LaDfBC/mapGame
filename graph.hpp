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
	m_data = input_graph.m_data;
}

template <class T>
void Graph<T>::remove(long index)
{
	long index_size = m_data[index].size();

	for(long i = 0; i < index_size; i++)
	{
		end_vertex = m_data[index][i].getVertex();
		m_data[end_vertex].remove(index);
	}

	//Pop everything off. When it's done the list is empty.
	for(long j = 0; j < index_size; j++)
	{
		m_data[index].remove(0);
	}
}

template <class T>
void Graph<T>::clear()
{
	long list_size = m_data.size();
	m_data.clear();
}