#include "ListStack.h"
#include <iostream>
#include <string>

using namespace std;

ostream &operator<<(ostream &os, const Animal *a) {
    os << a->name << ':' << a->weight << ':' << a->scary;
    return os;
}

/**
 * ListStack to construct the objects
 * Parameters:
 *     void
 * Returns:
 *     void
 *//** Olanrewaju Ayedun
Data Structures : Dr. Griffin
Date: October 15th 2019
Homework 3 - Overloading and Stacks
Description: List based Stack that holds an animal type
*/

#include "ListStack.h" // include stack definition
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

	// While there are still animals in the file
	while (!fin.eof()) {
		fin >> name >> weight >> scary;      // load animal with file data
		a = new Animal(name, weight, scary); // allocate memory for an animal           
		LS.Push(a);                          // push animal onto the stack      
	}

	LS.Print();             // Print the stack

	cout << endl;          
             
    a = LS.Pop(); 			// get animal off the top of the stack
	
	cout << a << endl;      // print animal (cout operator overloaded)

	a = LS.Pop();           // get animal off the top of the stack again
 
	cout << a << endl;      // print animal (cout operator overloaded)

	LS.Print();             // print the stack
}
ListStack::ListStack() {
    Top = NULL;
}

/**
 * Push to add an animal to the top of stack
 * Params:
 *     Animal* A : an animal type
 * Returns:
 *     void
 */
void ListStack::Push(Animal *A) {
    // allocate new memory
    Node *anode = new Node(A);    // Allocate new memory

    // check if list is empty
    if (!Top) {
        Top = anode;             // If stack empty, point to new node
    } else {
        anode->Next = Top;      // Link new node by pointing it next to old top
        Top = anode;            //  update top to point to the new node
    }
}

/**
 * Pop to remove an item from top of stack
 * Params:
 *     void
 * Returns:
 *     Animal* : top animal
 */
Animal *ListStack::Pop() {
    if (!Top) {
        return NULL;        // Return NULL for empty stack
    } else {
        Node *Temp = Top;   // Point to top with temp pointer

        Animal *a = Top->A; // Pull animal out of top (to return)

        Top = Top->Next;    // Move top of stack 

        delete Temp;        // Delete old top node

        return a;           // Return our animal
    }
}

/**
 * Print
 * Purpose:
 *     Print for debugging data
 * Params:
 *     void
 * Returns:
 *     void
 */
void ListStack::Print() {
    Node *Temp = Top;

    while (Temp != NULL) {
        cout << Temp->A << endl;
        Temp = Temp->Next;
    }
}
