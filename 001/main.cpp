#include <iostream>
#include <vector>

using namespace std;

class widget
{

	public:

		//constructors
		widget();				// default
		widget(int i);			// int
		widget(widget & w);		// copy
		widget(widget && w);	// move

		//operators
		widget & operator=(widget & w);
		
		//friend functions
		friend ostream & operator<<(ostream & os, widget & w);

	private:
		
		int value;
		
};


widget::widget() : value(0)
{

	cout << "Default CTOR used" << endl;

}


widget::widget(int i) : value(i)
{

	cout << "Conversion Integer CTOR used" << endl;

}

widget::widget(widget & w) : value(w.value)
{

	cout << "Copy CTOR used" << endl;

}


widget::widget(widget && w)
{

	cout << "Move CTOR used" << endl;

}

widget & widget::operator=(widget & w)
{

	cout << "Assignment overload used" << endl;
	value = w.value;

	return *this;

}


ostream & operator<<(ostream & os, widget & w)
{

	os << "Value: " << w.value << endl;
	
	return os;

}

int main()
{
	int x = 0;


	//JG Question #1
	widget a;
	cout << a << endl;
	
	//widget b();			//the compiler treats this as a function call.
	//cout << b << endl;
	
	widget c{ 1 };
	cout << c << endl;
	
	widget d(x);			//if I had replaced "x" with "int" the compiler will think this is a function call
	cout << d << endl;
	
	widget e{ x };
	cout << e << endl;
	
	widget f = x;			//always INITIALIZATION, never assignment		
	cout << f << endl;
	
	widget g = { x };		//always INITIALIZATION, never assignment
	cout << g << endl;
	
	auto h = x;             //this should have called the copy constructor, but didn't    
	cout << h << endl;
	
	auto i = widget{ x };       
	cout << i << endl;

	//Guru Questions 2
	vector<int> v1(10, 20);   // (a) - This initializes a vector, and assigns the value 20 to the first 10 entries.
	for (auto x : v1)
	{
		cout << x << ", ";
	}

	cout << endl << endl;

	vector<int> v2{ 10, 20 };   // (b) - This initializes a vector, and assigns the values 10 and 20 to the first 2 elements.
	for (auto x : v2)
	{
		cout << x << ", ";
	}

	//Guru Questions 4
	// Uniform Initialization
	// Works well for generic programming (unambiguous)
	// Can be used as function arguments when you don't want to name a variable

	//Guru Quesiton #4
	// When the class itself has a constructor that uses ().  
	
	/* 
		Here’s the simple guideline:

			Guideline: Prefer to use initialization with { }, such as vector<int> v = { 1, 2, 3, 4 }; 
			or auto v = vector<int>{ 1, 2, 3, 4 };, because it’s more consistent, more correct, 
			and avoids having to know about old-style pitfalls at all. In single-argument cases where 
			you prefer to see only the = sign, such as int i = 42; and auto x = anything; omitting the braces is fine. …
	
		That covers the vast majority of cases. There is only one main exception:

			… In rare cases, such as vector<int> v(10,20); or auto v = vector<int>(10,20);, 
			use initialization with ( ) to explicitly call a constructor that is otherwise hidden 
			by an initializer_list constructor.

		However, the reason this should be generally “rare” is because default and copy construction are already special and work fine with { }, 
		and good class design now mostly avoids the resort-to-( ) case for user-defined constructors because of this final design guideline:

			Guideline: When you design a class, avoid providing a constructor that ambiguously 
			overloads with an initializer_list constructor, so that users won’t need to use ( ) 
			to reach such a hidden constructor.
	*/

	cout << endl << endl;
	system("PAUSE");

	return 0;

}