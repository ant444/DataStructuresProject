//File: WordCList.h
// Container of WordCList
// Printing can be iterative or recursive
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
//  Filename: WordCList.h
//
//  Purpose: This is the header file for WordCList. It holds all of the
//  functions that are utilized by a WordCList in the cpp file.
//
////////////////////////////////////////////////////////////////////////////

/*!     \file WordCList.h
*       \brief This is the header file for WordCList. It holds all of the
*       functions that are utilized by a WordCList in the cpp file.
*
*/
#ifndef WORDCLIST_H
#define WORDCLIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include "CLinkedList.h"

using namespace std;

class WordCList : public WordList {
/*! \class WordCList
*   \brief This class holds and controls every implementation that uses a WordCList.
*   This class implements several functions, both public and private.
*
*/
public:

    /*!
    *   \fn WordCList
    *   \brief This function creates an empty WordCList
    *
    *   Requires:  Nothing
    *
    *   This constructs an empty WordCList. It has freed nodes and
    *   is ready for usage/ implementation.
    *
    *   \param N/A
    *   \return N/A
    *
    */
    WordCList();

    //Put a string of strings into the CList object
    /*!
    *   \fn parseIntoList
    *   \brief This function puts a string of strings into the CList object
    *
    *   Requires:   ifstream inf - valid user input file
    *
    *   The parseIntoList function uses the user's input file and goes through
    *   the file, checking if it doesn't have a match, and creates a temporary
    *   word and places it into the CList.
    *
    *   \param ifstream &inf - user's input file
    *   \return N/A
    */
    virtual void parseIntoList(ifstream &inf);

    //print the data iteratively
    /*!
    *   \fn printIteratively
    *   \brief This function prints the WordCList in an iterative manner.
    *
    *   Requires:   Nothing
    *
    *   The printIteratively function simply prints out the WordCList via the usage
    *   of built in functions via CLinkedList.h
    *
    *   \param N/A
    *   return N/A
    */
    virtual void printIteratively();

    //print the data recursively
    /*!
    *   \fn printRecursively
    *   \brief This function prints the WordCList in a recursive manner.
    *
    *   Requires: Nothing
    *
    *   The printRecursively function simply prints out the WordCList via the usage
    *   of a helper function called printRecursivelyWorker
    *
    *   \param N/A
    *   \return N/A
    */
    virtual void printRecursively();


private:
    CLinkedList<WordData> TheWords;

    //Look for a match and increment if found
    /*!
    *   \fn incMatch
    *   \brief This function looks for a match and increments the count if it's found
    *
    *   Requires: temp string
    *
    *   The incMatch function will check if there is a match in the file and within the CList
    *   and if so, it would increment the counter. Otherwise it would create tempword and insert it
    *   into the list
    *
    *   \param string temp - a temporary string to check if = to input file stream
    *   \return True or false - bool
    */
    bool incMatch(string temp);

    //Function to actually perform recursive print
    /*!
    *   \fn printRecursivelyWorker
    *   \brief This function is the worker for the print recursive. It does all of the work to get it to print.
    *
    *   Requires: iterator JimBob
    *
    *   The printRecursivelyWorker function is the helper function that helps iterate through the list
    *   and is called to print the function to print it.
    *
    *   \param CListItr<WordData> JimBob - iterator to step through
    *   \returns N/A
    */
    void printRecursivelyWorker(CListItr<WordData> JimBob);


};

#endif
