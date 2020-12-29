/**
* 
* @author David, Teng
* @Date  06/04/2018
* @version 1.0
* @Applying overloaded operator  ">>" and "<<" for input and output of pairs of values.
Using the overloaded operator for addition, subtraction, and multiplication on the pairs and
output to the screen.
*/
// _____ David, Teng ____      _____June 4/2018____________

#include <iostream>  

using namespace std;

/*Creating a class called Pairs*/
class Pairs
{
public:
	/*2 Constructors with no parameters and another two parameters constructor*/
	Pairs();
	Pairs(int first, int second);
	/*Friend functions with overloaded operators*/
	friend istream& operator >> (istream& ins, Pairs& second);
	friend ostream& operator << (ostream& outs, const Pairs& second);

	/*Overloaded binary operators that do multiplication,*/
	/*Adding operator based on the rule of matrix addition, (a,b)+(c,d)=(a+b, c+d)*/
	friend Pairs operator + (Pairs& first_pair, Pairs& second_pair);
	/*Subtracting operator based on the rule of matrix subtracttion, (a,b)-(c,d)=(a-b, c-d)*/
	friend Pairs operator - (Pairs& first_pair, Pairs& second_pair);
	/*Multiplying operator based on the rule of multiplication of a matrix with a constant, (a,b)*c=(a*c, b*c)*/
	friend Pairs operator * (Pairs& first_pair, int factor);

private:
	/*Private member variables*/
	int f;
	int s;
};

int main()
{
	/*Initializing the first member of the parameter to be 8 and the second member to be zero*/
	Pairs first(8, 0);
	/*Creating an object called second*/
	Pairs second;
	/*Multiplication factor*/
	int factor = 0;

	cout << "The initilization of the first pair output is: "  << first << endl;
	cout << "Input the value with this form. '(5,6)' for second pair to perform +/-/* operations" << endl;
	cout << "Second Input Pair : ";
	cin >> second;
	cout << "Original Data :" << endl;
	cout << "a : " << first << ", " << "b :" << second << endl << endl;
	cout << "Addition= a+b =" << first + second << endl << endl;
	cout << "Substraction= a-b =" << first - second << endl << endl;
	cout << "Enter an integer desired amplification factor: ";
	cin >> factor;
	cout << "Multiplication = a * factor of " << factor << " is: " << first * factor << endl << endl;

	cout << "Now the user can set their own first pair!" << endl << endl;
	cout << "Input the value with this form. '(5,6)'" << endl;
	cout << "First Input Pair :";
	cin >> first;
	cout << "Second Input Pair : ";
	cin >> second;
	cout << "Original Data :" << endl;
	cout << "a : " << first << ", " << "b :" << second << endl << endl;
	cout << "Addition= a+b =" << first + second << endl << endl;
	cout << "Substraction= a-b =" << first - second << endl << endl;
	cout << "Enter an integer desired amplification factor: ";
	cin >> factor;
	cout << "Multiplication = a * factor of " << factor << " is: " << first * factor << endl << endl;
	system("pause");
	return 0;
}
/*Default constructor for initializing the variables*/
Pairs::Pairs()
{
	/*Initializing the private member variables to zero*/
	f = 0;
	s = 0;
}

/*Constructor with two parameters of first and second*/
Pairs::Pairs(int first, int second)
{
	/*Storing the variable 'first' into f and variable 'second' into s*/
	f = first;
	s = second;
}

/*Implementing friends functions*/
/*Input operator that checks the correctness of the input from user and store it into Class Pairs*/
istream& operator >> (istream& ins, Pairs& second)
{
	char b1, b2, comma;
	int firstValue, secondValue;
	ins >> b1;
	ins >> firstValue;
	ins >> comma;
	
	/*Validating wether or not the correct format has been provided*/
	if (b1 != '(') 
	{
		cout << "Please input the correct format!" << endl;
	}
	if (comma == ',') 
	{
		ins >> secondValue;
		
		ins >> b2;
		second.f = firstValue;
		second.s = secondValue;
	}
	 if (comma == ')') 
	 {
		second.f = firstValue;
		second.s = 0;
	 }
	 if (b2 != ')')
	 {
		 cout << "Please input the correct format!" << endl;
	 }
	return ins;
}
/*Output operator that prints out the pairs*/
ostream& operator << (ostream& outs, const Pairs& second)
{
	long first, sec;
	first = second.f;
	sec = second.s;
	outs << '(' << first << ',' << sec << ')';
	return outs;
}


/*Adding operator based on the rule of matrix addition, (a,b)+(c,d)=(a+b, c+d)*/
Pairs operator + (Pairs& first_pair, Pairs& second_pair)
{
	Pairs temp;
	temp.f = first_pair.f + second_pair.f;
	temp.s = first_pair.s + second_pair.s;
	return temp;
}
/*Subtracting operator based on the rule of matrix subtracttion, (a,b)-(c,d)=(a-b, c-d)*/
Pairs operator - (Pairs& first_pair, Pairs& second_pair)
{
	Pairs temp;
	temp.f = first_pair.f - second_pair.f;
	temp.s = first_pair.s - second_pair.s;
	return temp;
}
/*Multiplying operator based on the rule of multiplication of a matrix with a constant, (a,b)*c=(a*c, b*c)*/
Pairs operator * (Pairs& first_pair, int factor)
{
	Pairs temp;
	temp.f = first_pair.f * factor;
	temp.s = first_pair.s * factor;
	return temp;
}

