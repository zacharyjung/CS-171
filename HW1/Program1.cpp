/****************************
Zachary Jung
Computer Science 171
Homework 1, Program 1
Last Edited: January 19,2016
*****************************/
#include <iostream>
#include <iomanip>
using namespace std;
/*******************
This program calculates the amount of tuition for five years when given the initial tuition and yearly percentage increase
*******************/

int main()
{

	cout << "What is the initial tuition amount?" << endl;
	long tuition;
	cin >> tuition;
	tuition = tuition * 100; //Turns the tuition into cents

	cout << "What is the percentage of yearly tuition increase?" << endl;
	double percentage;
	cin >> percentage;
	percentage = percentage / 100; // Makes it a percentage

	double year1, year2, year3, year4, year5, total;
	year1 = tuition;
	cout << "Year 1: "<< setprecision(2)<<fixed << year1/100 << endl;

	year2 = (percentage + 1)*(year1); //Calculates year 2
	cout << "Year 2: " << year2/100 << endl;

	year3 = (percentage + 1)*(year2); //Calculates year 3
	cout << "Year 3: " << year3/100 << endl;

	year4 = (percentage + 1)*(year3); //Calculates year 4
	cout << "Year 4: " << year4/100 << endl;

	year5 = (percentage + 1)*(year4);// Calculates year 5
	cout << "Year 5: " << year5/100 << endl << endl;

	total = year1 + year2 + year3 + year4 + year5;
	cout << "Total Tuition: " <<total/100<< endl;

	int dummyval; //To display my output and not close
	cout << "Type anything to exit" << endl;
	cin >> dummyval;

	return 0;
}