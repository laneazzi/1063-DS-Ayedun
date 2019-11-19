///////////////////////////////////////////////////////////////////////////////
//
// Author:           OLANREWAJU AYEDUN
// Assignment:       Program_03
// Date:             14 November 2019
// Title:            Program 3 
// Semester:         Spring 2019
// Course:           CMPS 1063 
// 
// Files:            apm.cpp, 
//                   doubly_linked.hpp, 
//                   input_data.txt 
//                   output.num
// Description:
//       Program to perfrom precise and large arithmetic operations
//

#include <iostream>
using namespace std;



struct Node{

  int data;

  Node* Next;

  Node* Prev;



  Node(int d){

    data = d;

    Next = NULL;

    Prev = NULL;

  }

};



class DoublyLinked{

private:

  Node *Head;

  Node *Middle;

  Node *Tail;

  

  int MiddleLoc;

  int size;

public:

  

  DoublyLinked();

  void FrontSert(int);

  void EndSert(int);

  void Print();

  void Delete();

  int Length();

  void add(DoublyLinked*, DoublyLinked*);

  void mul(DoublyLinked*, DoublyLinked*); 

  void sub(DoublyLinked*, DoublyLinked*);

  void PrintResult(ofstream &);

};





DoublyLinked::DoublyLinked(){

  Head = Middle = Tail = NULL;

  size = 0;

}



void DoublyLinked::FrontSert(int value){

  Node* temp = new Node(value); 

      

    if (Head == NULL) 

        Head = Tail = temp; 

    else { 

        Head->Prev = temp; 

        temp->Next = Head; 

        Head = temp; 

    } 

    size++; 

}



void DoublyLinked::EndSert(int value){

  Node* temp = new Node(value); 

      

    if (Tail == NULL) 

        Head = Tail = temp; 

    else { 

        Tail->Next = temp; 

        temp->Prev = Tail; 

        Tail = temp; 

    } 

    size++; 

}



void DoublyLinked::Print(){

    Node* Temp = Head;



    while(Temp){

      cout<<Temp->data;

      if(Temp->Next){

        cout<<"->";

      }

      Temp = Temp->Next;

    }

    cout<<endl;

}



int DoublyLinked::Length(){ 

    return size; 

} 



/**

 * Add

 * 

 * Description:

 *      Adds two doubly linked lists together.

 * 

 * Params:

 *      DoublyLinked* a 

 *      DoublyLinked* b 

 */

void DoublyLinked::add(DoublyLinked* a, DoublyLinked* b){ 

    int c = 0, s; 

    DoublyLinked* a1 = new DoublyLinked(*a); 

    DoublyLinked* b1 = new DoublyLinked(*b); 

  

    // Default constructor 

    // Constructor that copies data in the Node 

    this->Head = NULL; 

    this->Tail = NULL; 

    this->size = 0; 

  

    while (a1->Tail != NULL || b1->Tail != NULL) { 

        if (a1->Tail != NULL && b1->Tail != NULL) { 

            s = ((a1->Tail->data) + (b1->Tail->data) + c) % 10; 

            c = ((a1->Tail->data) + (b1->Tail->data) + c) / 10; 

            a1->Tail = a1->Tail->Prev; 

            b1->Tail = b1->Tail->Prev; 

        } 

        else if (a1->Tail == NULL && b1->Tail != NULL) { 

            s = ((b1->Tail->data) + c) % 10; 

            c = ((b1->Tail->data) + c) / 10; 

            b1->Tail = b1->Tail->Prev; 

        } 

        else if (a1->Tail != NULL && b1->Tail == NULL) { 

            s = ((a1->Tail->data) + c) % 10; 

            c = ((a1->Tail->data) + c) / 10; 

            a1->Tail = a1->Tail->Prev; 

        } 

          

        // Insert sum digit 

        FrontSert(s); 

    } 

      

    // Insert last carry 

    if (c != 0) 

        FrontSert(c); 

} 



/**

 * sub

 * 

 * Description:

 *      Subtracts one doubly linked list from another.

 * 

 * Params:

 *      DoublyLinked* a 

 *      DoublyLinked* b 

 */

void DoublyLinked::sub(DoublyLinked* a, DoublyLinked* b){ 

    int c = 0, s; 

    DoublyLinked* a1 = new DoublyLinked(*a); 

    DoublyLinked* b1 = new DoublyLinked(*b); 

  

    this->Head = NULL; 

    this->Tail = NULL; 

    this->size = 0; 

      

    while (a1->Tail != NULL || b1->Tail != NULL) { 

        if (a1->Tail != NULL && b1->Tail != NULL) { 

            if ((a1->Tail->data) + c >= (b1->Tail->data)) { 

                s = ((a1->Tail->data) + c - (b1->Tail->data)); 

                c = 0; 

            } 

            else { 

                s = ((a1->Tail->data) + c + 10 - (b1->Tail->data)); 

                c = -1; 

            } 

            a1->Tail = a1->Tail->Prev; 

            b1->Tail = b1->Tail->Prev; 

        } 

        else if (a1->Tail != NULL && b1->Tail == NULL) { 

            if (a1->Tail->data >= 1) { 

                s = ((a1->Tail->data) + c); 

                c = 0; 

            } 

            else { 

                if (c != 0) { 

                    s = ((a1->Tail->data) + 10 + c); 

                    c = -1; 

                } 

                else

                    s = a1->Tail->data; 

            } 

            a1->Tail = a1->Tail->Prev; 

        } 

        FrontSert(s); 

    } 

} 



/**

 * Mul

 * 

 * Description:

 *      Multiplies two doubly linked lists together.

 * 

 * Params:

 *      DoublyLinked* a 

 *      DoublyLinked* b  

 */

void DoublyLinked::mul(DoublyLinked* a, DoublyLinked* b){ 

    int Count = 0, i; 

    DoublyLinked* tpro = new DoublyLinked(); 

    while (b->Tail != NULL) { 

      int c = 0, s = 0; 

      DoublyLinked* temp = new DoublyLinked(*a); 

      DoublyLinked* pro = new DoublyLinked(); 

      while (temp->Tail != NULL) { 

          s = ((temp->Tail->data) * (b->Tail->data) + c) % 10; 

          c = ((temp->Tail->data) * (b->Tail->data) + c) / 10; 

          pro->FrontSert(s); 

          temp->Tail = temp->Tail->Prev; 

      } 

      if (c != 0) 

          pro->FrontSert(c); 



      for (i = 0; i < Count; i++) 

          pro->EndSert(0); 



      add(this, pro); 

      Count++; 

      b->Tail = b->Tail->Prev; 

      pro->Head = pro->Tail = NULL; 

      pro->size = 0; 

    } 

} 



/**

 * PrintResult

 * 

 * Description:

 *      Prints out the large number from a list

 */

void DoublyLinked::PrintResult(ofstream &fout){ 

  Node* temp = Head; 

  while (temp != NULL) { 

      fout << temp->data; 

      temp = temp->Next; 

  } 

  fout<<endl<<endl;

} 
