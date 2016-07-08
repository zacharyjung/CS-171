/****************************
Zachary Jung
Computer Science 171
Homework 1, Program 2
Last Edited: January 19,2016
*****************************/
#include <iomanip>
#include <iostream>
using namespace std;
/*********************************************************
This program converts fluid ounces into different units of fluids. It uses the largest units first until all of the fluid ounces are used up.
*********************************************************/
int main()
{
	int fluid_ounces,tablespoons,gills,cups,pints,quarts,gallons,barrels,remainder;
	cout << "How many fluid ounces do you have?" << endl;
	cin >> fluid_ounces;
	cout << fluid_ounces << " fluid ounces can be divided into: " << endl;
	//Converted all of the values to fluid ounces
	//tablespoons = twice as much fluid ounces
	//gills = 4x fl oz
	//cups = 8 fl oz
	//pints = 16 fl oz
	//quarts = 32 fl oz
	//gallons = 128 fl oz
	//barrels = 5376 fl oz
	//starting at the largest unit and using modulus to find the remainder
	barrels = fluid_ounces / 5376;
	remainder = fluid_ounces % 5376;
	gallons = remainder / 128;
	remainder = remainder % 128;
	quarts = remainder / 32;
	remainder = remainder % 32;
	pints = remainder / 16;
	remainder = remainder % 16;
	cups = remainder / 8;
	remainder = remainder % 8;
	gills = remainder / 4;
	remainder = remainder % 4;
	tablespoons = remainder * 2;
	remainder = remainder % 2;
	fluid_ounces = remainder;
	//Outputing the amounts of each unit
	cout << barrels << " Barrel(s)" << endl;
	cout << gallons << " Gallon(s)" << endl;
	cout << quarts << " Quart(s)" << endl;
	cout << pints << " Pint(s)" << endl;
	cout << cups << " Cup(s)" << endl;
	cout << gills << " Gill(s)" << endl;
	cout << tablespoons << " Tablespoon(s)" << endl;
	//Used so the program doesn't close automatically
	char dummy;
	cout << "Type a character to exit" << endl;
	cin >> dummy;
	return (0);
}