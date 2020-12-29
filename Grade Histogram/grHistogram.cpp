/**
* 
* @author David Teng
* @Date  06/17/2018
* @version 1.0
* @The program will accept a series of grade input from the user.
*The program will then store the value into vector and based on the occurrence of each 
*grade, the corresponding grade will be incremented by on accordingly and store it in
*dynamic array and output it in histogram format.
*/
//
// _____ David, Teng ____      _____June 17/2018____________
//



#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

/*Function Declarations*/
/*Computing the maximum value that is stored inside the array*/
int determineMAX(vector<int> &data, int maximum);

/*Output the histogram to the screen*/
void OutputHistogram(int *result, int size);

int main()
{
	/*Variables Initialization*/
	vector <int> grading;
	int grade;
	int size = 100;
	int max_value = 0;
	int iterator = 0;

	/*Creating dynamic arrays for storing the computation of histogram data*/
	/*Creating a dynamic array at most of size equals to the maximum value inside the vector*/
	int *histogram = new int[size];
	/*Initializing all the element in histogram array to zero to prevent the computer storing random
	address in the array*/
	for (int i = 0; i < size; i++)
	{
		histogram[i] = 0;
	}


	/*Asking user input of the grade until the user input type in -1*/
	do
	{
		cout << "Enter student's grade (enter -1 to quit and enter the test driver program): ";
		cin >> grade;
		/*Criteria for pushing only grade from 0~100*/
		if (grade >= 0 && grade <= 100) 
		{
			grading.push_back(grade);
			/*Increment the corresponding grade if it appears more than once inside the vector called 'grade'*/
			histogram[grading[iterator]]++;
			iterator++;
		}
	}
	while (grade != -1);

	/*Determining the maximum value from the vector list*/
	max_value = determineMAX(grading, max_value);

	/*Output the histogram to the screen*/
	OutputHistogram(histogram, max_value);

	
	/*TEST DRIVER PROGRAM starts here*/
	/*Initializing different and independent variables from the actual program*/
	vector <int> test_grading;
	int test_grade = 0;
	int test_max = 0;
	int test_size = 100;
	int test_iterator = 0;
	/*Different dynamic array variable name*/
	int *test_histogram = new int[test_size];

	for (int m = 0; m < test_size; m++)
	{
		test_histogram[m] = 0;
	}

	cout << "-----------Entering test driver program!--------" << endl;
	do
	{
		cout << "Enter student's grade (enter -1 to end) : ";
		cin >> test_grade;
		if (test_grade >= 0 && test_grade <= 100)
		{
			test_grading.push_back(test_grade);
			/*Increment the corresponding grade if it appears more than once inside the vector called 'grade'*/
			test_histogram[test_grading[test_iterator]]++;
			test_iterator++;
		}
	} while ( test_grade != -1  );

	cout << "The expected result: " << endl;
	/*Displaying what has been pushed*/
	for (int l = 0; l < test_grading.size(); l++)
	{
		cout << "The grade: " << test_grading[l] << " has been pushed back" << endl;
		if (test_grading[l] > test_max)
		{
			test_max = test_grading[l];
		}
	}
	cout << "The maximum grade is:" << test_max << endl;
	for (int j = 0; j < test_max; j++)
	{
		/*Only print out the one that has shown up in the vector to the screen */
		if (test_histogram[j] != 0)
		{
			/*Print out the histogram*/
			cout << "Number of " << j << "'s:" << test_histogram[j] << endl;
		}
	}
	/*Actual output of all the function calls*/
	cout << endl << endl << "The actual result is (after functions call): " << endl << endl;
	cout << "The max function is called and the maximum value returned is " << determineMAX(test_grading, test_max) << endl;
	cout << "The actual ouput of the program after calling OutputHistogram function is " << endl << endl;
	OutputHistogram(test_histogram, test_max);

	system("pause");
}


/*Function definitions*/

/* Precondition: A vector of integer data are passed into the function along with initial maximum value
   PostCondition: The maximum value in vector 'grading' will be returned back to the main function.
*/
int determineMAX(vector<int> &data, int maximum )
{
	/*If the vector is empty, there's nothing in it hence the maximum is hard coded to zero*/
	if (data.empty())
	{
		maximum = 0;
	}
	/*If there are series of data, the comparison will begin through a for loop*/
	for (int i = 0; i < data.size(); i++)
	{
		/*if the data is greater than original maximum value then store it into the variable 'maximum'*/
		if (data[i] > maximum)
		{
			maximum = data[i];
		}
	}
	return maximum;
}


/*Precondition: A dynamic array is passed in along with the size of the array
  PostCondition: The histogram will be output to the screen*/
void OutputHistogram(int *result, int size)
{
	for (int j = 0; j < size; j++)
	{
		/*Only print out the one that has shown up in the vector to the screen */
		if (result[j] != 0)
		{
			/*Print out the histogram*/
			cout << "Number of " << j << "'s:" << result[j] << endl;
		}
	}
}








