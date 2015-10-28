#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string read()
{
	string in;
	cout << "Enter a fractional decimal number:" << endl;;
	cin >> in;
	if ((cin.fail()) || ((in[0] != '-') && (in[0] != '+')))
	{
		cout << "Error! Invalid input" << endl;
		terminate();
	}
	int err = 0;
	for (int i = 1; i < in.length(); i++)
	{
		if (!isdigit(in[i]) && (in[i] != ',') && (in[i] != '.'))
		{
			cout << "Error! Invalid symbols" << endl;
			terminate();
		}
		if ((in[i] == ',') || (in[i] == '.'))
		{
			err++;
		}
	}
	if (err > 1)
	{
		cout << "Error! More than one delimiters" << endl;
		terminate();
	}
	return in;
}

string Celaya(double H)
{
	char symbol;
	string leg;
	int intH = (int)H;
	if (intH == 0)
	{
		symbol = '0';
		leg = symbol;
		return leg;
	}
	while (intH != 1)
	{
		int f = intH % 2;
		if (f == 1)
		{
			symbol = '1';
		}
		else
		{
			symbol = '0';
		}
		leg = symbol + leg;
		intH = intH / 2;
	}
	leg = '1' + leg;
	return leg;
}


string drobnaya(double J, int len)
{
	string led;
	int i = 0;
	char symbol;
	double gJ = J - (int)J;
	if (gJ == 0.0)
	{
		return led;
	}
	led = '.' + led;
	while ((i < len) || ((gJ - (int)gJ) == 0.0))
	{
		gJ *= 2;
		if ((int)gJ == 1)
		{
			symbol = '1';
		}
		else
		{
			symbol = '0';
		}
		led = led + symbol;
		i++;
		gJ = gJ - (int)gJ;
	}
	return led;
}

int main(void)
{
	string gH;
	string input = read();
	int por = 0;
	int zn = 0;
	if (input[0] == '-')
	{
		zn = 1;
	}
	input.erase(input.begin());
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (input[i] == ',')
		{
			input[i] = '.';
		}
	}
	double a = stod(input.substr());
	gH = Celaya(a) + drobnaya(a, 8);
	a = stod(gH.substr());
	while ((a < 1) || (a > 10))
	{
		if (a > 10)
		{
			por++;
			a = a * 0.1;
		}
		if (a < 1)
		{
			por--;
			a = a * 10;
		}
	}
	cout << "Sign: " << zn << endl;
	cout << "Exponent: " << por << endl;
	cout << "Mantissa (normalized): ";
	printf("%.8f", a, "\n");
}
