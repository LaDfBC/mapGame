/*
* Programmer: George Mausshardt
* 
* File: list.h
* Purpose: Implementation file for the List class
*/

template <class T>
List<T>::List()
{
	m_root = NULL;
	m_size = 0;
}

template <class T>
List<T>::List(T const input_value)
{
	m_root = new ListNode<T>;
	m_root -> p = NULL;
	m_root -> n = NULL;
	
	m_root -> node_data = new T(input_value);
	
	cout << *(m_root -> node_data) << endl; 
	
	m_size = 1;
}

template <class T>
List<T>::~List()
{
	if (m_size == 0)
	{
		return;
	}
	
	else if (m_size == 1)
	{
		delete m_root;
		m_size = 0;
		return;
	}
		
	else
	{
		clear();
	}
}


template <class T>
void List<T>::copy(const List<T>& right_hand_side)
{
	//if rhs == this...returns
	clear();
	
	return;
}


template <class T>
List<T>& List<T>::operator=(const List<T>& right_hand_side)
{
	copy();
	return *this;
}

template <class T>
T& List<T>::operator[](nsize const data_location) const
{
	if (data_location >= m_size)
	{
		//throw out_of-range error.
	}
	
	ListNode<T>* temp_node = m_root;
	for(long i = 0; i < data_location; i++)
	{
		temp_node = temp_node -> n; 
	}
	
	return *(temp_node -> node_data);
}

template <class T>
T& List<T>::operator[](nsize const data_location)
{
	if (data_location >= m_size)
	{
		//throw out_of-range error.
	}
	
	ListNode<T>* temp_node = m_root;
	for(long i = 0; i < data_location; i++)
	{
		temp_node = temp_node -> n; 
	}
	
	return *(temp_node -> node_data);
}

template <class T>
ListNode<T>* List<T>::getNode(nsize const data_location) const
{
	if (data_location >= m_size)
		{
			//throw out_of-range error.
		}
		
		ListNode<T>* temp_node = m_root;
		for(long i = 0; i < data_location; i++)
		{
			temp_node = temp_node -> n; 
		}
		
		return temp_node;
}

//template <class T>
//bool List<T>::operator!=(const List<T>& right_hand_side) const
//{
//	return !(*this == right_hand_side);
//}
//
//template <class T>
//bool List<T>::operator==(const List<T>& right_hand_side) const
//{
//	if (m_size != right_hand_side.m_size)
//		return false;
//	
//	else
//	{
//		//Ready for some fun tomorrow?
//	}
//	return true;
//}

template <class T>
void List<T>::append(nsize inputData)
{
	ListNode<T>* lastNode = getNode(m_size - 1);
	lastNode -> n = new ListNode<T>;
	
	lastNode -> n -> node_data = new T(inputData);
	
	lastNode -> n -> p = lastNode;
	lastNode -> n -> n = NULL;
	
	m_size++;
	return;
}


template <class T>
void List<T>::removeAtIndex(nsize inputIndex)
{
	//Deleting m_root
	if(inputIndex == 0)
	{
		//Size 1
		if (m_root -> n == NULL)
		{
			delete m_root -> node_data;
			delete m_root;
			m_size = 0;
			m_root = NULL;
			
			return;
		}
		else
		{
			ListNode<T>* tempNode;
			tempNode = m_root -> n;
			tempNode -> p = NULL;
			m_root -> n = NULL;
			
			delete m_root -> node_data;
			delete m_root;
			m_root = tempNode;
			m_size--;
			
			return;
		}
	}
}

template <class T>
void List<T>::clear()
{
	while (m_size > 0)
	{
		removeAtIndex(0);
	}
	return;
}

template <class T>
nsize List<T>::size() const
{
	return m_size;
}