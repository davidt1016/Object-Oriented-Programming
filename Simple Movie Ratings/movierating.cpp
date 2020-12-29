/**
* @file movierating.cpp
* @author David Teng
* @Date  05/29/2018
* @version 1.0
* The program consists of all the information about a Movie. It includes
  information such as the movie name, MPAA rating, and the rating from 1(terrible) to 
  5 (great). The class Movie will have a series of input on the rating of a movie and the
  average of all the rating will be computed and output to the screen.
**/
// _____ David Teng ____      _____May 29/2018____________

#include <iostream>  
#include <string>
#include <iomanip>

using namespace std;

/* Creating a class called Movie*/
class Movie
{
	/*Member functions will store in public including mutator and accessor function*/
	public:
		/*Constructor for initializing all the variables for the movie*/
		Movie();
		/*Fucntion for adding and updating the rating for the movie*/
		void addRating(int rating);
		/*Fucntion for returing average of the rating*/
		double getAverage();
		/*Function for accessing the Movie_Name in private variables*/
		string getMovie();
		/*Function for accessing the MPAA rating in private variables*/
		string getMPAA();
		/*Void Functions for updating Movie and MPAA rating*/
		void updateMovieInfo(string name, string mpaa_rating);
		/*Function for accessing each individual rating and account for how many each individual rating has*/
		void getRatingOutput();

	/*All variables will be private so that it is protected from accessible through main function*/
	private:
		//Creating variables for the all the information regarding a Movie
		string Movie_Name;
		string MPAA_rating;
		/*Ratings*/
		int rating_terrible;
		int rating_bad;
		int rating_ok;
		int rating_good;
		int rating_great;
		/*Average Calculation*/
		int num_rating;
		double sum;
};

/*Main function will create a few movie objects and store all the information inside the private variables*/
int main()
{
	/*Creating movie objects*/
	Movie Terminator, Avengers, IT;
	
	//Variables for test driver program
	Movie test; 
	char ans;
	string test_movie_name = "";
	string test_MPAA = "";


	/*Adding movie name, MPAA rating and viewers' rating*/
	Terminator.updateMovieInfo("The Terminator", "R");
	/*Setting ratings*/
	Terminator.addRating(2);
	Terminator.addRating(3);
	Terminator.addRating(4);
	Terminator.addRating(5);
	Terminator.addRating(2);
	for (int i = 1; i <= 5; i++)
	{
		Terminator.addRating(i);
	}
	/*Output the Movie information and all the ratings*/
	cout << "The Movie: " << Terminator.getMovie() << " has MPAA rating of " << Terminator.getMPAA() << endl;
	cout << "The ratings of this movie are: " << endl;
	Terminator.getRatingOutput();
	cout << "The overall average ratings for this movie are: " << fixed << setprecision(2) <<Terminator.getAverage() << endl;
	cout << endl << endl;

	/*Adding movie information for Avengers movie*/
	Avengers.updateMovieInfo("Avengers: Infinity War", "PG-13");
	/*Adding Ratings*/
	Avengers.addRating(5);
	Avengers.addRating(5);
	Avengers.addRating(4);
	Avengers.addRating(4);
	Avengers.addRating(5);
	Avengers.addRating(1);
	Avengers.addRating(2);
	Avengers.addRating(5);
	Avengers.addRating(3);

	/*Output the Movie information and all the ratings*/
	cout << "The Movie: " << Avengers.getMovie() << " has MPAA rating of " << Avengers.getMPAA() << endl;
	cout << "The ratings of this movie are: " << endl;
	Avengers.getRatingOutput();
	cout << "The overall average ratings for this movie are: " << fixed << setprecision(2) << Avengers.getAverage() << endl;
	cout << endl << endl;

	/*Adding information for the movie IT*/
	IT.updateMovieInfo("IT", "R");
	//Adding Ratings
	IT.addRating(5);
	IT.addRating(4);
	IT.addRating(4);
	IT.addRating(4);
	IT.addRating(4);
	IT.addRating(5);
	IT.addRating(3);
	IT.addRating(5);
	/*Output the Movie information and all the ratings*/
	cout << "The Movie: " << IT.getMovie() << " has MPAA rating of " << IT.getMPAA() << endl;
	cout << "The ratings of this movie are: " << endl;
	IT.getRatingOutput();
	cout << "The overall average ratings for this movie are: " << fixed << setprecision(2) << IT.getAverage() << endl;
	cout << endl << endl;



	/*-------------------TEST DRIVER PROGRAM-------------------*/
	do {
		/*Testing via user input*/
		cout << "-------------------Testing Driver Program-------------------" << endl << endl;
		cout << "Enter a movie name: ";
		cin >> test_movie_name;
		cout << "Enter the MPAA rating for the movie: ";
		cin >> test_MPAA;
		test.updateMovieInfo( test_movie_name, test_MPAA);
		/*setting fixed input ratings*/
		cout << "The anticipated output should be as follow: " << endl << endl;
		cout << "The Movie: " << test_movie_name << " has MPAA rating of " << test_MPAA << endl;
		cout << "The ratings of this movie are: " << endl;
		cout << "There are 1 people rating this movie as 1(TERRIBLE)." << endl;
		cout << "There are 1 people rating this movie as 2(BAD)." << endl;
		cout << "There are 1 people rating this movie as 3(OK)." << endl;
		cout << "There are 1 people rating this movie as 4(GOOD)." << endl;
		cout << "There are 1 people rating this movie as 5(GREAT)." << endl;
		cout << "The overall average ratings for this movie are 3.00" << endl << endl;

		/*Testing the functions*/
		cout << "The actual outputs via multiple function calls are the following: " << endl << endl;
		cout << "The Movie: " << test.getMovie() << " has MPAA rating of " << test.getMPAA() << endl;
		for (int j = 1; j <= 5; j++)
		{
			test.addRating(j);
		}
		cout << "The ratings of this movie are: " << endl;
		test.getRatingOutput();
		cout << "The overall average ratings for this movie are: " << fixed << setprecision(2) << test.getAverage() << endl;
		cout << endl << endl;

		cout << "Repeating the testing process? (Y for continue/ N for Discard): ";
		cin >> ans;
	} while ( ans == 'y' || ans == 'Y' );

}


/*------------------Constructors and Class Memeber Functions Definition------------------*/

/*Constructor for initializing all the variables*/
Movie::Movie()
{
	Movie_Name = "";
	MPAA_rating = "";
	rating_terrible = 0;
	rating_bad = 0;
	rating_ok = 0;
	rating_good = 0;
	rating_great = 0;
	num_rating = 0;
	sum = 0.0;
}
/* PreCondition: The addRating function will have integer rating passed in as a function pararmeter.
   PostCondition: Based on the value that is passed in, the corresponding rating will increment by 1.
   The function will return the sum of all the ratings.*/
void Movie::addRating( int rating )
{
	/*Series of if-else-if-else statements to determine what rating has been passed in*/
	/*Checking if the input rating is horrible, if so incremet by 1*/
	if ( rating == 1 )
	{
		rating_terrible++;
	}
	/*Checking if the input rating is bad, if so increment by 1*/
	else if ( rating == 2 )
	{
		rating_bad++;
	}
	/*Checking if the input rating is ok, if so increment by 1*/
	else if ( rating == 3 )
	{
		rating_ok++;
	}
	/*Checking if the input rating is good, if so increment by 1*/
	else if ( rating == 4 )
	{
		rating_good++;
	}
	/*Checking if the input rating is great, if so increment by 1*/
	else if (rating == 5)
	{
		rating_great++;
	}
	else
	{
		/*If the input is wrong, it will give an error message.*/
		cout << "Invalid rating! Please enter a valid input" << endl;
	}
}
/*PreCondition: The getAverage function will access all the ratings in the private member variables for calculation.
  PostCondition: The average of all the rating will be returned.*/
double Movie::getAverage( )
{
	/*Summation of all different types of ratings*/
	sum = 1 * rating_terrible + 2 * rating_bad + 3 * rating_ok + 4 * rating_good + 5 * rating_great;
	/*Summation of number of valid increments for all the ratings*/
	num_rating = rating_terrible + rating_bad + rating_ok + rating_good + rating_great;
	/*Return the average of all the ratings*/
	return sum / num_rating;
}
/*Simple accessor functions for accessing  movie name and MPA rating*/
string Movie::getMovie()
{
	return Movie_Name;
}
string Movie::getMPAA()
{
	return MPAA_rating;
}
/*PreCondition: Two input string variables are passed into the function parameter.
  PostCondition: THe variable Movie_Name and MPAA_rating will be updated according to what is being passed in*/
void Movie::updateMovieInfo(string name, string mpaa_rating )
{
	Movie_Name = name;
	MPAA_rating = mpaa_rating;
}
/*PreCondition: The function will access each variable under rating
  PostCondition: The function will print out how many times the ratings has been incremented for all 5 various types of ratings.*/
void Movie::getRatingOutput()
{
	/*Printing out number of ratings for each rating score*/
	cout << "There are " << rating_terrible << " people rating this movie as 1(TERRIBLE)." << endl;
	cout << "There are " << rating_bad << " people rating this movie as 2(BAD)." << endl;
	cout << "There are " << rating_ok << " people rating this movie as 3(OK)." << endl;
	cout << "There are " << rating_good << " people rating this movie as 4(GOOD)." << endl;
	cout << "There are " << rating_great << " people rating this movie as 5(GREAT)." << endl;
}