/*   Course:         CIS237                                     */
/*   Filename:       app.cpp                                    */
/*   Purpose:        This Example inputs a string and demon-    */
/*                   strates how to store it using a subclass   */
/*                   of an abstract base class that incorporates*/
/*                   virtual functions to enable polymorphism   */
/*                   If a file name is                          */
/*                   input through the command line all of the  */
/*                   options will be done automatically for the */
/*                   first line of the file                     */
/****************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "WordList.h"
#include "WordDataList.h"
#include "WordCList.h"
#include "WordSTLSeq.h"
#include <chrono>
#include <cmath>
// #include "WordData.h"        app only knows about the lists!


/*! \file app.cpp
*   \brief This file is necessary for user input and the project as a whole.
*   The menu implements all of the classes created as well as calculates the time complexity
*   for parsing into the data structure and for their respective print functions.
*/



using namespace std;

void displayMenu();
/*********************************************************************/
/*   Function Name: displayMenu()                                    */
/*                                                                   */
/*   Description: Displays the menu on the screen.                   */
/*********************************************************************/
/*! \fn displayMenu
*   \brief This function displays the menu onto the screen.
*
*   \param N/A
*   \return N/A
*/



void printEverything(ifstream &inf,WordList *TheList);
/*********************************************************************/
/*                                                                   */
/*   Function Name: printEverything                                  */
/*                                                                   */
/*   Description: Takes in a sentence and sends it through every     */
/*                parsing and printing function                      */
/*                                                                   */
/*   Parameters:  string sentence - sent to every function           */
/*                WordDataList TheList - The array of object         */
/*********************************************************************/
/*! \fn printEverything
*   \brief This function takes in a sentence and sends it through every parsing and printing function.
*
*   \param string sentence - sent to every function, WordDataList TheList -  object
*   \return N/A
*/




int frequency_of_primes (int n);
/*! \fn frequency_of_primes
*   \brief This function was pulled via Dr. Spiegel's Microsecond directory and slight modifications were made.
*
*   \param int n - the number used for TC.
*   \return int - the frequency
*/


int actualTimeComplexity();
/*! \fn actualTimeComplexity
*   \brief This is the function that actually does the time complexity and outputs it when called.
*
*   \param N/A
*   \return int - the number in nanoseconds
*/
int main(int argc,char *argv[])
{ ifstream inf;
  WordList *TheList = NULL;
  if(argc>1) //if there was an input on the command line
    {
      inf.open(argv[1]); //try and open the file
      if (inf.fail())       //if the file does not open
        {                    //terminate
          cout<<"Sorry, the file failed to open."<<endl;
          return 0;
        }
      printEverything(inf,TheList);
      return 0;
    }

  char selection;
  string fileName;
  cout<<"Please enter a file name:"<<endl;
  getline(cin,fileName);
  inf.open(fileName.c_str());
  if(inf.fail())
    {
     	cout << "Empty File." << endl;
        return 0;
    }
  // TheList is a pointer to a WordList that is pointed at a WordList subclass
  
  while (true)
    {
      displayMenu();
      cin>>selection;
      switch(selection)
      {
       	case '1':
        case '2':
        case '3':
            TheList = new WordDataList;
            cout << "------------------------------------------------" << endl;
            cout << "Parsing for the Object Array." << endl;
            break;
        case '4':
        case '5':
            TheList = new WordCList;
            cout << "------------------------------------------------" << endl;
            cout << "Parsing for the Circular List." << endl;
            break;
        case '6':
        case '7':
            TheList = new WordSTLSeq;
            cout << "------------------------------------------------" << endl;
            cout << "Parsing for the STL Vector." << endl;
            break;
        case '8':
            cout << "Goodbye.";
            return 0;
      }
      TheList->parseIntoList(inf);
      actualTimeComplexity();
      cout << "------------------------------------------------" << endl;
      switch(selection)
      {
       	//iterative prints
         case '1':
         case '4':
         case '6':
            TheList->printIteratively();
            cout << "------------------------------------------------" << endl;
            cout << "Time Complexity for This Iterative Print" << endl;
            actualTimeComplexity();
            cout << "------------------------------------------------" << endl;
            break;
        //recursive prints
         case '2':
         case '5':
         case '7':
            TheList->printRecursively();
            cout << "------------------------------------------------" << endl;
            cout << "Time Complexity for This Recursive Print" << endl;
            actualTimeComplexity();
            cout << "------------------------------------------------" << endl;
            break;
        //pointer print
         case '3':
            TheList->printPtr();
            cout << "------------------------------------------------" << endl;
            cout << "Time Complexity for Obj Array Pointer Print" << endl;
            actualTimeComplexity();
            cout << "------------------------------------------------" << endl;
            break;
        //exit
         case '8':
            cout << "Goodbye.";
            return 0;
          default:
            cout<<"I cannot understand "<<selection<<".  Try again."<<endl;
            break;
      }
       	inf.clear();
        inf.seekg(0);
    }
  delete TheList;
  return 0;
}

void displayMenu()
{
  cout<<endl;
    //output menu
  cout<<"How do you want to print your sentence elements?"<<endl;
  cout<<"------------------------------------------------"<<endl;
  cout<<"1. Object Array Iterative"<<endl;
  cout<<"2. Object Array Recursive"<<endl;
  cout<<"3. Object Array Pointer Only"<<endl;
  cout<<"4. Circular List Iterator"<<endl;
  cout<<"5. Circular List Iterator Recursive"<<endl;
  cout<<"6. STL Vector Iterative"<<endl;
  cout<<"7. STL Vector Recursive"<<endl;
  cout<<"8. Exit"<<endl;
  cout<<"------------------------------------------------"<<endl;
}

void printEverything(ifstream &inf,WordList *TheList)
{
  ofstream myfile;
  myfile.open("times.txt", ios::app);
  //for obj array
  using namespace std::chrono ;
  TheList=new WordDataList;
  auto begin = high_resolution_clock::now() ;
  TheList->parseIntoList(inf);
  //parsing inro list - object array
  auto end = high_resolution_clock::now() ;
  auto ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;
 
  //obj array print iteratively
  begin = high_resolution_clock::now() ;
  TheList->printIteratively();
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;


  //obj array print recursively
  begin = high_resolution_clock::now() ;
  TheList->printRecursively();
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;


  //obj array printPtr
  begin = high_resolution_clock::now() ;
  TheList->printPtr();
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;



  inf.clear();
  inf.seekg(0);

  //for CList parse
  TheList=new WordCList;
  begin = high_resolution_clock::now() ;
  TheList->parseIntoList(inf);
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;

  //CList iteratively
  begin = high_resolution_clock::now() ;
  TheList->printIteratively();
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;


  //Clist recursively
  begin = high_resolution_clock::now() ;
  TheList->printRecursively();
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;

  inf.clear();
  inf.seekg(0);

  //for vector
  TheList=new WordSTLSeq;
  begin = high_resolution_clock::now() ;
  TheList->parseIntoList(inf);
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;




  begin = high_resolution_clock::now() ;
  TheList->printIteratively();
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;


  begin = high_resolution_clock::now() ;
  TheList->printRecursively();
  end = high_resolution_clock::now() ;
  ticks = duration_cast<microseconds>(end-begin) ;
  myfile << ticks.count() << endl;
  myfile << endl;

 // myfile.close();

}


//via Dr. Spiegel source code
int frequency_of_primes(int n)
{   int freq=n-1;

    for(int i=2;i <=n; ++i)
        for(int j=sqrt(i);j>1; --j)
            if(i%j==0)
            {
             	--freq;
                break;
            }

    return freq;
}

int actualTimeComplexity()
{
    using namespace std::chrono ;


    auto begin = high_resolution_clock::now() ;
    int f = frequency_of_primes(99999);
    auto end = high_resolution_clock::now() ;

    auto ticks = duration_cast<microseconds>(end-begin) ;

    std::cout << "It took me " << ticks.count() <<" microseconds.\n" ;

    return 0;
}


