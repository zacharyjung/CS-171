/
/Created by Zachary Jung
//Date: 2/9/2016
//HW2(2-5)
#include <iomanip>
#include <iostream>
using namespace std;
//This function takes the zipcode and divides up the individual digits. Then it adds up the sum of the digits and finds the check digit, which is the amount away the sum is from being divisible by 10
int makeCheckDigit(int zipcode)
{
	int digit1, digit2, digit3, digit4, digit5, sum, count = 0;
	//This seperates each digit of the zipcode
	digit1 = zipcode / 10000;
	zipcode = zipcode % 10000;
	digit2 = zipcode / 1000;
	zipcode = zipcode % 1000;
	digit3 = zipcode / 100;
	zipcode = zipcode % 100;
	digit4 = zipcode / 10;
	zipcode = zipcode % 10;
	digit5 = zipcode;
	//Adds up all of the digits and finds the check number. The check number is how far away the sum is from being divisible by 10
	sum = digit1 + digit2 + digit3 + digit4 + digit5;
	while (sum % 10 != 0)
	{

		sum++;
		count++;


	}

	return count;
}
//This function converts a digit from 0-9 into the respective barcode of that number
string convertDigit(int value)
{
	string barcode;
	if (value == 0)
	{
		barcode = "||:::";
	}
	if (value == 1)
	{
		barcode = ":::||";
	}
	if (value == 2)
	{
		barcode = "::|:|";
	}
	if (value == 3)
	{
		barcode = "::||:";
	}
	if (value == 4)
	{
		barcode = ":|::|";
	}
	if (value == 5)
	{
		barcode = ":|:|:";
	}
	if (value == 6)
	{
		barcode = ":||::";
	}
	if (value == 7)
	{
		barcode = "|:::|";
	}
	if (value == 8)
	{
		barcode = "|::|:";
	}
	if (value == 9)
	{
		barcode = "|:|::";
	}
	return barcode;
}
//This function takes the barcodes of the digit and the check number and adds them together
string barcode(int zipcode)
{
	int check, digit1, digit2, digit3, digit4, digit5;
	string barcode1, barcode2, barcode3, barcode4, barcode5, barcode6;
	//Finds the check number
	check = makeCheckDigit(zipcode);
	//This seperates every digit from the zipcodes
	digit1 = zipcode / 10000;
	zipcode = zipcode % 10000;
	digit2 = zipcode / 1000;
	zipcode = zipcode % 1000;
	digit3 = zipcode / 100;
	zipcode = zipcode % 100;
	digit4 = zipcode / 10;
	zipcode = zipcode % 10;
	digit5 = zipcode;
	//Calls the convertDigit function and finds the barcode for each digit
	barcode1 = convertDigit(digit1);
	barcode2 = convertDigit(digit2);
	barcode3 = convertDigit(digit3);
	barcode4 = convertDigit(digit4);
	barcode5 = convertDigit(digit5);
	barcode6 = convertDigit(check);
	return("|" + barcode1 + barcode2 + barcode3 + barcode4 + barcode5 + barcode6 + "|");
}
//This function asks the user to input the zipcode and turns it into a barcode by calling all of the functions
int main()
{
	int zipcode;
	string barcode1;
	cout << "Enter the zipcode" << endl;
	cin >> zipcode;
	if (zipcode < 0)
	{
		cout << "Error" << endl;
	}
	barcode1 = barcode(zipcode);
}