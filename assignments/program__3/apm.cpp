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

#include <fstream>

#include "doubly_linked.hpp"



using namespace std;



int main() {

  ifstream fin;

  fin.open("input.dat");

  ofstream fmout;

  fmout.open("output.num");

  fmout<<"Olanrewaju Ayedun\n" <<"Program 3\n"

  << "Arbitrary Precision Math\n"<<endl;



  DoublyLinked* plus = new DoublyLinked(); 

  DoublyLinked* minus= new DoublyLinked(); 

  DoublyLinked* prod = new DoublyLinked();

  char run;

  string m1,s2;



  while(fin>>run>>m1>>m2){

    DoublyLinked* a = new DoublyLinked(); 

    DoublyLinked* b = new DoublyLinked();

    for (int i = 0; i < m1.length(); i++){

      a->FrontSert(m1.at(i) - '0');

    } 

    for (int i = 0; i < m2.length(); i++){

      b->EndSert(m2.at(i) - '0'); 

    }

    switch(op){

      case '+': plus->add(a, b);

        fmout<<"Operation 1: Addition\n Answer: \n";

        plus->PrintResult(fmout); break;

      case '-': minus->sub(a, b);

        fmout<<"Operation 2: Subtraction\n Answer: \n";

        minus->PrintResult(fmout); break;

      case '*': prod->mul(a, b);

        fmout<<"Operation 3: Multiplication\n Answer: \n";

        prod->PrintResult(fmout); break;

    }

  delete a;

  delete b;

  }

  fin.close();

  fmout.close();



  return 0;

}
