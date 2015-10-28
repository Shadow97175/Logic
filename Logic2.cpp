#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

std::string read()
{
	std::string in;
	std::cout << "Enter a fractional decimal number:" << std::endl;;
	std::cin >> in;
	if ((std::cin.fail()) || ((in[0] != '-') && (in[0] != '+')))
	{
		std::cout << "Error! Invalid input" << std::endl;
		std::terminate();
	}
	int err = 0;
	for (int i = 1; i < in.length(); i++)
	{
		if (!isdigit(in[i]) && (in[i] != ',') && (in[i] != '.'))
		{
			std::cout << "Error! Invalid symbols" << std::endl;
			std::terminate();
		}
		if ((in[i] == ',') || (in[i] == '.'))
		{
			err++;
		}
	}
	if (err > 1)
	{
		std::cout << "Error! More than one delimiters" << std::endl;
		std::terminate();
	}
	return in;
}

std::string Celaya(double H)
{
	char symbol;
	std::string leg;
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


std::string drobnaya(double J, int len)
{
	std::string led;
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
	std::string gH;
	std::string input = read();
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
	double a = std::stod(input.substr());
	gH = Celaya(a) + drobnaya(a, 8);
	a = std::stod(gH.substr());
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
	std::cout << "Sign: " << zn << std::endl;
	std::cout << "Exponent: " << por << std::endl;
	std::cout << "Mantissa (normalized): ";
	printf("%.8f", a, "\n");
}
