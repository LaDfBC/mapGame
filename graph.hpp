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
void Graph<T>::insert(long id, List<long> connections = List<long>())
{
	//Set up the vertex
	Vertex new_vertex;
	new_vertex.id = id;
	
	//Tie the connections together. Connections are assumed to be directed in this case
	for(int i = 0; i < connections.size(); i++)
	{
		//Connect the first way
		Connection new_connection;
		new_connection.connecting_vertex = connections[i];
		new_vertex.connections.append(new_connection);
		
		//Connect it the other way as well
		new_connection.connecting_vertex = id;
		m_data[ connections[i] ].connections.append(new_connection);
	}
	
	m_data.append(new_vertex);
}

template <class T>
void Graph<T>::remove(long id)
{
	int index = -1;
	for(int i = 0; i < m_size; i++)
	{
		if(m_data[i].id == index)
		{
			index = i;
		}
	}
	
	//That id does not exist! Just return.
	if(index == -1)
	{
		return;
	}
	
	//Eliminate the vertex
	m_data.removeAtIndex(index);
	
	//Eliminate references to the vertex
	for(int i = 0; i < m_size; i++)
	{
		for(int j = 0; j < m_data[i].connections.size(); j++)
		{
			if(m_data[i].connections[j].connecting_vertex == id)
			{
				m_data[i].connections.removeAtIndex(j);
				break;
			}
		}
	}
	
	return;
}

template <class T>
void Graph<T>::clear()
{
	long list_size = m_data.size();
	m_data.clear();
}