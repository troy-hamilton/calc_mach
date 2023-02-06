#include <iostream>
#include <valarray> 

using namespace std;

void fptofrac(double fp, int &numerator, int &denominator)
{
	double precision = 5e-4;
	int cycles = 10;
	int sign = fp > 0 ? 1 : -1;
	fp = fp * sign;
	double new_fp, whole_part;
	double decimal_part = fp - (int)fp;
	int counter = 0;

	valarray<double> vec_1{double((int) fp), 1}, vec_2{1,0}, temporary;

	while(decimal_part > precision & counter < cycles)
	{
		new_fp = 1 / decimal_part;
		whole_part = (int) new_fp;

		temporary = vec_1;
		vec_1 = whole_part * vec_1 + vec_2;
		vec_2 = temporary;

		decimal_part = new_fp - whole_part;
		counter += 1;
	}

	numerator = (int)sign * vec_1[0];
	denominator = (int)vec_1[1];
}

using std:: cout;
using std::endl;

int main()
{
	int n, d;
	double fpnum = 7.0 / 16;
	
	fptofrac(fpnum, n, d);
	
	// outputs 7 / 16
	cout << "floating point value: " << fpnum << endl 
	<< "fractional value: " << n << " / " << d << endl;
}
