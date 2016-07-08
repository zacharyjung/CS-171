/****************************
Zachary Jung
Computer Science 171
Homework 1, Extra Credit
Last Edited: January 19,2016
*****************************/
#include <iomanip>
#include <iostream>
using namespace std;

/*********************************************************
This program converts the time input into different time zones around the world.
*********************************************************/
int main()
{
	int time, honolulu, seattle, london, moscow, hongkong, aukland;
	//Takes the input and stores the value in time
	cout << "What time is it in Philadelphia? (Military time)" << endl;
	cin >> time;
	//Add 2400 so there are no negative times
	time = (time)+2400;
	//Convert time from Philadelphia to the various city's times
	honolulu = (time - 600) % 2400;
	seattle = (time - 300) % 2400;
	london = (time + 500) % 2400;
	moscow = (time + 800) % 2400;
	hongkong = (time + 1200) % 2400;
	aukland = (time + 1700) % 2400;
	//Outputs the times of the cities
	cout << "Honolulu: "<<setw(4)<<setfill('0')<< honolulu << endl;
	cout << "Seattle: " << setw(4) << setfill('0')<<seattle << endl;
	cout << "London: " <<setw(4) << setfill('0') << london << endl;
	cout << "Moscow: " << setw(4) << setfill('0')<<moscow << endl;
	cout << "Hong Kong: " << setw(4) << setfill('0')<< hongkong << endl;
	cout << "Aukland: " << setw(4) << setfill('0')<< aukland << endl;
	//Used so the program doesn't close automatically
	char dummy;
	cout << "Type in a character to exit" << endl;
	cin >> dummy;
	return 0;
}