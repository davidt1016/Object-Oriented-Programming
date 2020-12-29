/**
* 
* @author David, Teng
* @Date  06/26/2018
* @version 1.0
* 				The program will have multiple classes that are derived from
*				the Vehicle class. The vehicle class will contain the information of the most basic information
*				and the derived class Truck will have all of the functions from the base class. Similarly, the Person
*				Followed up by the Person class, which is derived from the Vehicle class.
*
*/
//
// _____ David, Teng ____      _____June 26/2018____________
//

#include <iostream>
#include <string>

using namespace std;

/*Classes Declaration and Definitions*/
/*A Person class that stores the information about the owner of the vehicle*/
class Person
{
	public:
		/*Constructor*/
		Person();
		Person(string theName);
		/*Copy Constructor*/
		Person(const Person& theObject);
		/*Mutator Function*/
		void updateName(string Owner);
		/*Accessor Function*/
		string getName();
		/*Overloading operator*/
		Person& operator=(const Person& rtSide);
		friend istream& operator >>(istream& inStream,
			Person& personObject);
		friend ostream& operator <<(ostream& outStream,
			const Person& personObject);
		/*Private member variables*/
	private:
		string name;
};
/*Creating a base class called Vehicle*/
class Vehicle
{
	public:
		/*Default Constructor*/
		Vehicle();
		Vehicle(Person owner,string manufacturer, int cylinder);
		/*Copy Constructor*/
		Vehicle(const Vehicle& CopyVehicle);

		/*Mutator Functions*/
		void updateowner(Person ownerVehicle);
		void updatemanufacturer(string carmaker);
		void updatecylinder(int cylinderofVehicle);

		/*Accessor Functions*/
		/*Accessing the person class*/
		Person getowner() const;
		int getcylinder();
		string getmanufacturer();

		/*Overloading Operator*/
		friend ostream& operator << (ostream& outStream, const Vehicle& VehicleOut);

	/*Variables are stored under private to only allow accessor function to access the variable stored under private*/
	private:
		int cylinderofvehicle;
		string manufacturer_c;
		Person ownerofVehicle;
};
/*A derived class of class Vehicle with a few additional functions and features*/
class Truck : public Vehicle
{
	public:
		/*Default Constructor*/
		Truck();
		/*Constructor for storing all the required information about the vehicle*/
		Truck(Person truckowner, string Manufacture, int cylinderofTruck, double loading, int towing);
		/*Copy Constructor*/
		Truck(const Truck& theObject);

		/*Mutator Functions*/
		void updateLoad(double update_l);
		void updateTowing(int update_c);
		/*Accessor Functions*/
		double getLoad();
		int getTowing();
		/*Overloading operator*/
		Truck& operator=(const Truck& CopyTruck);

		/*Private Member Variables*/
	private:
		int towing_capacity;
		double loading_capacity;
};
int main()
{
	/*Variables Declaration*/
	string manufacture_name, owner_name, truck_name, t_owner_name;
	int cylinderofcar, towing_cap, cylinderoftruck;
	double load;

	/*Creating objects for vehicle, truck, and owner */
	Truck truck1;
	Person owner_t;

	/*Basic Input from the user*/
	cout << "Enter basic information for your car and truck" << endl << endl;
	cout << "Enter owner name of your car: ";
	cin >> owner_name;
	Person owner_c(owner_name);
	cout << "Enter the manufacturer of the car: ";
	cin >> manufacture_name;
	cout << "Enter the cylinder of the car: ";
	cin >> cylinderofcar;
	/*Storing all the information in class Vehicle*/
	Vehicle car1(owner_c, manufacture_name, cylinderofcar);
	cout << endl;
	/*Now allowing the user to input all the information for their truck*/
	cout << "Enter the name of the truck owner: ";
	cin >> t_owner_name;
	owner_t.updateName(t_owner_name);
	truck1.updateowner(owner_t);
	cout << "Enter the manufacturer of the truck: ";
	cin >> truck_name;
	truck1.updatemanufacturer(truck_name);
	cout << "Enter the number of cylinders for the truck: ";
	cin >> cylinderoftruck;
	truck1.updatecylinder(cylinderoftruck);
	cout << "Enter the loading capacity of the truck: ";
	cin >> load;
	truck1.updateLoad(load);
	cout << "Enter the towing capacity of the truck: ";
	cin >> towing_cap;
	truck1.updateTowing(towing_cap);
	cout << endl << endl;
	cout << "This is the summary of your information" << endl;
	cout << car1;
	cout << endl;
	cout << "Owner of the truck is:" << truck1.getowner();
	cout << "Truck Manufacturer: " << truck1.getmanufacturer() << endl;
	cout << "Truck has " << truck1.getcylinder() <<" cylinders." << endl;
	cout << "Truck loading and towing capacity are: " << truck1.getLoad() << ", " << truck1.getTowing() << " ,respectively." << endl;
	

	/*Test Program*/
	cout << endl << "---------------------------Test Driver Program---------------------------" << endl;
	
	/*Anticipated Program*/
	cout << "The program will have a fixed input to test out if the result is the same as anticipated." << endl << endl;
	cout << "This is the summary of your information" << endl;
	cout << "Owner of the vehicle is: John \n";
	cout << "Car Manufacturer: Porsche\n";
	cout << "Cylinder of the vehicle is: 10\n\n";
	cout << "Owner of the truck is: Steve" << endl;
	cout << "Truck Manufacturer: GMC" << endl;
	cout << "Truck has 8 cylinders." << endl;
	cout << "Truck loading and towing capacity are 5 and 10, respectively." << endl << endl;

	cout << "Setting test_truck1 to test_truck2 using  overloading '=' operator" << endl;
	cout << "test_truck2 should have the following information: " << endl;
	cout << "Owner of the truck is: Steve" << endl;
	cout << "Truck Manufacturer: GMC" << endl;
	cout << "Truck has 8 cylinders." << endl;
	cout << "Truck loading and towing capacity are 5 and 10, respectively." << endl << endl << endl;

	/*Actual output of the program*/
	cout << "The actual output of the program with all of the function calls are as follow: " << endl << endl;
	cout << "This is the summary of your information" << endl;
	Person owner_test("John");
	Vehicle test;
	test.updatemanufacturer("Porsche");
	test.updatecylinder(10);
	test.updateowner(Person("John"));
	cout << test;
	Person test_truck;
	Truck test_truck1, test_truck2;
	/*Function calls*/
	test_truck.updateName("Steve");
	test_truck1.updateowner(test_truck);
	test_truck1.updatemanufacturer("GMC");
	test_truck1.updatecylinder(8);
	test_truck1.updateLoad(5);
	test_truck1.updateTowing(10);
	/*Testing if the output matches*/
	cout << "Owner of the truck is:" << test_truck1.getowner();
	cout << "Truck Manufacturer: " << test_truck1.getmanufacturer() << endl;
	cout << "Truck has " << test_truck1.getcylinder() << " cylinders." << endl;
	cout << "Truck loading and towing capacity are: " << test_truck1.getLoad() << ", " << test_truck1.getTowing() << " ,respectively." << endl;

	cout << "After setting test_truck1 to test_truck2 " << endl << endl;
	test_truck2 = test_truck1;
	cout << "Owner of the truck is:" << test_truck2.getowner() << endl;
	cout << "Truck Manufacturer: " << test_truck2.getmanufacturer() << endl;
	cout << "Truck has " << test_truck2.getcylinder() << " cylinders." << endl;
	cout << "Truck loading and towing capacity are: " << test_truck2.getLoad() << ", " << test_truck2.getTowing() << " ,respectively." << endl;
	cout << "---------------------------------END OF TEST DRIVER PROGRAM.---------------------------------" << endl;
	/*End of Test Driver program*/

	system("pause");
	return 0;
}

/*-------------------Function Definitions and Constructors for all Classes-------------------*/

/*----------------------------Class Person----------------------------*/
/*Default Constructor*/
Person::Person() 
{
	/*Initializing the name as NA until the user enter the name*/
	name = "NA";
}
Person::Person(string theName) 
{ 
	name = theName;
}
/*Person class copy constructor*/
Person::Person(const Person& theObject)  
{
	name = theObject.name;
}
/*Mutator Function*/
void Person::updateName(string Owner) 
{
	name = Owner;
}
/*Accessor Function*/
string Person::getName() 
{
	return name;
}
/*Setting the object rtSide to the name and return the pointer that points toward name*/
Person& Person::operator=(const Person& rtSide)
{
	this->name = rtSide.name;
	return *this;
}
istream& operator >>(istream& inStream, Person& personObject)
{
	string name_owner;
	inStream >> name_owner;
	personObject.name = name_owner;
	return inStream;
}
ostream& operator <<(ostream& outStream, const Person& personObject)
{
	string name_o = personObject.name;
	outStream << name_o << endl;
	return outStream;
}


/*----------------------------Class Vehicle----------------------------*/
/*Default constuctor*/
Vehicle::Vehicle()
{
	cylinderofvehicle = 0;
	manufacturer_c = "NA";
}
Vehicle::Vehicle(Person owner, string manufacturer, int cylinder ) 
{	
	cylinderofvehicle = cylinder;
	manufacturer_c = manufacturer;
	ownerofVehicle = owner;
	
}
/*Copy Constructor*/
Vehicle::Vehicle(const Vehicle& CopyVehicle)
{	
	/*Creating a new objecct class called CopyVehicle and accesss each variable and store each of them
	into the corresponding variable in private*/
	cylinderofvehicle = CopyVehicle.cylinderofvehicle;
	manufacturer_c = CopyVehicle.manufacturer_c;
	ownerofVehicle = CopyVehicle.ownerofVehicle;
}
/*Mutator Funtions*/
void Vehicle::updateowner(Person ownerVehicle)
{
	ownerofVehicle = ownerVehicle;
}
void Vehicle::updatemanufacturer(string carmaker)
{
	manufacturer_c = carmaker;
}
void Vehicle::updatecylinder(int cylinderofVehicle)
{
	cylinderofvehicle = cylinderofVehicle;
}
/*Accessor Functions*/
Person Vehicle::getowner() const
{
	return ownerofVehicle;
}
string Vehicle::getmanufacturer() 
{
	return manufacturer_c;
}
int Vehicle::getcylinder() 
{
	return cylinderofvehicle;
}
/*Overloading Operator <<*/
/*For output the data*/
ostream& operator << (ostream& outStream, const Vehicle& VehicleOut)
{
	/*Number of cylinder has to be greater than 1*/
	if (VehicleOut.cylinderofvehicle <= 0)
	{
		outStream << "Invalid Cylinder Number!!" << endl;
	}
	outStream <<"Owner of the Vehicle is: " << VehicleOut.ownerofVehicle << endl<<  "Car Manufacturer: " << VehicleOut.manufacturer_c <<
		endl <<"Cylinder of the Vehicle is: "<< VehicleOut.cylinderofvehicle << endl;
	return outStream;
}


/*----------------------------Class Truck----------------------------*/
/*Default constructor*/
/*Initializing the private member variables*/
Truck::Truck() 
{
	Vehicle();
	towing_capacity = 0;
	loading_capacity = 0.0;
}
Truck::Truck(Person truckowner, string Manufacture, int cylinderofTruck, double loading, int towing)
{
	Vehicle(truckowner, Manufacture, cylinderofTruck);
	loading_capacity = loading;
	towing_capacity = towing;
}
/*Copy Constructor for Truck Class*/
Truck::Truck(const Truck& CopyTruck) 
 {
	loading_capacity = CopyTruck.loading_capacity;
	towing_capacity = CopyTruck.towing_capacity;
}
/*Mutator Functions*/
void Truck::updateLoad(double update_l)
{
	loading_capacity = update_l;
}
void Truck::updateTowing(int update_c)
{
	towing_capacity = update_c;
}
/*Accessor Function*/
int Truck::getTowing()
{
	return towing_capacity;
}
double Truck::getLoad()
{
	return loading_capacity;
}

/*Overloading operator =*/

Truck& Truck::operator=(const Truck& rtSide) {

	this->loading_capacity = rtSide.loading_capacity;
	this->towing_capacity = rtSide.towing_capacity;
	(*this).Vehicle::operator=(rtSide);
	return *this;
}

