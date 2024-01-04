// File: WordDataList.cpp
// Container of WordData objects 
//   Implementations of member functions including inherited pure virtual fns.
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
//  Filename: WordDataList.cpp
//
//  Purpose: Implementations of member functions including inherited pure
//  virtual fns.
//
////////////////////////////////////////////////////////////////////////////

/*! \file WordDataList.cpp
*   \brief Implementations of member functions including inherited pure virtual
*   functions.
*/





#include <sstream>
#include <iostream>
#include "WordDataList.h"

using namespace std;

  WordDataList::WordDataList()
  { numWords=0; } //constructs it

  bool WordDataList::incMatch(string temp)
  { for(int i=0; i<numWords; i++) { //when theres still more words
      if (temp==TheWords[i].getWord()) {    //get it, and inc count
        TheWords[i].incCount(); // inc count if match
        return true;
      }
    }  
    return false; //otherwise return false
  }

  void WordDataList::parseIntoList(ifstream &inf)
  { string temp; // temp var
    while (inf >> temp) //while reading into temp
      if (!incMatch(temp) && numWords < 10) { //max count is 10
          TheWords[numWords].setWord(temp);   //set word
          TheWords[numWords++].setCount(1);   //set count
      }
  }

  // Print the data iteratively
  void WordDataList::printIteratively()
  //  void printObjectArrayIterator(WordData TheWords[], int numWords)
  {
    cout<<"--------------------------"<<endl;
    cout<<"|Object  Array  Iterative|"<<endl;
    cout<<"|Word         Occurences |"<<endl;  
    cout<<"--------------------------"<<endl;
    for(int i=0; i<numWords; i++)
    cout<<" "<<TheWords[i]<<endl;
  }

  
  // Print the data recursively
  void WordDataList::printRecursivelyWorker(int numWords)
  //void printObjectArrayRecursive(WordData TheWords[], int numWords)
  {if (numWords==1) {
      cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Recursive|"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      cout<<" "<<TheWords[numWords-1]<<endl;
      return;
    }
    printRecursivelyWorker(numWords-1);
    cout<<" "<<TheWords[numWords-1]<<endl;
  }

  // Call worker function to print the data recursively
  void WordDataList::printRecursively()
  {  printRecursivelyWorker(numWords); }


  // Print the data recursively with a pointer
  void WordDataList::printPtrWorker(int numWords)
  //void printObjectArrayPointerRecursive(WordData* TheWords, int numWords)
  {if (!numWords)
    { cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Pointer  |"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      return;
    }
    printPtrWorker(numWords-1);
    cout<<" "<<*(TheWords+(numWords-1))<<endl;
  }

  // Call worker function to print the data recursively
  void WordDataList::printPtr()
  { printPtrWorker(numWords); }



