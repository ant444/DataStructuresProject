// File: WordList.h
// Abstract base class for containers of word data
// Known subclasses:
//      WordDataList
/////////////////////////////////////////////////////////////////////////////
//
//  Author: Anthony Nelson & Dr. Spiegel
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
//  Filename: WordList.h
//
//  Purpose: This is the header for WordList. It holds all of the
//           WordList functions that are utilized in the cpp file.
//
//
//
////////////////////////////////////////////////////////////////////////////


/*!     \file WordList.h
*       \brief This is the header for WordList. It holds all of the
*       WordList functions that are utilized in the cpp file.
*/


#ifndef WORDLIST_H
#define WORDLIST_H

#include <fstream>
#include <string>

using namespace std;

/*! \class WordList
*   \brief This class holds and controls every implementation that uses a WordList.
*   It implements several functions, both public and private.
*/

class WordList {
public:

// Place the line of text into the data structure
/*!
*    \fn parseIntoList
*    \brief This function places the line of text into the data structures.
*
*   Requires: ifstream inf - input file
*
*   The parseIntoList function places the line of text into the data structures.
*
*
*
*   \param ifstream &inf - user's input file import/export
*   \return N/A
*/
  virtual void parseIntoList(ifstream &inf)=0;

  // Print the data iteratively
/*!
*    \fn printIteratively
*    \brief This function will print the data structure iteratively
*
*   Requires: Nothing
*
*   The printIteratively function simply prints out the data structure in an
*   iterative manner.
*
*
*   \param N/A
*   \return N/A
*/
  virtual void printIteratively()=0;
  
  // Print the data recursively
/*!
*    \fn  printRecursively
*    \brief This function will print out the data structure recursively.
*
*   Requires: Nothing
*
*   The printRecursively function simply prints out the data structure in a recursive manner.
*   It utilizes a helper function to do so.
*
*
*   \param N/A
*   \return N/A
*/
  virtual void printRecursively()=0;
  
  // Print the data recursively with a pointer
/*!
*    \fn printPtr
*    \brief This function prints out the object array via a pointer.
*
*   Requires: Nothing
*
*   The printPtr function prints the data recuursively with the use
*   of a pointer.
*
*
*   \param N/A
*   \return N/A
*/
  virtual void printPtr() {}   // not pure virtual; why?
    
};
  
#endif



