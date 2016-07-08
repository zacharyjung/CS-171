/*Zachary Jung
February 17,2016*/
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
//Prototypes for the functions
void computeBloodAlcoholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC);
string impairment(double bac);
int promptForInteger(string const &message, int lower, int upper);
char promptForMorF(string const &message);
void showImpairmentChart(int weight, int duration, bool isMale);

//This function calculates the Blood Alcohol Content given the gender, weight, number of drinks, and duration since last drink.
void computeBloodAlcoholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC)
{
	//These are the constants used to calculate the blood alcohol content
	const double male = 3.8;
	const double female = 4.5;
	const double drink = .01;
	const double time = (.01 / 40);

	//These set of lines calculate the Male Blood alcohol content and the Female Blood Alcohol Content
	maleBAC = (double)numDrinks / (double)weight*male - time*duration;
	femaleBAC = (double)numDrinks / (double)weight*female - time*duration;

	//If the BAC is below zero the BAC is set to 0 becaue you cant have negative BAC
	if (maleBAC<0)
	{
		maleBAC = 0;
	}
	if (femaleBAC<0)
	{
		femaleBAC = 0;
	}

}
//This function uses the Blood alcohol content to figure out the impairment
string impairment(double bac)
{
	//These are the impairment constants
	const double safe = 0.00;
	const double someImpairment = 0.04;
	const double significantAffected = 0.08;
	const double someCriminalPenalties = 0.10;
	const double deathPossible = 0.30;
	const string SAFE = "Safe To Drive";
	const string SOMEIMPAIR = "Some Impairment";
	const string SIGNIFICANT = "Driving Skills Significantly Affected";
	const string MOST_STATES = "Criminal Penalties in Most US States";
	const string ALL_STATES = "Legally Intoxicated - Criminal Penalties in All US States";
	const string YOURE_DEAD = "Death is Possible!";
	//These lines are returning the statuses of at the BAC
	if (bac == safe)
	{
		return(SAFE);
	}
	else if (bac < someImpairment)
	{
		return(SOMEIMPAIR);
	}
	else if (bac < significantAffected)
	{
		return(SIGNIFICANT);
	}
	else if (bac < someCriminalPenalties)
	{
		return(MOST_STATES);
	}
	else if (bac <= deathPossible)
	{
		return(ALL_STATES);
	}
	else
	{
		return(YOURE_DEAD);
	}
}
//This function asks the user for their weight or duration from the last time you had a drink and returns it to the main function
int promptForInteger(string const &message, int lower, int upper)
{
	int number;
	//This loop returns the number the user entered as long as it is in between the lower and upper bound
	do
	{
		cout << message << endl;
		cin >> number;
		if ((number >= lower) && (number <= upper))
		{
			return(number);
		}
		else
		{
			return 0;
		}

	} while ((number<lower) && (number>upper));
}


//This function asks the user to say if they are male or female
char promptForMorF(string const &message)
{
	char gender;
	//This loop returns the gender of the user as long as a F or M is inputted
	int test;
	do
	{
		cout << message << endl;
		cin >> gender;

		if ((gender == 'F') || (gender == 'M'))
		{
			return(gender);
		}
	} while (gender != 'F' || 'M');
}
//This function shows the chart of impairment and the blood alcohol concentration
void showImpairmentChart(int weight, int duration, bool isMale)
{
	double maleBAC, femaleBAC, bac;
	int count = 1;
	if (isMale == true)
	{
		cout << weight << " pounds, Male" << duration << " minutes since last drink" << endl;
		cout << "# of drinks     BAC status" << endl;

	}
	else if (isMale == false)
	{
		cout << weight << " pounds, female" << duration << " minutes since last drink" << endl;
		cout << "# of drinks     BAC status" << endl;
	}
	//This loop outputs the BAC for the amount of drinks up to 10
	do
	{
		computeBloodAlcoholConcentration(count, weight, duration, maleBAC, femaleBAC);
		if (isMale == true)
		{
			bac = maleBAC;
			cout << setw(8) << count << " " << setprecision(3) << fixed << bac << " " << impairment(bac) << endl;
		}
		else if (isMale == false)
		{
			bac = femaleBAC;
			cout << setw(8) << count << " " << setprecision(3) << fixed << bac << " " << impairment(bac) << endl;
		}

		count++;
	} while (count <= 10);
	char dummy;
	cout << "Type a character" << endl;
	cin >> dummy;
}
//The main function calls all of the functions back to get the gender,weight, and duration
int main()
{
	int duration, weight, lower = 0, upper = 1000, test;
	char gender;
	bool Maleorfemale;
	string message = "What is your weight?", message1, message2;
	weight = promptForInteger(message, lower, upper);
	message1 = "How recently did you have your last drink?";
	duration = promptForInteger(message1, lower, upper);
	message2 = "Are you Male of Female (M or F)?";

	gender = promptForMorF(message2);

	if (gender == 'M')
	{
		Maleorfemale = true;
	}
	if (gender == 'F')
	{
		Maleorfemale = false;
	}

	showImpairmentChart(weight, duration, Maleorfemale);

}