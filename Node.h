// File: Node.h
// Singly-linked list node definition/implementation (also good for circular)
//Author: Anthony Nelson Given by Dr. Spiegel
// Due Date: 3/12/23
//purpose: To help implement CLInkedList
/*! \file Node.h
*   \brief This is the node definition/implementation.
*   Works for the CLinkedList.
*
*/

/*! \class Node
*   \brief This class is used for the implementation of the Circular Linked List.
*
*/

#ifndef NODE_H
#define NODE_H

// Need to prototype template classes if they are to be friends
template <typename eltType> class CLinkedList;
template <typename eltType> class CListItr;

template <typename eltType> class Node
{	private:
        Node(eltType info, Node* link = NULL ) :
                           data(info), next(link) 
        {};
	eltType data;
        Node *next;
        friend class CLinkedList<eltType>;
        friend class CListItr<eltType>;
};

#endif

