//Implementations of member functions including pure virtual functions
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
//  Filename: WordSTLSeq.cpp
//
//  Purpose:    This file implements the member functions used via a WordSTLSeq,
//              more specifically a vector.
//
//
////////////////////////////////////////////////////////////////////////////

/*!     \file WordSTLSeq.cpp
*       \brief This file implements the member functions used via a WordSTLSeq, more specifically a vector.
*
*/



#include <sstream>
#include <iostream>
#include "WordSTLSeq.h"
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

    // initailize wordVector

    WordSTLSeq::WordSTLSeq()
    {}

    bool WordSTLSeq::incMatch(string temp)
    {
     	if(myVect.empty()) //if vector is empty
        {
            WordData tmpvct(temp, 1);   //create a temporary vector w/ temp word and count as 1
            myVect.push_back(tmpvct);   //add it to list
            return true;                //return true, as something was added
        }
	vector<WordData>::iterator it;  //making iterator
        for(it = myVect.begin();it != myVect.end(); it++) //if it has begun, not ended, then increment iterator
        {
            string word = it->getWord();    //get the word
            if(temp == word)                //if temp is =  word
            {
             	it->setCount(it->getCount()+1);     //set the count
                return true;                        //return true
            }
	}
	return false;   //must initially be false
    }

    void WordSTLSeq::parseIntoList(ifstream &inf)
    {
     	//some vars
        int counter = 0;
        string temp;
        WordData* tempWord;
        while(inf >> temp)	//while reading into temp
        {
            if(!incMatch(temp))     //if match isn't found
            {
             	tempWord = new WordData(temp, 1);   //make a tempWord
                myVect.push_back(*tempWord);        //insert it into myVect
                counter++;                          //increment the counter
            }
	}
    }

    void WordSTLSeq::printIteratively()
    {
     	//header
        cout << "----------------------------" << endl;
        cout << "|   STL Vector Iterative   |" << endl;
        cout << "| Word:       Occurences:  |" << endl;
        cout << "----------------------------" << endl;



        //Via C++ website
        //This sorts the vector right before printing it
        sort(myVect.begin(), myVect.end(), [](const WordData a, const WordData b) 
        {
	return a.getWord() < b.getWord();
        });

	for(auto it = myVect.begin(); it != myVect.end(); it++) //increment through if not at the end
        {
            cout << setw(16) << left << it->getWord()  <<  it->getCount()<< endl;  //output the word and the count
        }
    }


    void WordSTLSeq::printRecursivelyWorker(vector<WordData>::iterator it)
    {
     	if(myVect.empty())    { //if empty return
            return;
        }
	if(it == myVect.end()) { //if at the end return
            return;
        }
	else
	{
          //sort used via C++ website
          sort(myVect.begin(), myVect.end(), [](const WordData a, const WordData b) 
          {
          return a.getWord() < b.getWord();
          });
          cout << setw(16) << left << it->getWord()  << it->getCount() << endl;  //outputs one row of the vector
          printRecursivelyWorker(++it); //calls itself to increment
        }
    }


    void WordSTLSeq::printRecursively()
    {
     	//header
        cout << "----------------------------" << endl;
        cout << "|   STL Vector Recursive   |" << endl;
        cout << "| Word:         Occurences:|" << endl;
        cout << "----------------------------" << endl;

        printRecursivelyWorker(myVect.begin()); //calls the worker
    }

