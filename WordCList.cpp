/////////////////////////////////////////////////////////////////////////////
//
//  Author: Anthony Nelson
//
//  Major: Computer Science
//
//  Creation Date: March 28, 2023
//
//  Due Date: April 5, 2023
//
//  Course: CSC237 Data Structures
//
//  Professor Name: Dr. Spiegel
//
//  Assignment: Project 3
//
//  Filename: WordCList.cpp
//
//  Purpose: brief This file implements the member functions used via a WordCList.
//       WordCList is utilized via project 2's CLinkedList header file.
//       This will cover the implementation of every function needed for the 
//       WordCList. (A Circular Linked List).
//
//
//
////////////////////////////////////////////////////////////////////////////


#include <sstream>
#include <iostream>
#include "WordCList.h"
#include "CLinkedList.h"
using namespace std;

    WordCList::WordCList()
    {}

    /*!
    *   \fn WordCList::incMatch
    *   \brief This function checks if the temp string matches anything in the CList and will increment the counter ifso.
    *
    *   Requires: string temp
    *
    *   The incMatch function via a WordCList checks if there is a match in the
    *   CList, then will remove the existing one and increment the counter.
    *   Otherwise, it makes a tempWrd and will use that to help access the existing one.
    *
    *   \param string temp - the temporary word in string
    *   \return true or false - depending on if the word is found/inserted into CList
    *
    */
    bool WordCList::incMatch(string temp)
    {
     	if(TheWords.empty()) //if the list is empty
        {
            return false;	//return false
        }
	CListItr<WordData>  TheWordsItr(TheWords);  //make iterator to work through list
        for(TheWordsItr.start(); !TheWordsItr.isLastNode(); TheWordsItr++) {
            if(temp == (*TheWordsItr).getWord()) //if the temp word = the word in the list
            {
             	//remove it then increment the counter
               WordData tmpWrd(temp, (*TheWordsItr).getCount()+1);
               TheWords.remove(tmpWrd); //get rid of the existing one
               TheWords.orderedInsert(tmpWrd); //insert the temp word into TheWords
               return true; //because it was found
            }
	}
	if(temp == (*TheWordsItr).getWord()) // if temp word = the word in list
        {
                 //remove it then increment the counter
            WordData tmpWrd(temp, (*TheWordsItr).getCount()+1); //create tempword w/ count as 1
            TheWords.remove(tmpWrd); //remove the existing one
            TheWords.orderedInsert(tmpWrd); //insert the temp word
            return true; //because it was found
        }
	else
	{
            return false; // default as false
        }
    }

    /*!
    *
    *   \fn WordCList::parseIntoList
    *   \brief This function inserts a tempWord in the list if it is not found via match function.
    *
    *   Requires: ifstream &inf
    *
    *   The parseIntoList function simply checks to see if the current word
    *   being read in is already in the list, and if not, then it creates
    *   a temp word in the list and will add it into the list(parse it into
    *   the CList.
    *
    *   \param ifstream &inf - input file stream
    *   \return N/A
    */
    void WordCList::parseIntoList(ifstream &inf)
    {   string temp;
       while (inf >> temp) //while reading the text file
        if (!incMatch(temp))    //if match isn't found
        {
            WordData tmpWord(temp, 1);      //create a tempWord with count of 1
            TheWords.orderedInsert(tmpWord);    //insert it into the list
        }
    }

//print data iteratively

    /*!
    *   \fn WordCList::printIteratively
    *   \brief This function will print the WordCList iteratively.
    *
    *   Requires: Nothing
    *
    *   The printIteratively function prints the WordCList through the
    *   use of a CList iterator. This will output the list in an ordered
    *   manner, via the utilization of the orderedInsert in the CLinkedList
    *   header file.
    *
    *   \param N/A
    *   \return N/A
    *
    */

    void WordCList::printIteratively()
    {
     	//header
        cout << "----------------------------" << endl;
        cout << "| Circular List Iterative |" << endl;
        cout << "| Word:        Occurences:|" << endl;
        cout << "----------------------------" << endl;
        cout << TheWords << endl; //outputs the list iteratively
    }


//print data recursively
    /*!
    *   \fn WordCList::printRecursiveWorker
    *   \brief This function uses an iterator to print the WordCList.
    *
    *   Requires:       Iterator
    *
    *   The printRecursivelyWorker function uses an iterator to print
    *   out the CList until it meets the end of the list(last node)
    *   and will then output the last node and return.
    *
    *   \param CList<WordData> JimBob - iterator for the list(to help move through list)
    *   \return N/A
    */
    void WordCList::printRecursivelyWorker(CListItr<WordData> JimBob)
    {
     	if(JimBob.isLastNode())   { //if at last node
            cout << " " << *JimBob << endl; //output the lastnode
            return;                         //end the output
        }
	cout << " " << *JimBob << endl; // output the word and count
        JimBob++;                       // keep going through
        printRecursivelyWorker(JimBob); //calls output

    }

//calls worker function to print recursively

    /*!
    *   \fn WordCList::printRecursively
    *   \brief This function prints the header for CListRecursive and calls the worker function.
    *
    *   Requires:   Nothing
    *
    *   The printRecursively function simply prints the header of the
    *   CList Recursive and it calls the worker function to print the
    *   entire list.
    *
    *   \param N/A
    *   \return N/A
    *
    */

    void WordCList::printRecursively()
    {
     	CListItr<WordData> JimBob(TheWords); //makes iterator to go through list
        //header
        cout << "----------------------------" << endl;
        cout << "| Circular List Recursive |" << endl;
        cout << "| Word:        Occurences:|" << endl;
        cout << "----------------------------" << endl;

        printRecursivelyWorker(JimBob); //calls the worker for it
     }



