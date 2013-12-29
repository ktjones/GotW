#include <iostream>
#include <vector>
#include <list>
#include <string>

class employee
{

private:

	string name;
	string adress;

public:

	employee() {};
	string & name() { return name; };



};


string find_addr(const list<employee> & emps, const string & name);

using namespace std;

int main()
{
	
	//JG Question

		/*
	
		A temporary object is an unnamed object that we cannot know the address of.  Often called an rvalue.

		...and just think about “rvalues” for temporary objects without names and whose addresses can’t be taken, 
		and “lvalues” for non-temporary objects that have names and whose addresses can be taken.
	
		*/

	//Guru Questions
	
	/*
	
		1. Function args passed by value.  They should be passed by const reference (const &)
		2. The end of the range is recalculated on each loop iteration. (potential, but not really due to auto)
			a.  The  postincrement operator (i++) has to increment and return the original value, which is extra work
				when compared to the preincrement operator.
		3. The comparison might use an implicit conversion.
			a.  The (*i == name) conditional statement forces the compiler to choose a member function to implicitly convert i to string.  This is either done 
				using the string class constructor, or the employee class constructor.  Either way, the implicit conversion creates a temporary object.
		4.	
	
	
	*/
	

	cout << endl << endl;
	system("PAUSE");

	return 0;

}

string find_addr(const list<employee> & emps, const string & name)
{
	for (auto i = begin(emps); i != end(emps); i++)
	{
		if (i->name() == name) 
		{
			return i->addr;
		}
	}
	return "";
}
