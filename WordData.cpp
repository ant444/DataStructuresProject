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
//  Filename: WordData.cpp
//
//  Purpose:    This file holds all the sets and gets and their functionalities
//              for WordData.
//
//
////////////////////////////////////////////////////////////////////////////

/*! \file WordData.cpp
*   \brief This file holds all the sets and gets and their functionalities for
*   for WordData.
*
*/





#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

WordData::WordData(string wrd, int cnt)
{
        setWordData(wrd, cnt);
}

void WordData::setWord(string wrd)
{
        word = wrd;
}

void WordData::setCount(int cnt)
{
        count = cnt;
}

void WordData::setWordData(string wrd, int cnt)
{
        setWord(wrd);
        setCount(cnt);
}
string WordData::getWord() const
{
        return(word);
}

int WordData::getCount() const
{
        return(count);
}

void WordData::incCount(int inc)
{
        count+=inc;
}

ostream &operator<<(ostream& output, const WordData &words)
{
  output<<words.getWord()<<"\t\t"<<words.getCount();
  return output;
}

bool WordData::operator==(const WordData &right) const
{
    return(getWord()==right.getWord());
}

bool WordData::operator>(const WordData &right) const
{
    return(getWord()>right.getWord());
}

bool WordData::operator!=(const WordData &right) const
{
    return(getWord()!=right.getWord());
}




