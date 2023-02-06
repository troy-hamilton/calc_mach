#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

// modify this one for each function
double o(double i)
{
	double output;
	
	output = ( pow(i, 2) + (7 * i) ) / ( pow(i, 2) - (2 * i) - 63 );
	
	return output;
}

// make a function for converting doubles into fractions

// y2 - y1 / x2 - x1
double secant(double &i1, double &i2)
{
	double slope;
	
	slope = (o(i1) - o(i2)) / (i1 - i2);
	
	return slope;	
}

void find_secant()
{
	double
		i1, i2;
	
	cin >> i1 >> i2;
	
	cout << "slope: " << secant(i1, i2) << endl;	
}

void find_output()
{
	double i;
	
	cin >> i;
	
	cout << "output: " << o(i) << endl;	
}

void find_limits()
{
	double i;
	
	cin >> i;
	
	cout << "ipos: " << o(i + 0.001) << endl
	<< "ineu: " << o(i) << endl
	<< "ineg: " << o(i - 0.001) << endl;
	
	
}

int main()
{
	std::cout << std::fixed;
    std::cout << std::setprecision(15);
	find_limits();
}
