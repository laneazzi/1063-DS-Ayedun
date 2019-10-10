//Olanrewaju Ayedun//



#include <iostream>

/** 
DATA 1063 
Teacher: Dr. Griffin
HW2 - Resizable Array Stack
Program reads data from a file and uses three methods
to check, enlarge and shrink the size of an array based stack. The results are printed to an output file.
*/

#include <iostream> 
#include <fstream>

using namespace std;

class Stack
{
private:
	int *A;  
	int Top; // To keep track of the top
	int count; 
	int Size;
	bool hasEnlarged;

public:
	// Default Constructor that initializes an array of type int and sets  top//


	Stack()
	{
		Size = 10;
		A = new int[Size];
		Top = -1;
		count = Top + 1;
		hasEnlarged = false;
	};

	/**
	 Overloaded constructor that initializes an array of type int to    a given size and sets the top.
   Int s: size is being passed.
	 */

	Stack(int s)
	{
		Size = s;
		A = new int[Size];
		Top = -1;
		hasEnlarged = false;
	};

	/**
	 * Push func to adds item to the top of the stack
	 * Returns a boolean.
	 */

	bool Push(int val) 
	{
		if (!Full())
		{
			Top++;
			count++;
			A[Top] = val;
			checkResize();
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
    Pop func to remove an item from the top of the stack and return it.
	 */

	int Pop() // 
	{
		if (!Empty())
		{
			int temp = 0;
			temp = A[Top];
			Top--;
			count--;
			checkResize();
			return temp;
		}
		else
		{
			cout<< "Stack is empty" << endl;
		}
		return 0;
	}

	/**
	 * Empty func to check if stack is empty
	 * Returns a boolean.
	 */

	bool Empty()
	{
		return Top < 0;
	}

	/**
	 * Full checks if is stack full
	 * Returns a boolean.
	 */

	bool Full()
	{
		return (Top == Size - 1);
	}
	// checkResize to enlarge or shrink stack based on specs.//

	void checkResize()
	{

		if (count >= int(Size * .8))
		{
			Enlarge();
		}
		else if (count <= int(Size * .2))
		{
			if (hasEnlarged)
			{
				Reduce();
			}
		}
	}

	// Enlarge func to increase array size//

	void Enlarge()
	{
		int newsize = int(Size * 1.5);
		int *b = new int[newsize];
		int *deleter = NULL;


		for (int i = 0; i < Size; i++)
		{
			b[i] = A[i];
		}
		Size = newsize;

		deleter = A;
		A = b;
		delete[] deleter;
		hasEnlarged = true;
	}

 //Reduce to shrink the array size//

	void Reduce()
	{
		int oldSize = int(Size * .5);
		int *C = new int[oldSize];
		int *deleter1 = NULL;

		for (int i = 0; i < oldSize; i++)
		{
			C[i] = A[i];
		}
		Size = oldSize;

		deleter1 = A;
		A = C;
		delete[] deleter1;
	}

	// MaxSize to return the current max size//
	int GetSize()
	{
		return Size;
	}

	//Print func to print the stack for debugging//

	void Print(ostream& out) // function to print the contents of the stack//
	{

		for (int i = Top; i >= 0; i--)
		{
			out<< A[i] << ' ';
		}
		out<< endl;
	}
};


int main()
{
	ofstream outfile; // declares an output file
	outfile.open("stack_out.dat.txt"); // creates "stack_out.dat" for writing output.//

	ifstream fin; // gets a stream variable//
	fin.open("input_data.txt"); // opens "input_data.txt" for reading//

	Stack S;         
	char operation;  
	int number;      
	int maxsize = 0; 

	while (fin >> operation >> number)
	{
		switch (operation)
		{
		case '+':
			S.Push(number);
			if (S.GetSize() > maxsize)
			{
				maxsize = S.GetSize();
			}
			// if s.getsize is bigger than maxsize
			// maxsize is equal to s.getsize
			break;
		case '-':
			S.Pop();
			break;
		default:
			outfile<< "Please recheck input file...Haha JK. But what if though?" << endl;
		}
		
	}

	outfile << "Olanrewaju Ayedun\n";
	outfile << "10 / 09 / 19\n";
	outfile << "HW 2\n\n";
	outfile << "Stack Size is: " << S.GetSize() << endl;
	outfile << "Largest Size is: " << maxsize << endl;
	outfile << "The values are: "  ;
	S.Print(outfile);
	outfile << endl;

	// Command to close file
	fin.close();
	outfile.close();

	return 0;
}
