/**
* 
* @author David, Teng
* @Date  06/17/2018
* @version 1.0
* The program will implement a Queue for stimulation of
* the customer arrivals at DMV counter service. Starting with number 1 as starting ticket and 
* for every new custome, the number of ticket will increment accordingly. Whenever a service agent
* is available, the first customer in the wait line will be called. The queue data will consist of
* ticket number and the time stampd. The program will save the length of the wait time of the last three 
* customers spent on waiting in line. If it is an empty queue, print out it is empty.
*
*/
//
// _____ David, Teng ____      _____June 17/2018____________
//

/*The code have been modified based on the sample dsiplay from 13.21 to 13.23 from the textbook
of "Problem Solving with C++ nineth edition by Walter Savitch from page 772-776------------1*/

#include <cstddef>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

/*Queue structure definition*/
struct QueueConnect
{
	/*Structure of a queue consist information regarding the ticket number and timestamp
	at which the customer entered the lineup*/
	int ticket_number;
	long timestamp;
	/*Queue pointer*/
	QueueConnect *connect;
};
typedef QueueConnect* Queue_DMV;

/*Queue class definition*/
class Queue
{
	/*Constructor, deconstructor, accessor, and mutator functions will be stored under the public decalaration*/
	public:
		/*Constructors and Deconstructors for deleting and initializing member variables*/
		/*Constructor*/
		Queue();
		/*Deconstructor*/
		~Queue();
		/*Copy Constructor*/
		Queue(const Queue&copyConstructor);
		
		/*Member function definitions*/
		/*Checking if the queue is empty or not*/
		bool empty() const;
		/*Functions for the functionalities for the DMV serive*/
		/*Function for each customer entering the queue along with the position that each customer is at as
		function parameter*/
		void customer_enter(int position, long arrival);
		/*Dequeuing the line by removing the first customer in line*/
		long serviceAvailable();
		/*Output function for the result of the wait and approximation of the wait for the next customer*/
		void OutputResult(int customer, long waiting, long departure );
		/*Output function for the result of the average function*/
		void OutputAverage(int avg, int customer1);

		/*Accessor function for the timestampd data*/
		long  getTime();
		/*Mutator functions for storing the value of arrival time*/
		void updateArrival(long time_a);
		/*Accessor functions for storing the value of arrival time*/
		long getArrival();
		/*Mutator functions for storing the value of departure time of the line*/
		void updateDeparture(long time_d);
		/*Accessor functions for storing the value of departure time of the line*/
		long getDeparture();
		/*Mutator function for storing the average wait time of the last three customers*/
		int updateAverageTime(int customer_in_line, int &counter, long wait_duration, double *time);
		/*Accessor function for accessing the average wait time for the last three customers*/
		int getAverageTime();
	

	private:
		/*Private member variables*/
		Queue_DMV front_end;
		Queue_DMV back_end;
		int number_of_customer;
		long arrival;
		long departure;
		long average_time;
};


int main()
{
	/*Creating an object called DMV for the class Queue*/
	Queue DMV;
	
	/*User input*/
	int choice = 0;
	int customer_number1 = 1;
	int customer_number2 = 1;
	long enter = 0;
	long leave = 0;
	long wait = 0;
	int average = 0;
	double time1[3] = { 0 };
	int count1 = 0;
	/*The Queue will always be empty in the beginning; therefore, no need to check if it is empty through if statements
	with the parameter of DMV.empty()*/
	cout << "The line is empty." << endl;
	/*Continuing on the loop as long as the user does not enter 3 to quit the program*/
	do 
	{
		cout << "Enter '1' to simulate a customer's arrival, '2' to help the next customer, or '3' to quit. " << endl;
		cin >> choice;
		/*Checking if the user enters 1 or 2 */
		/*If the user types in 1 then add customer to the line*/
		if (choice == 1)
		{
			enter = static_cast<long>(time(NULL));
			DMV.customer_enter(customer_number1, enter);
			customer_number1++;
		}
		/*If the choice is 2, the customer is being helped. Therefore, it will be removed from the queue*/
		if (choice == 2)
		{	
			/*Variables for computing the entering time */
			enter = DMV.getTime();
			/*Accessing the time at which it removes a person from the queue*/
			leave = DMV.serviceAvailable();
			/*wait is equivalent to the difference of time that the user enter the line and exit the line*/
			wait = leave - enter;
			/*Computing the average that the next customer has to wait*/
			average = DMV.updateAverageTime(customer_number2, count1, wait, time1);
			/*Calling the output function for outputting the time at which it leaves the queue*/
			DMV.OutputResult(customer_number2, wait, leave);
			/*Calling member function for the estimation of waiting time*/
			DMV.OutputAverage(average, customer_number2);
			customer_number2++;
		}
	} while (choice != 3);
	/*Destructor*/
	DMV.~Queue();

	cout  << "----------------------End of the program----------------------" << endl << endl;
	cout << "Entering test driver program!" << endl;
	Queue test_DMV;

	/*User input*/
	
	long test_enter1 = 0;
	long test_enter2 = 0;
	long test_enter3 = 0;
	long test_leave1 = 0;
	long test_leave2 = 0;
	long test_leave3 = 0;
	long test_wait1 = 0;
	long test_wait2 = 0;
	long test_wait3 = 0;
	int test_average1= 0;
	int test_average2= 0;
	int test_average3= 0;
	double test_time1[3] = { 0 };
	int test_count1 = 0;


	cout << "Test program will be based on STUD test program, which fixed input will be passed in and no involvement of user input." << endl;
	cout << "Three customers will be in the queue for the test" << endl;
	cout << "-------------------Anticipated output of the program-------------------" << endl;
	cout << "The line is empty." << endl;
	test_enter1 = static_cast<long>(time(NULL));
	cout << "Customer 1 entered the queue at time " << test_enter1 << "." << endl;
	test_enter2 = static_cast<long>(time(NULL));
	cout << "Customer 2 entered the queue at time " << test_enter2 << "." << endl;
	test_enter3 = static_cast<long>(time(NULL));
	cout << "Customer 3 entered the queue at time " << test_enter3 << "." << endl;

	test_leave1 = static_cast<long>(time(NULL));
	test_wait1 = test_leave1 - test_enter1;
	cout << "Customer 1 is being helped at time " << test_leave1 << "." << endl;
	cout << "Wait time = " <<test_wait1 << " seconds." << endl;
	cout << "The estimated wait time for customer 1 is " << test_wait1 << " seconds." << endl;
	test_leave2 = static_cast<long>(time(NULL));
	test_wait2 = test_leave2 - test_enter2;
	cout << "Customer 2 is being helped at time " << test_leave2 << "." << endl;
	cout << "Wait time = " << test_wait2 << " seconds." << endl;
	cout << "The estimated wait time for customer 2 is " << (test_wait1+test_wait2)/2 << " seconds." << endl;

	test_leave3 = static_cast<long>(time(NULL));
	test_wait3 = test_leave3 - test_enter3;
	cout << "Customer 3 is being helped at time " << test_leave3<< "." << endl;
	cout << "Wait time = " << test_wait3 << " seconds." << endl;
	cout << "The estimated wait time for customer 3 is " << (test_wait1 + test_wait2 +test_wait3) / 3 << " seconds." << endl;


	cout << "The actual output of the function with all the function calls" << endl << endl;
	
		test_DMV.customer_enter(1, test_enter1);
		test_DMV.OutputResult(1, test_wait1, test_leave1);
		test_average1 = DMV.updateAverageTime(1, count1, test_wait1, test_time1);
		test_DMV.OutputAverage(test_leave1, 1);

		test_DMV.customer_enter(2, test_enter2);
		test_DMV.OutputResult(2, test_wait2, test_leave2);
		test_average2 = DMV.updateAverageTime(2, count1, test_wait2, test_time1);
		test_DMV.OutputAverage(((test_leave1+test_leave2)/2), 2);

		test_DMV.customer_enter(3, test_enter3);
		test_DMV.OutputResult(3, test_wait3, test_leave3);
		test_average3 = DMV.updateAverageTime(3, count1, test_wait3, test_time1);
		test_DMV.OutputAverage( ((test_leave1 + test_leave2 + test_leave3) / 3), 3);

	//Test Driver Program
	system("pause");
}

/*Class construcotrs and deconstructors*/

/*Initializing the private member variables*/
Queue::Queue() : front_end(NULL), back_end(NULL), average_time(0), number_of_customer(0) , arrival(0), departure(0) 
{
}
/*Copy Constructor for storing data in case the original data was removed out of scope and causing an error*/
Queue::Queue(const Queue&copyConstructor)
{
	/*Checking if the queue is empty*/
	if (copyConstructor.empty())
	{
		/*Setting everything to NULL */
		front_end = NULL;
		back_end = NULL;
	}
	else
	{
		/*Not empty then create series of nodes to copy the data*/
		/*Iterating through each nodes in the queue*/
		Queue_DMV tmp_old = copyConstructor.front_end;
		Queue_DMV tmp_new;
		/*Creating a new node to store all the old data*/
		back_end = new QueueConnect; 
		back_end->ticket_number = tmp_old->ticket_number;
		back_end->timestamp = tmp_old->timestamp;
		back_end->connect = NULL;
		front_end = back_end;
		tmp_old = tmp_old->connect;

		/*Iterating through each node and store all the old data into a new set of Queue list*/
		while (tmp_old != NULL)
		{
			tmp_new = new QueueConnect;
			tmp_new->ticket_number = tmp_old->ticket_number;
			tmp_new->timestamp = tmp_old->timestamp;
			tmp_new->connect = NULL;
			back_end->connect = tmp_new;
			back_end = tmp_new;
			tmp_old = tmp_old->connect;
		}
	}

}
/*Deconstructor for Queue*/
Queue::~Queue()
{
	Queue_DMV tmp = front_end;
	/*Checking if it is empty*/
	if (empty())
	{
		cout << "The wait line is already empty!" << endl;
		exit(0);
	}
	else
	{
		/*If it is not empty, delete each element in the queue until it reaches NULL, which is the
		last element*/
		while ( tmp != NULL )
		{
			tmp = tmp->connect;
			delete tmp;
		}
		if (front_end == NULL)
		{
			back_end = NULL; /*Removing the last element*/
		}
	}
}
/*--------------Function definitions-----------------*/
/*Functions for checking if the queue is empty or not*/
bool Queue::empty() const
{
	return (front_end == NULL);
}

/*Mutator and Accessor Function Definitions*/

long Queue::getTime()
{
	return front_end->timestamp;
}


/*Mutator function for updating the arrival time*/
void Queue::updateArrival(long time_a)
{
	arrival = time_a;
}
/*Accessor function for obtaining the arrival time value*/
long Queue::getArrival()
{
	return arrival;
}
/*Mutator function for updating the arrival time*/
void Queue::updateDeparture(long time_d)
{
	departure = time_d;
}
/*Accessor function for obtaining the arrival time value*/
long Queue::getDeparture()
{
	return departure;
}
/*Accessor function for gaining the average waiting time*/
int Queue::getAverageTime()
{
	return average_time;
}


/*Precondition: The customer will be given a ticket number based on their position in the lineup
  Postcondition: The function will add customer to the queue according to their position*/
/*The following code have been modified and used from the textbook that has been defined at the beginning
of the program.*/
void Queue::customer_enter(int position, long arrival)
{
	/*If it is empty, creating a new node for the queue*/
	if (empty())
	{
		front_end = new QueueConnect;
		/*Queue list will include data for ticket number and timestamp for the arrival time of each customer*/
		front_end->ticket_number = position;
		front_end->timestamp = arrival;
		front_end->connect = NULL;
		back_end = front_end;
	}
	else
	{
		/*If the node is not empty, then create another node after the original node meanwhile keeping the connection between
		each node*/
		Queue_DMV tmp;
		tmp = new QueueConnect;
		tmp->ticket_number = position;
		tmp->timestamp = arrival;
		tmp->connect = NULL;
		back_end->connect = tmp;
		back_end = tmp;
	}
	/*Printing out the message for customer arrival time and its position*/
	cout << "Customer " << position << " entered the queue at time " << arrival << "." << endl;
}
/*Precondition: The queue is not empty.
  PostCondition: The first customer in line will be removed and moved onto the second customer following the FIFO concept.*/
long Queue::serviceAvailable()
{
	/*IF the queue is empty output the following message*/
	if (empty())
	{
		cout << "The wait line is empty!" << endl;
		exit(0);
	}
	/*Not empty then help the first person in line and remove the first person off the queue*/
	
		front_end->timestamp = static_cast<long>(time(NULL));
		long wait_time = 0;
		wait_time = front_end->timestamp;
		
		/*Removing the first person off the line by replacing the connection between first and second nodes*/
		Queue_DMV remove_line = front_end;
		front_end = front_end->connect;
		/*If it is the last node then remove it and point it to NULL*/
		if (front_end == NULL)
		{
			back_end = NULL;
		}
		/*Deleting the node*/
		delete remove_line;

	return wait_time;
}

/*Precondition: Assuming that the line is not empty and it will compute the average time
PostCondition: The function will update the variable average_time in private member variables*/
int Queue::updateAverageTime(int customer_in_line, int &counter, long wait_duration, double *time)
{
	/*For more than three customers, shift to the last three customers*/
	if (customer_in_line > 3)
	{
		int i = 0;
		while (i < 2)
		{
			/*Moving down the array*/
			time[i] = time[i + 1];
			i++;
		}
		time[2] = wait_duration;
		average_time = ((time[0] + time[1] + time[2]) / 3);
	}
	/*Exactly three customers in line*/
	if (customer_in_line == 3)
	{
		time[counter] = wait_duration;
		/*Exactly three customer will require the average of three value stored from time[0]-time[2]*/
		average_time = ((time[0] + time[1] + time[2]) / 3);
	}
	/*Two customers now*/
	if (customer_in_line == 2)
	{
		time[counter] = wait_duration;
		/*since there are two people in the line, the wait time will be equivalent to the mean of the wait time
		for first and second customer*/
		average_time = ((time[0] + time[1]) / 2);
		counter++;
	}
	/*Only one customer, the wait time will be the amount of time that the first customer have waited*/
	if (customer_in_line == 1)
	{
		/*Storing the wait time into array of time[0]*/
		time[counter] = wait_duration;
		average_time = wait_duration;
		/*Incrementing the counter by 1 */
		counter++;
	}
	return average_time;
}



/*Precondition: The number of customer along with waiting time and departure time are passed as function parameters
  PostConditon: The function will output how long the customer has waited and an estimated of how long the next customer has to wait*/
void Queue::OutputResult(int customer, long waiting, long departure)
{
	int count = 0;
	cout << "Customer " << customer << " is being helped at time " << departure <<  "." <<endl;
	cout << "Wait time = " << waiting  <<" seconds." << endl;
}
/*Precondition: The Average value and the customer number is passed in as function parameter
  PostCondition: The function will produce the corresponding messages according to the customer number and
 an estimated wait time*/
void Queue::OutputAverage(int avg , int customer1 )
{
	cout << "The estimated wait time for customer " << customer1 + 1 << " is " << getAverageTime() << " seconds." << endl;
}