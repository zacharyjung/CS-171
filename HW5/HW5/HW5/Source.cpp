/*Zachary Jung
March 12,2016
HW5*/
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
void reportStatus(ostream &os, double time, double height, double velocity, double fuel, string name);
void updateStatus(double &velocity, double burnAmount, double&fuelRemaining, double &height);
void introduction(istream &is, ostream &os, string target, string replacement);
void touchdown(double &elapsedTime, double &velocity, double&burnAmount, double &height);
void finalAnalysis(ostream &os, double velocity);

/*This function asks the user for if they want to see the instructions and how much fuel to burn. Also it 
calls the functions. */
int main()
{
	double velocity = 50, altitude = 1000, fuel, tank=150;
	double acceleration = 5;
	double seconds = 1.0;
	char Answer;
	//This defines the output file and the input file.
	string outputname;
	cout << "What do you want the ouput file name to be" << endl;
	cin >> outputname;
	ofstream outputfile(outputname);
	ifstream input("input.txt");
	cout << "Do you want to view the instructions" << endl;
	cin >> Answer;
	//If the answer is Y or y it replaces the the instructions with the replacement word
	if ((Answer == 'Y') || (Answer == 'y'))
	{
		introduction(input, cout, "$SPACECRAFT", "APOLLO");
		input.close();
		input.open("input.text");
		introduction(input, outputfile, "$SPACECRAFT", "APOLLO");
	}
	//This reports the status and updates the status until the altitude hits 0
	do {
		reportStatus(cout, seconds, altitude, velocity, tank, "Apollo");
		reportStatus(outputfile, seconds, altitude, velocity, tank, "Apollo");
		if (tank>0)
		{
			outputfile << "Number of fuel units from 0-30" << endl;
			cin >> fuel;
			if (fuel > tank)
			{
				fuel = tank;
			}
			if ((fuel < 0)||(fuel>30))
			{
				outputfile << "Invalid value" << endl;
			}
			
			else
			{
				updateStatus(velocity, fuel, tank, altitude);
				seconds++;
			}
			
			

		}
		else if (tank <= 0)
		{
			fuel = 0;
			tank = 0;
			outputfile << "****OUT OF FUEL****" << endl;
			updateStatus(velocity, fuel, tank, altitude);
			seconds++;
		}
	} while (altitude > 0);
	if (altitude < 0)
	{
		touchdown(seconds, velocity, fuel, altitude);
		reportStatus(cout, seconds, altitude, velocity, tank, "Apollo");
		reportStatus(outputfile, seconds, altitude, velocity, tank, "Apollo");
		finalAnalysis(cout, velocity);
	}
	return 0;


}
//This function outputs the status,time,height,speed,and fuel.
void reportStatus(ostream &os, double time, double height, double velocity, double fuel, string name)
{
	os << "Status of your " << name << " spacecraft:" << endl;
	os << "Time: " << time << " seconds" << endl;
	os << "Height: " << height << " feet" << endl;
	os << "Speed: " << velocity << " feet/second" << endl;
	os << "Fuel: " << fuel << endl;
}
//This function updates the velocity, fuel burned, fuel left, and height while the altitude is above 0
void updateStatus(double &velocity, double burnAmount, double&fuelRemaining, double &height)
{
	int oldvelocity = velocity;
	fuelRemaining = fuelRemaining - burnAmount;
	velocity = (oldvelocity + 5) - burnAmount;
	height = height - ((oldvelocity + velocity) / 2);
}
//This function outputs the intstructions and replaces the target word with the replacement word.
void introduction(istream &is, ostream &os, string target, string replacement)
{
	string words,first,second;
	
	while (!is.eof())
	{
		getline(is, words, '\n');
		if (!is.eof())
		{
			while (words.find(target) != -1)
			{
				first = words.substr(0, words.find(target) - 1);
				second = words.substr(words.find(target) + target.length(), words.length() - (first.length() + 1 + target.length()));
				words = first+" " + replacement + second;
			}
		
			os << words<<endl;
		}
		
	}
}
//This function updates the time, velocity, amount of fuel burned, and height while the altitude is less than zero.
void touchdown(double &elapsedTime, double &velocity, double&burnAmount, double &height)
{
	double delta;
	delta = (sqrt((velocity*velocity) +( height*(10 - 2 * burnAmount))) - velocity) / (5 - burnAmount);
	elapsedTime = elapsedTime + delta;
	velocity = velocity + (5 - burnAmount)*delta;
	height = 0;
}
//This function outputs the results of the landing based on the velocity.
void finalAnalysis(ostream &os, double velocity)
{
	if (velocity == 0.0)
	{
		os << "Congratulations! A perfect landing!!Your license will be renewed...later." << endl;
	}
	else if (velocity<2.0)
	{
		os << "A little bumpy." << endl;
	}
	else if (velocity<5.0)
	{
		os << "You blew it!!!!!!Your family will be notified...by post." << endl;
	}
	else if (velocity < 10.0)
	{
		os << "Your ship is a heap of junk !!!!!Your family will be notified...by post." << endl;
	}
	else if (velocity < 30.0)
	{
		os << "You blasted a huge crater !!!!!Your family will be notified...by post." << endl;
	}
	else if (velocity < 50.0)
	{
		os << "Your ship is a wreck !!!!!Your family will be notified...by post " << endl;
	}
	else
	{
		os << "You totaled an entire mountain !!!!!Your family will be notified...by post." << endl;
	}
}