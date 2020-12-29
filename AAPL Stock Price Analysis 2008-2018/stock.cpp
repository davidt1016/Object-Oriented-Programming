/**
* @file lab8.cpp
* @author Chih Yu Teng
* @Date  07/16/2018
* @version 1.0
* @section Lab 8 will read in series of data from CSV document and read in the stock
*		   pricing for everywhere. The only manipulating data will be the high prices only,
*		   which will then be computed for its average price per year, per month, sort in descendent 
*		   and ascendent order. Then save the sorted list in a TEXT FILE.
*/
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Chih Yu,Teng ____      _____July 16/2018____________
//
// ____301250722____
#include<iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include<string>


using namespace std;

/*Function Declarations*/

int conversionYear(string Stock_Year);
int conversionMonth(string Stock_Date);
int conversionDay(string Stock_Day);
int searchStartYear(vector<string> Year_s, int startin_year);
int searchEndYear(vector<string> Year_e, int ending_year);
int searchStartMonth(vector<string> Month_s, int starting_month, int start_s, int end_s);
int searchEndMonth(vector<string> Month_e, int ending_month, int start_e, int end_e);
void AverageYear(vector<string> Year, int start, int end, vector<double> high_stock);
void AverageMonth(int start_year, int end_year, int starting_month, int ending_month, vector<string>Month, vector<double>stock_pricing1);
void HighestPrice(int search_year,vector<string>Date, vector<double>stock_pricing2);
void LowestPrice(int search_year1,vector<string>Date1, vector<double>stock_pricing3);
void SortAscending(vector<string> Date2, vector<double> stock);
void SortDescending(vector<string> Date3, vector<double> stock1);
void swap_date(string *date1, string *date2);
void swap_stock(double *stock1, double *stock2);


int main()
{
	/*Basic input and output data from and to the file*/
	ifstream fin;
	/*Variables Declaration*/
	string date1, temp_title, unused;
	string high;
	double high_1;
	/*Char variables for the third parameters for the getline() function*/
	char delim_comma = ',';
	char delim_next = '\n';
	/*Storing the value and string that is required by the specification of the lab*/
	vector <string> date;
	vector <double> highest;

	/*Trying to open the file*/
	fin.open("StockPrices.csv");
	/*Fail to open the file*/
	if (fin.fail())
	{
		cout << "Error: Input file cannot be opened! \n";
		exit(1);
	}
	/*Extracting only the date and high column title and ignore the rest*/
	getline(fin, date1, delim_comma);
	getline(fin, temp_title, delim_comma);
	getline(fin, high, delim_comma);
	getline(fin, unused, delim_next);

	/*Iterating through the file until end of file has been reached*/
	/*Extracting only the date and high point of the stock only*/
	while (!(fin.eof()))
	{
		/*Pushing only the date onto the vector*/
		getline(fin, date1, delim_comma);
		date.push_back(date1);

		/*Accessing the next element along the row but ignored it*/
		getline(fin, temp_title, delim_comma);
		/*Accessing the high element and pushback onto the vector*/
		getline(fin, high, delim_comma);
		/*Converting the string from high column into double and push_back double only*/
		high_1 = atof(high.c_str());
		highest.push_back(high_1);
		/*Ignoring the rest*/
		getline(fin, unused, delim_next);
	}
	/*PARTA----------------------Calculating the average stock price per year----------------------*/

	AverageYear(date, 2008, 2009, highest);
	AverageYear(date, 2009, 2010, highest);
	AverageYear(date, 2010, 2011, highest);
	AverageYear(date, 2011, 2012, highest);
	AverageYear(date, 2012, 2013, highest);
	AverageYear(date, 2013, 2014, highest);
	AverageYear(date, 2014, 2015, highest);
	AverageYear(date, 2015, 2016, highest);
	AverageYear(date, 2016, 2017, highest);
	AverageYear(date, 2017, 2018, highest);
	cout << endl << endl;

	/*PART B----------------------Calculating the average stock for a specific month of a year----------------------*/
	int startM = 0;
	int startY = 0;
	int endY = 0;
	char ans;
	do
	{
		cout << "Calculation of the average for a specific month of a year (ex 2008~2009)" << endl;
		cout << "Please enter the starting year: ";
		cin >> startY;
		cout << "Please enter the ending year: ";
		cin >> endY;
		cout << "Please enter the month in number (1 as January, 12 as December): ";
		cin >> startM;
		/*Function call for computing the average month*/
		AverageMonth(startY, endY, startM, (startM + 1), date, highest);
		cout << "Would you like to compute again for different month? (y or Y to continue) ";
		cin >> ans;
		/*Asking the user to continue on or not*/
	} while (ans == 'y' || ans == 'Y');

		/*PART C----------------------Searching for the largest and the lowest----------------------*/
		/*Starting from highest*/
		for (int s = 2008; s <= 2018; s++)
		{
			HighestPrice(s, date, highest);
		}
		cout << endl << endl;
		/*Finding the lowest*/
		for (int k = 2008; k <= 2018; k++)
		{
			LowestPrice(k, date, highest);
		}

		/*PART D & PART E----------------------Generating a file for storing the ascending and descending order of the data----------------------*/
		/*Sorting the data in ascending order*/
		SortAscending(date, highest);
		/*Sorting the data in descending order*/
		SortDescending(date, highest);

		/*Closing the file*/
		fin.close();

		system("pause");
	
}
/*Function Definitions*/

/*Precondition: Passing in Stock_Year in as function parameters in the format of "x/x/xxxx," or "x/xx/xxxx," or "xx/x/xxxx", or "xx/xx/xxxx,"
  Postcondition: Returning the integer version of the year*/
int conversionYear(string Stock_Year)
{
	int year = 0;

		/*Considering each year format*/
		/*If the date is xx/xx/xxxx, format*/
		if ( Stock_Year.size() == 10)
		{
			/*Extracting the Year*/
			year = (1000 * (Stock_Year[6] - '0')) + (100 * (Stock_Year[7] - '0')) + (10 * (Stock_Year[8] - '0'))
				+ (Stock_Year[9] - '0');
		}
		/*If the date is x/xx/xxxx, or xx/x/xxxx format*/
		if (Stock_Year.size() == 9)
		{
			year = (1000 * (Stock_Year[5] - '0')) + (100 * (Stock_Year[6] - '0')) + (10 * (Stock_Year[7] - '0')) +
				(Stock_Year[8] - '0');
		}
		if (Stock_Year.size() == 8)
		{
			/*Extracting the Year*/
			year = (1000 * (Stock_Year[4] - '0')) + (100 * (Stock_Year[5] - '0')) + (10 * (Stock_Year[6] - '0'))
				+ (Stock_Year[7] - '0');
		}
		return year;
}


/*Precondition: A date is thrown in as function parameter
  Postcondition: The string variable of that month will be converted into int*/
int conversionMonth(string Stock_Date)
{
	int month = 0;
	
	/*Checking the format of the date*/
	/*If it is within October, then the first character in the string should be from 1-9*/
	if (Stock_Date[1] == '/' )
	{
		month = (Stock_Date[0] - '0');
	}
	/*If it is passed beyond October, then it will have two elements that contain the information about the month*/
	if (Stock_Date[2] == '/')
	{
		month = ( 10* (Stock_Date[0] - '0')) + (Stock_Date[1] - '0');
	}
	/*Returning the converted integer month*/
	return month;
}

/*Precondition: A date is thrown in as function parameter
Postcondition: The string variable of that day will be converted into int*/
int conversionDay(string Stock_Day)
{
	int day = 0;
	/*Check it if is in this format x/xx/xxxx or x/x/xxxx*/
	/*x/x/xxxx or x/xx/xxxx format*/
	if (Stock_Day[1] == '/')
	{
		if (Stock_Day[3] == '/')
		{
			day = (Stock_Day[2] - '0');
		}
		if (Stock_Day[4] == '/')
		{
			day = (10 * (Stock_Day[2] - '0')) + (Stock_Day[3] - '0');
		}
	}

	/*xx/xx/xxxx format*/
	if (Stock_Day[2] == '/')
	{
		day = (Stock_Day[3] - '0');
	}
	if (Stock_Day[5] == '/')
	{
		day = (10 * (Stock_Day[3] - '0')) + (Stock_Day[4] - '0');
	}
	
	return day;
}
/*Precondition: Year vector along with the starting year is passed in as function parameter
  Postcondition: The found index is returned*/
int searchStartYear(vector<string> Year_s, int starting_year)
{
	int i = 0;
	int index_s = 0;
	int searchStartingYear = 0;

	/*Searching for the index of the corresponding Year in the CSV file*/
	while (i < (Year_s.size() - 1))
	{
		searchStartingYear = conversionYear(Year_s[i]);
		/*If found then break through the loop and set the index to the index_s*/
		if (searchStartingYear == starting_year)
		{
			index_s = i;
			break;
		}
		
		i++;
	}
	return index_s;
}
/*Precondition: Year vector along with the ending year is passed in as function parameter
 Postcondition: The found index is returned*/
int searchEndYear(vector<string> Year_e, int ending_year)
{
	int j = 0;
	int index_e = 0;
	int searchEndYear = 0;

	/*Searching for the index that stores the end of the year provided by the program*/
	while (j < (Year_e.size() - 1))
	{
		searchEndYear = conversionYear(Year_e[j]);
		/*If found, then break through the loop and pass the index to the index_e*/
		if (searchEndYear == ending_year)
		{
			index_e = j;
			break;
		}
		else
		{
			/*If it is not found then, it is the last year on the CSV, hence set the index_e to
			the number of the element -1*/
			index_e = (Year_e.size() - 1);
		}
		j++;
	}
	return index_e;
}
/*Precondition: Month vector along with the starting month is passed in as function parameter 
	as well as the starting year and ending year
Postcondition: The found index is returned*/
int searchStartMonth(vector<string> Month_s, int starting_month, int start_s, int end_s)
{
	int index_s = 0;
	int index_ys = 0;
	int index_ye = 0;
	int searchStartingMonth = 0;
	/*Series of function calls to find the matching year and month*/
	index_ys = searchStartYear(Month_s, start_s);
	index_ye = searchEndYear(Month_s, end_s);

	/*Responsible for calculating the month within a specific year*/
	/*Searching for the index of the corresponding MOnth in the CSV file*/
	while ( index_ys < index_ye )
	{
		searchStartingMonth = conversionMonth(Month_s[index_ys]);
		/*If found then break through the loop and set the index to the index_s*/
		if (searchStartingMonth == starting_month)
		{
			index_s = index_ys;
			break;
		}
		/*If it cannot be found then pass -1 for special handling*/
		else
		{
			index_s = -1;
		}
		index_ys++;
	}
	return index_s;
}
/*Precondition: Month vector along with the ending month is passed in as function parameter as well as the 
				starting year and ending year
Postcondition: The found index is returned*/
int searchEndMonth(vector<string> Month_e, int ending_month ,int start_e, int end_e)
{
	int index_e = 0;
	int index_ys = 0;
	int index_ye = 0;
	int searchEndMonth = 0;
	/*Series of function calls to find the matching year and month*/
	index_ys = searchStartYear(Month_e, start_e);
	index_ye = searchEndYear(Month_e, end_e);

	/*Searching for the index that stores the end of the month provided by the program*/
	while (index_ys < index_ye)
	{
		searchEndMonth = conversionMonth(Month_e[index_ys]);
		/*If found, then break through the loop and pass the index to the index_e*/
		if (searchEndMonth == ending_month)
		{
			index_e = index_ys;
			break;
		}
		/*If it cannot be found then pass -1 for special handling*/
		else
		{
			index_e = -1;
		}
		index_ys++;
	}
	return index_e;
}

/*Precondition: A starting and ending year is passed in along with the vector that stores the date and the stock 
  Postcondition: The average for that year will be output to the screen and it will output based on a year 
				regardless of the month and the date of both starting and ending date.*/
void AverageYear(vector<string> Year, int start, int end, vector<double> high_stock) 
{
	int index_s = 0;
	int index_e = 0;
	int numData = 0;
	double average = 0;
	double sum = 0;
	 index_s =searchStartYear(Year, start);
	 index_e = searchEndYear(Year, end);
	numData = index_e - index_s -1;
	/*for loop for calculating the sum of the stock for a year*/
	for (index_s; index_s < index_e; index_s++)
	{
		sum = sum + high_stock[index_s];
	}
	/*Calculating the average*/
	average = sum / numData;
	cout << "Average of year " << start << " to " << end << " is: "  << average << endl;	
}
/*Precondition: A year, starting month, and ending month along with the vector of month and the price
				will be passed in as function parameters.
 Postcondition: The average for the month will be calculated regardless of the day of the month. Therefore,
				it will return the average from July to August even if the data do not consist of full 30/31 days*/
void AverageMonth(int start_year, int end_year,int starting_month, int ending_month, vector<string>Month, vector<double>stock_pricing1)
{
	int index_s = 0;
	int index_e = 0;
	int numData = 0;
	double average = 0;
	double sum = 0;


	/*Series of function calls to find the matching year and month to compute the average*/
	
	index_s = searchStartMonth(Month, starting_month, start_year, end_year);
	index_e = searchEndMonth(Month, ending_month, start_year, end_year);
	numData = index_e - index_s - 1;
	/*for loop for calculating the sum of the stock for a specific year*/
	for (index_s; index_s < index_e; index_s++)
	{
		sum = sum + stock_pricing1[index_s];
	}
	average = sum / numData;
	if ((index_s == -1) || (index_e == -1))
	{
		cout << "Year: " << start_year << endl;
		cout << "Average of month " << starting_month << "~" << ending_month << " is: 0" << endl;
	}
	else
	{
		cout << "Year: " << start_year << endl;
		cout << "Average of month " << starting_month << "~" << ending_month << " is: " << average << endl;
	}
}
/*Precondition: Search year is passed in with two other vectors, Date and stock_pricing2,respectively.
  Postcondition:The highest pricing along with the corresponding date will be output to the screen*/
void HighestPrice(int search_year, vector<string>Date, vector<double>stock_pricing2)
{
	double max = 0;
	int max_year = 0;
	int end_year = 0;
	int index_s = 0;
	int index_e = 0;
	end_year = search_year + 1;

	index_s = searchStartYear(Date, search_year);
	index_e = searchEndYear(Date, end_year);
	/*Searching for the highest stock*/
	for (index_s; index_s < index_e; index_s++)
	{
		if (max < stock_pricing2[index_s])
		{
			max = stock_pricing2[index_s];
			max_year = index_s;
		}
	}
	cout << "Max occurs on " << Date[max_year] << " and the max value is: "<< max  << endl;
}
/*Precondition: Search year is passed in with two other vectors, Date and stock_pricing3,respectively.
	Postcondition:The lowest pricing along with the corresponding date will be output to the screen*/
void LowestPrice(int search_year1, vector<string>Date1, vector<double>stock_pricing3)
{
	double min = 99999999;
	int min_year = 0;
	int end_year = 0;
	int index_s = 0;
	int index_e = 0;
	end_year = search_year1 + 1;

	index_s = searchStartYear(Date1, search_year1);
	index_e = searchEndYear(Date1, end_year);
	/*Searching for the highest stock*/
	for (index_s; index_s < index_e; index_s++)
	{
		if (min > stock_pricing3[index_s])
		{
			min = stock_pricing3[index_s];
			min_year = index_s;
		}
	}
	cout << "Min occurs on " << Date1[min_year] << " and the min value is: " << min<< endl;
}
/*Swapping function for selection sort*/
void swap_date(string *date1, string *date2)
{
	string temp = *date1;
	*date1 = *date2;
	*date2 = temp;
}
void swap_stock(double *stock1, double *stock2)
{
	double temp = *stock1;
	*stock1 = *stock2;
	*stock2 = temp;
}

/*Reference for the sorting algorithm: https://www.geeksforgeeks.org/selection-sort/*/
/* Precondition: The vector Date and stock are passed in function parameter
   Postcondition: The function will sort the data in data in ascending order and store it 
				  in the text file*/
void SortAscending(vector<string> Date2, vector<double> stock)
{
	int min = 0;
	ofstream out;
	for (int i = 0; i < (stock.size() - 1); i++)
	{
		min = i;
		for (int j = i + 1; j < stock.size(); j++)
		{
			if (stock[j] < stock[min])
			{
				min = j;
			}
		}
		/*swapping*/
		swap_stock(&stock[min], &stock[i]);
		swap_date(&Date2[min], &Date2[i]);
	}
	/*printing onto the file*/
	out.open("Ascending.txt");
	for (int m = 0; m < Date2.size(); m++)
	{
		out << Date2[m] << "\t" << stock[m] << endl;
	}
	/*closing the file*/
	out.close();
}

/*Precondition: The vector Date and stock are passed in function parameter
  Postcondition : The function will sort the data in data in descending order and store it
				in the text file*/
void SortDescending(vector<string> Date3, vector<double> stock1)
{
	int min = 0;
	ofstream out1;
	for (int i = 0; i < (stock1.size() - 1); i++)
	{
		min = i;
		for (int j = i + 1; j < stock1.size(); j++)
		{
			if (stock1[j] > stock1[min])
			{
				min = j;
			}
		}
		/*swapping*/
		swap_stock(&stock1[min], &stock1[i]);
		swap_date(&Date3[min], &Date3[i]);
	}
	/*Printing onto the file*/
	out1.open("Descending.txt");
	for (int m = 0; m < Date3.size(); m++)
	{
		out1 << Date3[m] << "\t" << stock1[m] << endl;
	}
	out1.close();
}