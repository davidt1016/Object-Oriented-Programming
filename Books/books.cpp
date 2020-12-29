/**
* 
* @author David, Teng
* @Date  07/09/2018
* @version 1.0
* @    The program will ask user for the input of book's author, title, and date.
*	   If the user types in 2 it will output the author of the book alphabetically and 3 to quit.
*	   If the user type in 1 then it will continue to ask the user for the author of the book, title, and
*   the date of the book.
*/
// _____ David,Teng ____      _____July 9/2018____________
//

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;  

/*Creating a class called book*/
class Book
{
	/*Public member functions*/
	public:
	/*Default constructors*/
		Book();
		Book(string title,string writer,string published_date);
	/*Mutator Functions*/
		void updateTitle(string bookTitle);
		void updateAuthor(string AuthorName);
		void updateDate(string DateofBook);
	/*Accessorr Functions*/
		string getTitle();
		string getAuthor();
		string getDate();
		/*Overloading operator that compares book_a and book_b and returning true or false*/
		friend bool operator<(const Book &book_a, const Book &book_b);
	
	/*Private member variables*/
	private:
		string book_title;
		string author;
		string date;
};

int main()
{
	/*Variable Declarations*/
	int user_decision = 0;
	string Auth, Titles, Date;
	vector <Book> books;
	do
	{	
		/*Basic input/output*/
		cout << "Select From the following choices: \n";
		cout << "1. Add new book\n";
		cout << "2. Print listing sorted by author\n";
		cout << "3. Quit\n";
		cin >> user_decision;
		/*User entering new books*/
		if (user_decision == 1)
		{
			cout << "Enter title: \n";
			cin.ignore();
			getline(cin, Titles);
			cout << "Enter Author: \n";
			getline(cin, Auth);
			cout << "Enter date: \n";
			getline(cin, Date);
			/*Asssigning variables into private member variables*/
			Book book1(Titles, Auth, Date);
			/*pushing books onto the vector*/
			books.push_back(book1);
		}
		/*Printing out the books stored in vector according to the author name in alphabetical order*/
		if (user_decision == 2)
		{
			/*If user_input is 2 then sort all the book in the vector and print it out*/
			
				/*Sorting the author */
				sort(books.begin(), books.end());
				cout << "The books entered so far, sorted alphabetically by artists are: \n";
				/*Printing out the sorted list*/
				for (int i = 0; i < books.size(); i++)
				{
					cout << "   " << books[i].getAuthor() << "," << books[i].getTitle() << "," << books[i].getDate() << endl;
				}
		}
		/*If user input 3, then quit the program*/
	} while (user_decision != 3);

}

/*Default Constructor*/
Book::Book()
{
	/*Assigning default value*/
	book_title = "";
	author = "";
	date = "";
}
Book::Book(string title, string writer, string published_date)
{
	/*Assigning function parameters into the private member variables*/
	book_title = title;
	author = writer;
	date = published_date;
}

/*Mutator Functions*/
void Book::updateTitle(string bookTitle)
{
	book_title = bookTitle;
}
void Book::updateAuthor(string AuthorName)
{
	author = AuthorName;
}
void Book::updateDate(string DateofBook)
{
	date = DateofBook;
}

/*Accessor Functions*/
string Book::getTitle()
{
	return book_title;
}
string Book::getAuthor()
{
	return author;
}
string Book::getDate()
{
	return date;
}
/*Precondition: two class objects have been passed in as function parameters
  Postcondition: It will return true or false accordingly through the comparison in sort() under
  algorithm library*/
bool operator<(const Book &book_a, const Book &book_b)
{
	return book_a.author < book_b.author;
}
