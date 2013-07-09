#ifndef LIST_NODE_H
#define LIST_NODE_H

template <class T>
struct ListNode
{
	ListNode* p;
	ListNode* n;
	T* node_data;
};

#endif /*LIST_NODE_H*/
