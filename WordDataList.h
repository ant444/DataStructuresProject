// File: WordDataList.h
// Container of WordData objects. 
// Printing can be iterative or recursive. 

    /*! \file WordDataList.h
    *   \brief This is the WordDataList header file. It handles the container of WordData objects, and its printing mechanisms.
    */
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
//  Filename: WordDataList.h
//
//  Purpose: Container of WordData objects.
//  doing their prints as well
//
//
////////////////////////////////////////////////////////////////////////////



#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;
    /*! \class WordDataList
    *   \brief This class is used for the implementation of the object array subclass.
    *   It includes the prints and the constructor for the WordDataList.
    */

class WordDataList : public WordList {
public:

       	/*!
        *    \fn WordDataList
        *    \brief This function creates an empty WordDataList.
        *
        *   Requires:   Nothing
        *
        *   This constructs an empty WordDataList It has freed nodes and
        *   is ready for usage/implementation.
        *
        *   \param N/A
        *   \return N/A
        */
	WordDataList();

        // Put a string of strings into the list object
        /*!
        *    \fn parseIntoList
        *    \brief This function puts a string into the WordDataLIst object
        *
        *   Requires:   ifstream inf - valid user input file
        *
        *   The parseIntoList function uses the user's input file and goes through
        *   the file, checking if it doesn't have a match, and creates a temporary
        *   word and places it into the WordDataList.
        *
        *   \param ifstream &inf - user's input file import/export
        *   \return N/A
        */
	virtual void parseIntoList(ifstream &inf);

        // Print the data iteratively
        /*!
        *    \fn printIteratively
        *    \brief This function prints the WordDataList in an iterative manner.
        *
        *   The printIteratively function simply prints out the
        *   WordDataList
        *
        *   \param N/A
        *   \return N/A
        */
	virtual void printIteratively();
  
  	// Print the data recursively
        /*!
        *    \fn printRecursively
        *    \brief This function prints the WordDataList in a recursive manner.
        *
        *   Requires: Nothing
        *
        *   The printRecursively function simply prints out the WordDataList via
        *   the use of a helper function called printRecursivelyHelper
        *
        *
        *   \param N/A
        *   \return N/A
        */
	virtual void printRecursively();
  
  	// Print the data recursively with a pointer
        /*!
        *    \fn printPtr
        *    \brief This function prints data recursively with a pointer.
        *
        *   Requires: Nothing
        *
        *   The printPtr function simply prints out the WordDataList via
        *   a pointer, recursively.
        *
        *   \param N/A
        *   \return N/A
        */
	virtual void printPtr();

private:
  WordData TheWords[10];
  int numWords;

        // Look for a match and increment if found
        /*!
        *    \fn incMatch
        *    \brief This function looks for a match and increments the count if it is found.
        *
        *   Requires: temp string
        *
        *   The incMatch function will check if there is a match in the file and increment it
        *   if so. Otherwise it would create a temp WordData and insert it into the list.
        *
        *
        *   \param string temp - a temporary string to check if = to input file import/export
        *   \return True or false - bool
        */
	bool incMatch(string temp);
  
  	// Function to actually perform recursive print
        /*!
        *    \fn printRecursivelyWorker
        *    \brief This function is the worker for the print recursive. It does all the dirty work.
        *
        *   Requires:   int numWords
        *
        *   The printRecursivelyWorker function is the helper function that helps go through the list
        *   and it is called to print the list.
        *
        *
        *   \param int numWords - the number of words import
        *   \return N/A
        */
	void printRecursivelyWorker(int numWords);

        // Function to actually perform recursive print using pointer
        /*!
        *    \fn printPtrWorker
        *    \brief This function performs the recursive print using the ptr.
        *
        *   Requires: The number of words
        *
        *   This function is the worker function to print the ptr recursively.
        *   The other function calls this one.
        *
        *
        *   \param int numWords - the number of words import/export
        *   \return N/A
        */
	void printPtrWorker(int numWords);


};
  
#endif



