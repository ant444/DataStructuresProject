//////////////////////////////////////////////////////////
//
//      Author:             Anthony Nelson
//
//      Major:              Computer Science
//
//      Creation Date:      March 2, 2023
//
//      Due Date:           March 12, 2023
//
//      Course:             CSC237 Data Structures
//
//      Professor Name:     Dr. Spiegel
//
//      Assignment:         Project 2
//
//      Filename:           CLinkedList.h
//
//      Purpose:            This file is the heart and soul
//                          of project 2, it gives the cpp
//                          everything it needs to be fully
//                          functional.
//
//////////////////////////////////////////////////////////

/*!     \file CLinkedList.h
*       \brief This file provides everything for the WordCList program to be functional.
*       Its functions are used in WordCList.cpp
*/

#ifndef _CLinkedList_
#define _CLinkedList_
#include <assert.h>
#include <iostream>
#include "Node.h"

using namespace std;

//Prototyping template classes
template <typename eltType> class CLinkedList;
/*! \class CLinkedList
*   \brief  This class holds and control every implementation that uses a CLinkedList.
*   This class implements several functions, most of which are public.
*
*/



template <typename eltType> class CListItr;
/*! \class CListItr
*   \brief This class is the iterator, which controls movement in the list.
*   This class implements the counting aspect of this project for the most part.
*/


template <typename eltType> class CLinkedList
{
    public:
	//Construct empty CLinkedList
        /*!
        *   \fn CLinkedList
        *   \brief This function creates an empty CLinkedList
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: Nothing
        *
        *   This constructs an empty CLinkedList. It has freed nodes
        *   and is ready for usage/ implementation.
        *
        *   \param N/A
        *   \return N/A
        */
	CLinkedList();


        //Construct deep copy of another CLinkedList
        /*!
        *   \fn CLinkedList deep copy
        *   \brief This function creates a  copy of the CLinkedList.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires:  CLinkedList&
        *
        *   The  copy goes node by node to get every piece of information
        *   possible to copy the list.
        *
        *
        *   \param CLinkedList - itself
        *   \return itself?
        */
	CLinkedList(CLinkedList&);

        //destroys CLinkedList
        /*!
        *   \fn ~CLinkedList
        *   \brief This is the destructor, it destroys the CLinkedList.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: Nothing
        *
        *   This destructor goes node by node getting rid of everything
        *   completetly.
        *
        *   \param N/A
        *   \return N/A
        */
	~CLinkedList();

        //Assign another CLinkedList to this CLinkedList; deep copy
        /*!
        *   \fn operator=
        *   \brief This operator assignes another CLinkedList to this CLinkedList.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: const CLinkedList& - the list that will be copied
        *
        *   This operator does the deep copy. It goes eltType by eltType copying 1
        *   by 1, node by node.
        *
        *   /param a constant version of itself
        *   /return a copied CLinkedList?
        */
	CLinkedList& operator=(const CLinkedList&);

        // Is CLinkedList empty?
        /*!
        *   \fn empty
        *   \brief This function finds whether the CLinkedList is empty or not.
        *
        *   Member Function Classification: Inspector
        *
        *   Requires: Nothing
        *
        *   The empty function is used when trying to determine if the Circular Linked
        *   List is empty or not. It is a bool, so its outcome will always be either
        *   true or false.
        *
        *   \param No parameters for this function.
        *
        *   \return bool - true or false whether it is empty
        */
	bool empty();


        //Ordered insert
        /*!
        *   \fn orderedInsert
        *   \brief This function will insert the eltType into the list in an ordered manner.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: eltType - the thing being inserted to CLinkedList
        *
        *   The orderedInsert function will first check if the list is empty and if so, make
        *   a new node for the list with eltType x. It checks if the eltType is in the middle
        *   or at the end of the list, and inserts it accordingly. This is done with some pointer
        *   manipulation.
        *
        *   \param eltType - the data of the item in which is being inserted
        *   \return N/A
        */
	void orderedInsert(eltType);




        //Remove
        /*!
        *   \fn remove
        *   \brief This function will remove an eltType from the CLinkedList.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: eltType - the data we want to remove
        *
        *   The remove function will first check if the list is empty, and if so,
        *   return. Otherwise, it will look to see if the eltType that we want to
        *   remove is in the list, and if so, remove it.
        *
        *   \param eltType - the data of the item in which we want to remove
        *   \return N/A
        */
	void remove(eltType);



        //backwardPrint
        /*!
        *   \fn backwardPrint
        *   \brief This function calls the backwardPrintHelper to get the eltType
        *
        *   Member Function Classification: Inspector
        *
        *   Requires: Nothing
        *
        *   The backwardPrint function simply makes the pointer equal the first
        *   item in the list and it calls the backwardPrintHelper which does the
        *   rest of the work.
        *
        *   \param N/A
        *   \return N/A
        */
	void backwardPrint();



        //backwardPrintHelper
        /*!
        *   \fn backwardPrintHelper
        *   \brief This function outputs the last element in the array and calls itself.
        *
        *   Member Function Classification: Inspector
        *
        *   Requires: eltType *p - iterator
        *
        *   The backwardPrintHelper function checks if the pointer p is at the last node
        *   of the list, and if so, it outputs it. Otherwise, it will print the first node
        *   in the list, because that is all that would be left.
        *
        *   \param <eltType> *p - the pointer to p, from the backwardPrint function
        *   \return N/A
        */
	void backwardPrintHelper(Node<eltType> *p);


    private:
	//CLinkedList ptr
        Node<eltType>* last;

        //Get copy of deep node
        //copy
	/*!
        *   \fn copy
        *   \brief This function gets the deep copy of the Node.
        *
        *   Member Function Classification: Faciliator
        *
        *   Requires: eltType *
        *
        *   The copy function copies everything Node by Node to get the
        *   deep copy. I am not 100% sure if this one was done correctly.
        *
        *   \param eltType * - the pointer we use for copying
        *   \return N/A
        */
	void copy(const CLinkedList<eltType> &);


        //destroy
        // Frees node of CLinkedList
        /*!
        *   \fn destroy
        *   \brief This function recursively destroys all nodes in CLinkedList.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: eltType *
        *
        *   The destroy function simply goes node by node and recursively deletes
        *   all of the nodes inside. It frees up the nodes in CLinkedList.
        *
        *   \param eltType * - pointer to an eltType so it knows what to delete.
        *   \return N/A
        */
	void destroy(Node<eltType> *);


    //we need this to be a friend in order to use CListItr
    friend class CListItr<eltType>;
};



//ostream operator<<
/*!
*   \fn ostream operator<<
*   \brief This operator is necessary for outputting the CLinkedList.
*
*   The operator<< is used when outputting the CLinkedList, meaning that
*   it is detrimental for outputting. We also utilize it for the forward
*   print of the CLinkedList.
*
*   \param ostream &os - output stream
    \param eltType &l - the referenced eltType
    \return eltType
*/
template <typename eltType>
    ostream& operator<<(ostream &os,const CLinkedList<eltType> &l);


//Now we will create the CListItr
template <typename eltType> class CListItr
{
    public:
	//construct CListitr

        /*!
        *   \fn CListItr
        *   \brief This creates an iterator with a pointer called curr
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: const CLinkedList &l - the CLinkedList being traversed
        *
        *   This has a constant reference to the CLinkedList which will be traversed
        *
        *   \param const CLinkedList<eltType> &l
        *   \return N/A
        *
        */
	CListItr(const CLinkedList<eltType> &l);

        //set curr to point at the first node of itr
        /*!
        *   \fn start
        *   \brief This function points at the first node of the iterator
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: Nothing
        *
        *   The start function simply gets the first node by setting the
        *   current pointer to point at the first node.
        *
        *   \param eltType l - the iterator's first node
        *   \return N/A
        */
	void start();

        //Is curr null?
        /*!
        *   \fn more
        *   \brief This function checks if the current node is NULL.
        *
        *   Member Function Classification: Inspector
        *
        *   Requires: Nothing
        *
        *
        *   This boolean based function checks to see if there is any more
        *   nodes to be accounted for. Once there is no more, it would return.
        *
        *   \param N/A
        *   \return bool
        */
	bool more();

        //go to curr-> next
        /*!
        *   \fn next
        *   \brief This function goes to the next node(curr->next).
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: Nothing
        *
        *   The next function simply goes to the next node by implementing
        *   a "->next". It is utilized many times to help iterate through nodes.
        *
        *   \param N/A
        *   \return N/A
        */
	void next();

        //get the value out of curr's node
        /*!
        *   \fn value
        *   \brief This function gets the value out of curr's node
        *
        *
        *   The eltType value function simply grabs the value of the node
        *   and stores it as an eltType.
        *
        *   \param N/A
        *   \return N/A
        */
	eltType value();

        //isFirstNode
        /*!
        *   \fn isFirstNode
        *   \brief This function checks to see if the node is currently in the first place.
        *
        *   Member Function Classification: Inspector
        *
        *   Requires: Nothing
        *
        *   The isFirstNode function simply checks to see if it is the first node, by seeing if
        *   it is in the spot last->next.
        *
        *   \param N/A
        *   \return bool
        */
	bool isFirstNode();


        //isLastNode
        /*!
        *   \fn isLastNode
        *   \brief This function checks to see if the current node is the last node.
        *
        *   Member Function Classification: Inspector
        *
        *   Requires: Nothing
        *
        *   The isLastNode function simply checks to see if it is in the last node, by
        *   seeing if it is in last.
        *
        *   \param N/A
        *   \return bool
        */
	bool isLastNode();

        //pre-increment
        /*!
        *   \fn operator++ pre-increment
        *   \brief This is the pre-increment ++ operator.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: Nothing
        *
        *   The operator++ pre-increment checks if the current item is null and if so
        *   it moves to the next iteratively and returns the item.
        *
        *   \param N/A
        *   \return eltType - int
        */

  	CListItr<eltType> operator++(); //pre-increment

        //post-increment
        /*!
        *   \fn operator++ post-increment
        *   \brief This is the post-increment operator++ function.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: int
        *
        *   The operator++ post increment uses a constant reference to the CListItr
        *   and has similar functionality to the pre-increment function.
        *
        *   \param int
        *   \return eltType - int
        */
	const CListItr<eltType>operator++(int); //post-increment


        //operator* const
        /*!
        *   \fn operator* const
        *   \brief The * const operator is used for dereference to iterator(ex:*this).
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: Nothing
        *
        *   This operator returns the data in the current node.
        *
        *   \param N/A
        *   \return eltType
        */
	eltType operator*()const;

        //operator*
        /*!
        *   \fn operator*
        *   \brief The *operator is used for obtaining reference to the iterator.
        *
        *   Member Function Classification: Mutator
        *
        *   Requires: Nothing
        *
        *   This operator has similar functionality to the const, but it is simply
        *   not a const. It returns the data in thr current node.
        *
        *   \param N/A
        *   \return eltType
        */
	eltType operator*();

    private:
	const CLinkedList<eltType> &listInItr;
        Node<eltType> *curr;
};


// Construct empty CLinkedList
//might need an end to it other than head? Not sure
template <typename eltType> CLinkedList<eltType>::CLinkedList() : last(NULL)
{}


//copy constructor
//copy() does the deep copy
template <typename eltType>
    CLinkedList<eltType>::CLinkedList(CLinkedList<eltType> &cl)
{
    if(!cl.empty())
    {
     	copy(cl);
    }
}
//Frees up all nodes
template <typename eltType> CLinkedList<eltType>::~CLinkedList()
{
    if(!empty())
    {
     	destroy(last->next);
    }
}
//assignment operator: copy() does deep copy
template <typename eltType> CLinkedList<eltType>
    &CLinkedList<eltType>::operator =(const CLinkedList<eltType>& cl)
{   if(this != &cl)
    {
     	if(!empty())
        {
            destroy(last->next);
        }
	copy(cl);
    }
    return *this;
}


//orderedInsert

template <typename eltType>
        void CLinkedList<eltType>::orderedInsert(eltType x)
{   if(empty())
    {
     	assert(last=new Node<eltType>(x,last));
        last->next = last;                        //if empty then make the new node and point to itself
    }
    else if(x > last->data)
    {
     	Node<eltType>* ptr=new Node<eltType>(x,last->next); //if inserted num is > last, then put this one at last
        last->next = ptr;
        last = last->next;
    }
    else
    {
     	Node<eltType>* p = last->next;
        Node<eltType>* trailp = last;
        while(x > p->data)
        {
            trailp = p;     //insert in middle
            p = p->next;
        }
    trailp->next= new Node<eltType>(x,p);
    }

}




//is element in the CLinkedList
//Inline
template <typename eltType> inline bool CLinkedList<eltType>::empty()
{return (last == NULL);}




template <typename eltType>
    void CLinkedList<eltType>::remove(eltType x)
{
    Node<eltType>* p = last->next;
    Node<eltType>* trailp = last;
    bool isFound = false;


    if(empty())
    {
     	return; // if it's empty return
    }


    if(p == last)
    {
      delete p;
        last = NULL;    //if p is last then set delete it and return
        return;
    }

    while( p != last && isFound == false)
    {
     	if( x == p->data)
        {                               //this if is for if it's found in middle of list
            isFound = true;
            trailp->next = p->next;     //if x is found then delete p and hook pointers back up
            delete p;
            p = trailp->next;
        }
	p = p->next;
        trailp = trailp->next; // increment them/ keep moving
        if(p == last && x == p->data)
        {
            isFound = true;
            last = trailp;
            last->next = p->next;	//if it's found at end of list, configure pointers then delete p
            delete p;
            p = trailp->next;
        }
    }

}



template <typename eltType> void CLinkedList<eltType>::backwardPrint()
{   Node<eltType>* p = last->next;
    if(empty())
    {
     	return;
    }
    backwardPrintHelper(p); //call helper
}

template <typename eltType> void CLinkedList<eltType>::backwardPrintHelper(Node <eltType> *p)
{
    if(empty())
    {
     	return;
    }
      if(p == last)
    {
     	cout << p->data << " "; //output last
        return;
    }
    else
    {
        backwardPrintHelper(p->next); //find last
     	cout << p->data << " "; //output it
    }
}



template <typename eltType> void CLinkedList<eltType>::destroy(Node<eltType> *l)
{
    if (last == NULL || l == last)
    {
        delete l;
        return;
    }
    Node<eltType>* p = l->next;
    delete l;
    destroy(p); //recursive call
}




//Deep copy. copy the source list l, one node at a time
template <typename eltType>
    void CLinkedList<eltType>::copy(const CLinkedList<eltType> &l)
{   CListItr<eltType> lt(l);
    for(lt.start(); !lt.isLastNode();lt++)
    {
     	orderedInsert(*lt);
    }
    orderedInsert(*lt);
}

//outputs the CLinkedList, using itr
template <typename eltType>
    ostream& operator<<(ostream &os,const CLinkedList<eltType> &l)
{   CListItr<eltType>   lt(l);
    for(lt.start(); !lt.isLastNode(); lt++)
    {
        	os << *lt << endl;//*operator for .value
    }
    os << *lt << " ";
    return os;
}








///////////////////////////////////////
//
//      CListItr implementations
//
//
///////////////////////////////////////

//construct list iterator
//  consists of reference to CLinkedList obj
//  consists of a ptr to actual list, at the head
template <typename eltType>
CListItr<eltType>::CListItr(const CLinkedList<eltType> &l): listInItr(l),curr(l.last->next)
{}

//set curr to point at itr's head
template <typename eltType> void CListItr<eltType>::start(void)
{curr = listInItr.last->next;}

//is curr at end of list 
//might need additional condition for if it is at beginning of list since circular
template <typename eltType> bool CListItr<eltType>::more(void)
{return curr != NULL;}

//Move curr to next node
template <typename eltType> void CListItr<eltType>::next(void)
{assert( curr != NULL );
 curr = curr->next;
}

//return data in curr's node. regardless of assert(), this
// function shouldn't be called until making sure more() returns true
template <typename eltType> eltType CListItr<eltType>::value(void)
{assert( curr != NULL );
 return curr->data;
}

template <typename eltType> bool CListItr<eltType>::isLastNode(void)
{return curr == listInItr.last;}

template<typename eltType> bool CListItr<eltType>::isFirstNode(void)
{return curr == listInItr.last->next;}

template <typename eltType> eltType
    CListItr<eltType>::operator*() const
{return curr->data;}

template <typename eltType> eltType
    CListItr<eltType>::operator*()
{return curr->data;}


template <typename eltType> CListItr<eltType> //preincrement
    CListItr<eltType>::operator++()
{
    if( curr != NULL )//if there is still something in the list
    {
     	curr = listInItr.last->next;
    }
    return *this;
}

template <typename eltType> const CListItr<eltType>
    CListItr<eltType>::operator++(int) //post-increment
{
    CListItr<eltType> p = *this;
    if( curr != NULL )
    {
     	curr = curr->next;
    }
    return p;
}
#endif


