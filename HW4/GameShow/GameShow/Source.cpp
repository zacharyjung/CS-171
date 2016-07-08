#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

void setupDoors(char &door1, char &door2, char &door3);
void result(char door1, char door2, char door3, int &doorPlayer);
void pickDoorChoices(char door1, char door2, char door3, int &doorPlayer, int &doorMonty);
void chart(double correct, double incorrect);
double correct=0, incorrect=0;//Global Variable so I don't need to return anything
/*This function is used to seed the rand() command and to call the setupDoors function 10,000 times. Then calls the chart function to display the percentages*/
void main()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
	int count = 0;
	char door1='a', door2='a', door3='a';
	do {
		setupDoors(door1, door2, door3);
		count++;
	} while (count < 10000);
	chart(correct, incorrect);
	
}
/* This function randomly generates where the location of where the car is behind and where the goats are*/
void setupDoors(char &door1, char &door2, char &door3)
{
	int n,doorPlayer=0,doorMonty=0;
	n = rand() % 3 + 1;
	if (n == 1)
	{
		door1 = 'C';
		door2 = 'G';
		door3 = 'G';
	}
	else if (n == 2)
	{
		door1 = 'G';
		door2 = 'C';
		door3 = 'G';
	}
	else if (n == 3)
	{
		door1 = 'G';
		door2 = 'G';
		door3 = 'C';
	}
	pickDoorChoices(door1, door2, door3, doorPlayer, doorMonty);
}
/*This function randomly assigns the player a door. Then based on the door the player chooses Monty is randomly given a number which can't be the door the player
chooses or the door that has the car behind it*/
void pickDoorChoices(char door1, char door2, char door3, int &doorPlayer, int &doorMonty)
{
	doorPlayer = rand() % 3 + 1;
	if (door1 == 'C')
	{
		if (doorPlayer == 1)
		{
			doorMonty = rand() % 2 + 2;
		}
		if (doorPlayer == 2)
		{
			doorMonty = 3;
		}
		if (doorPlayer == 3)
		{
			doorMonty = 2;
		}
	}
	else if (door2 == 'C')
	{
		if (doorPlayer == 1)
		{
			doorMonty = 3;
		}
		if (doorPlayer == 2)
		{
			do
			{
				doorMonty = rand() % 3 + 1;
			} while (doorMonty == 2);
		}
		if (doorPlayer == 3)
		{
			doorMonty = 1;
		}
	}
	else if (door3 == 'C')
	{
		if (doorPlayer == 1)
		{
			doorMonty = 2;
		}
		if (doorPlayer == 2)
		{
			doorMonty = 1;
		}
		if (doorPlayer == 3)
		{
			doorMonty = rand() % 2 + 1;
		}
	}
	result(door1, door2, door3, doorPlayer);
	
}
/*This function counts the amount of correct and incorrect doors the user picked for all 10,000 times the game was played*/
void result(char door1, char door2, char door3, int &doorPlayer)
{
	if (door1 == 'C'&&doorPlayer == 1)
	{
		correct++;
	}
	else if (door2 == 'C' && doorPlayer == 2)
	{
		correct++;
	}
	else if (door3 == 'C'&& doorPlayer == 3)
	{
		correct++;
	}
	else
	{
		incorrect++;
	}
}
/*This function finds the percentages of the incorrect and correct doors selected when swapped and not swapped. Then it displays a chart of the percentages.*/
void chart(double correct, double incorrect)
{
	double correctpercent, incorrectpercent;
	correctpercent = (correct / 10000.0)*100.0;
	incorrectpercent = (incorrect / 10000.0)*100.0;
	cout << "Correct Percentage: " << correctpercent << "%"<<endl;
	cout << "Incorrect Percentage: " << incorrectpercent<<"%" << endl;
	cout << "Switched Correct Percentage: " << 100.0 - (correctpercent)<<"%" << endl;
	cout << "Switched Incorrect Percentage: " << 100.0 - (incorrectpercent)<<"%" << endl;
	char dummy;
	cout << "Type in a character" << endl;
	cin >> dummy;
}