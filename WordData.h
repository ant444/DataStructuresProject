/****************************************************************/
/*   Filename:       WordData.h                                 */
/*   Purpose:        The Only Addition i made to this file was  */
/*                   an overloading of the << operator.         */
/****************************************************************/
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
//  Filename: WordData.h
//
//  Purpose: This is the WordData header file. It holds the definition/ implementation.
//
//
//
////////////////////////////////////////////////////////////////////////////


    /*! \file WordData.h
    *   \brief This is the WordData header file. It holds the  definition/ implementation.
    */

#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;



    /*! \class WordData
    *   \brief This class is used for the implementation of every subclass.
    *   Without this class, everything would be broken :0
    *
    */
class WordData {

public:

       	//Constructor
        /*!
        *   \fn WordData
        *   \brief This function creates an empty WordData
        *
        *   Requires: Default string and count
        *
        *   This constructs an empty WordData. It has freed nodes and
        *   is ready for usage/ implementation.
        *
        *   \param string wrd , int cnt export
        *   \return N/A
        *
        */
	WordData(string wrd = "", int cnt = 1);

        //Sets
	/*!
        *    \fn setWord
        *    \brief This function sets the word in the WordData class.
        *
        *   Requires: a string - wrd
        *
        *   The setWord function simply gets the word and sets it based on
        *   whatever word it must be set to
        *
        *   \param  string wrd - word being set/used import/export
        *   \return N/A
        */
	void setWord(string wrd);


        /*!
        *    \fn setCount
        *    \brief This function sets the count in the WordData class.
        *
        *   Requires:   int cnt - the count being set
        *
        *   The setCount function simply gets the count and sets it based on
        *   whatever count it must be set to
        *
        *
        *   \param  int cnt - the count being set import
        *   \return N/A
        */
	void setCount(int cnt);

        //Set Whole WordData Object
        /*!
        *    \fn setWordData
        *    \brief This function sets the WordData in the WordData class.
        *
        *   Requires: string and int - word and count to be set
        *
        *   The setWordData sets the whole WordData object via, it has the same
        *   functionality as setWord and setCount, but it does both at once.
        *
        *
        *   \param  string - word to be set, int - count to be set import
        *   \return N/A
        */
	void setWordData(string,int);

        //Gets

        /*!
        *    \fn getWord
        *    \brief This function gets the word in the WordData class.
        *
        *   Requires: Nothing
        *
        *   The getWord function simply gets the word in the WordData class and
        *   stores it.
        *
        *   \param N/A
        *   \return string- the word that was gotten
        */
	string getWord() const;


        /*!
        *    \fn getCount
        *    \brief This function gets the count in the WordData class.
        *
        *   Requires:   Nothing
        *
        *   The getCount function simply gets the count in the WordData class and
        *   stores it.
        *
        *
        *   \param N/A
        *   \return int - the count
        */
	int getCount() const;

        //Increment
        /*!
        *    \fn incCount
        *    \brief This function increments the count by 1.
        *
        *   Requires: int inc = 1
        *
        *   The incCount function simply increments the count in the WordData class by
        *   1 each time it is used.
        *
        *
        *   \param int inc = 1 import
        *   \return N/A
        */
	void incCount(int inc = 1);

        /*!
        *    \fn operator==
        *    \brief This is the == operator. It checks to see if two things are equal to each other.
        *
        *   Requires:  WordData - two items to be compared
        *
        *   The operator== is a comparator to see if two things are the same.
        *
        *
        *
        *   \param WordData &right - the rightmost item in comparator stmt
        *   \return true or false - it's a bool
        */
	bool operator==(const WordData &right) const;

        /*!
        *    \fn operator>
        *    \brief This operator compares to see if the rightmost thing is less than the leftmost thing.
        *
        *   Requires:   WordData - two items to be compared
        *
        *   The operator> is a comparator to see if the right most thing is < the left most thing.
        *
        *   \param WordData &right - the rightmost item in the comparator stmt
        *   \return true or false - it is a bool
        */
	bool operator>(const WordData &right) const;

        /*!
        *    \fn operator!=
        *    \brief This operator checks to see if something is not equal to something.
        *
        *   Requires:   WordData - item being compared
        *
        *   The operator!= is a comparator to see if the rightmost thing is != to the leftmost thing.
        *
        *   \param WordData &right - the rightmost item being compared
        *   \return true or false - it is a bool
        */

	bool operator!=(const WordData &right) const;



private:

        //variables
        string word;
        int count;


};

        /*!
        *    \fn operator<<
        *    \brief The stream insertion operator.
        *
        *   Requires: WordData and outstream& output
        *
        *   The operator<< is an ostream operator that outputs the WordData being used
        *
        *   \param ostream& output, WordData words
        *   \return an ostream
        */

ostream &operator<<(ostream& output, const WordData &words);

#endif




