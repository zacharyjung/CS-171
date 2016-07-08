#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
void reportStatus(ostream &os, double time, double height, double velocity, double fuel, string name);

int main()
{
	double velocity=50, altitude=1000,fuel,tank;
	double acceleration =5;
	int seconds=1; 

		do{
			reportStatus(time, height, velocity, fuel, name);
		if (tank>0)
		{
				cout << "Number of fuel units" << endl;
				cin >> fuel;
				if (fuel < 0)
				{
					cout << "****OUT OF FUEL****" << endl;
				}
				tank = tank - fuel;
				acceleration = acceleration + (0.1*fuel);
				velocity = velocity + acceleration;
				altitude = altitude + velocity;
				seconds++;
			
		}
		if (tank <= 0)
		{
				acceleration = -1.63;
				velocity = velocity + acceleration;
				altitude = altitude + velocity;
				cout << "Velocity= " << -velocity << endl;
				cout << "Altitude= " << altitude << endl;
				cout << "Seconds= " << seconds << endl;
				seconds++;
		}
		} while (altitude > 0);
	if (velocity < -2)
	{
		cout << "You have crashed"<<endl;
	}
	else
	{
		cout << "You have landed safely"<<endl;
	}
	char dummy;
	cout << "Type in any character to exit"<<endl;
	cin >> dummy;
	return 0;

	
}

void reportStatus(ostream &os, double time, double height, double velocity, double fuel, string name)
{
	string name = "Apollo";
	cout << "Status of your " << name << " spacecraft:" << endl;
	cout << "Time: " << time <<" seconds"<< endl;
	cout << "Height: " << height << " feet" << endl;
	cout << "Speed: " << velocity << " feet/second" << endl;
	cout << "Fuel: " << fuel << endl;
}