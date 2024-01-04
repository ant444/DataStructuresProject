// File: WordSTLSeq.h
// Container of WordData obj
// printing them too
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
//  Filename: WordSTLSeq.h
//
//  Purpose: Container of WordData object, specifically a vector.
//  Prints as well.
//
//
////////////////////////////////////////////////////////////////////////////


#ifndef WORDSTLSEQ_H
#define WORDSTLSEQ_H

#include <string>
#include "WordList.h"
#include "WordData.h"
#include <vector>

/*! \file WordSTLSeq.h
*   \brief This is the header file for WordSTLSeq. It holds all of the
*   functions that are utilized by a WordSTLSeq in the WordSTLSeq.cpp file.
*/

using namespace std;

/*! \class WordSTLSeq
*   \brief This class holds and controls every implementation that uses a WordSTLSeq.
*   This class implements several functions, both public and private.
*/

class WordSTLSeq : public WordList  {
public:
/*!
*    \fn WordSTLSeq
*    \brief This constructs an empty WordSTLSeq. It has freed nodes and
*       is ready for usage/ implementation.
*
*   Requires:   Nothing
*
*   This constructs an empty WordSTLSeq with freed nodes.
*
*   \param N/A
*   \return N/A
*/

    WordSTLSeq();

    //Put a string of strings into the list object
/*!
*    \fn parseIntoList
*    \brief This function puts a string of strings into the vector
*
*   Requires: ifstream inf  - user input
*
*   The parseIntoList function uses the user's input file and goes thru
*   the file, checks for a match and if not creates a temp vect and places
*   it into the vector
*
*   \param  ifstream&inf - user input file import/export
*   \return N/A
*/
    virtual void parseIntoList(ifstream &inf);

    //Print the data iteratively
/*!
*    \fn  printIteratively
*    \brief This function prints the vector in an iterative manner.
*
*   Requires: Nothing
*
*   The printIteratively function simply prints out the vector by implementing
*   some statements in the cpp file.
*
*
*   \param N/A
*   \return N/A
*/
    virtual void printIteratively();

    //Print the data recursively
/*!
*    \fn printRecursively
*    \brief This function prints out the vector in a recursive manner with the help of a helper function.
*
*   Requires: Nothing
*
*   The printRecursively function iterates through and prints the vector in a
*   recursive way through the usage of a helper function.
*
*
*   \param N/A
*   \return N/A
*/

    virtual void printRecursively();

private:
    vector<WordData> myVect;
    int numWords;


    //Looks for match and increment if found
     /*!
     *   \fn incMatch
     *   \brief This function looks for a match and increments the count if it is found
     *
     *   Requires: temp string
     *
     *   The incMatch function will check if there is a match in the file
     *   and if so, it would increment the counter. Otherwise it would put it
     *   into the vector
     *
     *   \param string temp - a temporary string to check if = to input file> import/export
     *   \return True or false - bool
     */
    bool incMatch(string temp);

    // function to actually perform recursive print
     //Function to actually perform recursive print
     /*!
     *   \fn printRecursivelyWorker
     *   \brief This function is the worker for the print recursive. It does the bulk by iterating through the vector
     *
     *   Requires: iterator it
     *
     *   The printRecursivelyWorker function is the helper function that does the work
     *   and is called to print the output recursively.
     *
     *   \param iterator it - iterator to step through
     *   \returns N/A
     */

    void printRecursivelyWorker(vector<WordData>:: iterator it);

};

#endif



