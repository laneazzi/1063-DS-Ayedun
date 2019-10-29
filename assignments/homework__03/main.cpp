/** Olanrewaju  Ayedun
Data Structures: Dr. Griffin
October 15th 2019
Homework 3
Description: List based Stack that holds an animal type
*/

#include "ListStack.h" // include  stack definition
#include <fstream>        
#include <iostream>
#include <string>

using namespace std;

int main() {
	ifstream fin("animals.txt"); // input file of animal info                   
	Animal *a;                   // animal pointer used to hold popped animals

	// Variable Declarations
	string name;
	double weight;
	double scary;
    
    // List based stack object
	ListStack LS;

	// While animals in the file
	while (!fin.eof()) {
		fin >> name >> weight >> scary;      // load animal with file data
		a = new Animal(name, weight, scary); // allocate memory for an animal           
		LS.Push(a);                          // push animal onto the stack      
	}

	LS.Print();             // Print the stack

	cout << endl;          
             
    a = LS.Pop(); 			// get animal off the top of stack
	
	cout << a << endl;      // print animal (cout operator overloaded)

	a = LS.Pop();           // get animal off the top of stack again
 
	cout << a << endl;      // print animal (cout operator overloaded)

	LS.Print();             // print the stack
}
