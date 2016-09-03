/*
Name:  Christopher Teti                               Z#:23293126
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 9/4/2016                     Due Time:9/04/2016
Total Points: 100
Assignment 2: 

Description:
In this assignment  a program a call management system is implemented.  The program used three functions:
input, output, and process.  The function input gets input from the user, the function process performs
the necessary calculations, and the function output prints the results.
*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
using namespace std;

//Prototypes for your functions: Input, Output, and Process will go here

void Input(string & cell_number, int & relays, int & call_length);
void Output(const string cell_number, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost_of_call);
void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost_of_call, double & tax_rate);

//Function Implementations will go here

///*************************************************************************************
//Name:  Input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, relays, and call_length) from the user.

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS
//FORMAL PARAMETERS ARE: cell_number (string), relays (integer), call_length (integer)
//*************************************************************************************
void Input(string & cell_number, int & relays, int & call_length) // example of all formal parameter using the call by reference mechanism in C++
{
	cout << "Enter your Cell Phone Number: ";
	cin >> cell_number;
	cout << "Enter the number of relay stations: ";
	cin >> relays;
	cout << "Enter the length of the call in minutes: ";
	cin >> call_length;
}

///*************************************************************************************
//Name:  Output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//NOTE: ALL FORMAL PARAMETERS ARE BEING PASSED BY VALUE. ALSO WE USED CONST TO MAKE SURE THEY WOULD NOT BE CHANGED BY MISTAKE
//      USED THE SAMPLE OUTPUT TO HELP YOU FORMAT YOU OUTPUT
void Output(const string cell_number, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost_of_call)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	cout << "the net cost is: " << net_cost << endl;
	cout << "the tax on the call is: " << call_tax << endl;
	cout << "the total cost comes to: " << total_cost_of_call << endl;
	/********************************************/


}

///*************************************************************************************
//Name:  Process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//Note: there are 3 input parameter and 3 output parameters
void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost_of_call, double & tax_rate){
	//this is an example of a stub
 net_cost = relays / 50.0 * .40 * call_length;

	if ((relays >= 1) && (relays <= 5)) {
	tax_rate = 1.00;
}
else if ((relays >= 6) && (relays <= 11)) {
	tax_rate = 3.00;
}

else if ((relays >= 12) && (relays <= 20)) {
	tax_rate = 5.00;
}

else if ((relays >= 21) && (relays <= 50)) {
	tax_rate = 8.00;
}
else {
	tax_rate = 12.00;
}

call_tax = (net_cost * tax_rate) / 100;
total_cost_of_call = net_cost + call_tax;
}

//Here is your driver to test the program
int main()
{
	string user_response = "y";
	string cell_number;
	int relays;
	int  call_length;
	double net_cost;
	double call_tax;
	double total_cost_of_call;
	double tax_rate;

	while (user_response == "y" || user_response == "Y") {

		Input(cell_number, relays, call_length);
		Process(relays, call_length, net_cost, call_tax, total_cost_of_call, tax_rate);
		Output(cell_number, relays, call_length, net_cost, call_tax, total_cost_of_call);

		cout << "Would you like to do another calculation (Y or N): " << endl;
		cin >> user_response;
	}
	return 0;
}
