/**
* 
* @author David, Teng
* @Date  06/26/2018
* @version 1.0
*           Converting the 24 hours input time from the user to 12 hours time. The program will catch any error from the user due
*		   to invalid input from the user through catch and throw exception until the user enters the correct input. 
*/

// _____ Chih Yu,Teng ____      _____June 26/2018____________

#include<iostream>
#include<string>

using namespace std;

/*Exception Class Declaration*/
class TimeFormatMistake
{
	public:
		/*Exception function will be thrown when it catches invalid input of time*/
		void error(string time);
};
/*Function declaration for TimeConversion that will compute the corresponding time and output to the screen*/
void TimeConversion(int &hour, int &minute, string user_input, int &size);

int main()
{
	/*String Variable declarations*/
	string user_time, time_zone;
	char user_choice;
	/*Integer variable initialization*/
	int hour,minute, size;

	do
	{
		cout << "Enter time in 24-hour notation: ";
		cin >> user_time;
		size = user_time.length();
		/*Exception handling starts here*/
		try
		{
			/*Calling the Time conversion function*/
			TimeConversion(hour, minute, user_time, size);
			/*If time is greater than 12 AM then it becomes PM*/
			if (hour >= 12)
			{
				time_zone = "PM";
			}
			else
			{
				/*If it is not PM then it has to be AM */
				time_zone = "AM";
			}
			/*Converting hour by getting the remainder of the hour divide by 12*/
			hour %= 12;
			if (hour == 0)
			{
				hour = 12;
			}
			/*For time in minute that is less than 10 minute it requires additional 0 in front of the minute*/
			if (minute < 10) 
			{	
				cout << "That is the same as " << endl;
				cout << hour << ":0" << minute << " " << time_zone << endl;
			}
			else
			{
				/*For time greater than 10 it will automatically output the right format*/
				cout << "That is the same as " << endl;
				cout << hour << ":" << minute << " " << time_zone << endl;
			}
		}
		/*Catching the handling TimeFormatMistake*/
		catch (TimeFormatMistake e)
		{
			e.error(user_time);
			/*Allowing the user to repeat the process again*/
			user_choice = 'y';
			continue;
		}
		/*Asking if the user want to repeat the process or not*/
		cout << "Again? (y/n)" << endl;
		cin >> user_choice;
		/*The program will run as long as the user type in Y for repeating the program*/
	} while (user_choice == 'y' || user_choice == 'Y');

}
void TimeFormatMistake::error(string time) 
{
	cout << "There is no such time as " << time << endl;
	cout << "Try again: " << endl;
}
/*Function Definition*/
/*Precondition: Time in terms of hours, minutes, size of the string, and the input of the time is given from user input
  Postcondition: The function will output the corresponding time based on the user input in 12-hours format*/
void TimeConversion(int &hour, int &minute, string user_input, int &size)
{
	/*The time format has to be either 01:45 or 1:45, which implies that it has to be either string length of five or four*/
	if (size > 5 || size < 4 ) 
	{
		throw TimeFormatMistake();
	}
	//If the user input time as 1:45 rather than 01:45, which has string length of four rather than five
	if (size == 4)
	{
		/*The initial input time has to be a positive number and it can only be 0-9 which is the same for both string length of four or five*/
		if (user_input[0] < '0' || user_input[0] > '9')
		{
			throw TimeFormatMistake();
		}
		/*Since the input from the user is 1:45 format rather than 01:45, the second element in the string has to be
		':'*/
		if (user_input[1] != ':')
		{
			throw TimeFormatMistake();
		}
		/*Checking for the third element if it is valid number*/
		if (user_input[2] <'0' || user_input[2] > '9')
		{
			throw TimeFormatMistake();
		}
		if (user_input[3] <'0' || user_input[3] > '9')
		{
			throw TimeFormatMistake();
		}
		/*Minute and hour conversion from string to integer*/
		hour = (user_input[0] - '0');
		minute = (10 * (user_input[2] - '0')) + (user_input[3] - '0');
	}
	/*Check for input time with string length of five, ex: 01:45*/
	if ( size == 5 )
	{
		/*The initial input time has to be a positive number and it can only be 0-9 which is the same for both string length of four or five*/
		if (user_input[0] < '0' || user_input[0] > '9')
		{
			throw TimeFormatMistake();
		}
		/*Checking for the second element if it is valid number*/
		if (user_input[1] < '0' || user_input[1] > '9')
		{
			throw TimeFormatMistake();
		}
		/*Since the input from the user is 01:45 format rather than 1:45, the third element in the string has to be
		':'*/
		if (user_input[2] != ':') 
		{
			throw TimeFormatMistake();
		}
		if (user_input[3] < '0' || user_input[3] > '9') 
		{
			throw TimeFormatMistake();
		}
		if (user_input[4] < '0' || user_input[4] > '9') 
		{
			throw TimeFormatMistake();
		}
		/*Minute and hour conversion from string to integer*/
		/*The format is now xx:xx, the second elemnt has to be converted to integer as well*/
		hour = (10 * (user_input[0] - '0')) + (user_input[1] - '0');
		/*Simialr to the previous computation for input time of length 4 except now it has string input_time lnegth of
		five therefore, increment each time by one*/
		minute = (10 * (user_input[3] - '0')) + (user_input[4] - '0');
	}
	/*After the conversion, check if the converted integer value of hour and minute is valid*/
	if ((hour < 0 || hour > 24) || (minute < 0 || minute > 59)) 
	{
		throw TimeFormatMistake();
	}
}