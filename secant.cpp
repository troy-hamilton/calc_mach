#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

// modify this one for each function
double o(double &i)
{
	double output;
	
	output = (8 * i) - (1.86 * pow(i, 2));
	
	return output;
}

// y2 - y1 / x2 - x1
double secant(double &i1, double &i2)
{
	double slope;
	
	slope = (o(i1) - o(i2)) / (i1 - i2);
	
	return slope;	
}

int main()
{
	double
		i1, i2;
	
	cin >> i1 >> i2;
	
	cout << "slope: " << secant(i1, i2) << endl;
}
