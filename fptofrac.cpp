#include <valarray> 

void fptofrac(double fp, int &numerator, int &denominator)
{
	double
		precision = 5e-4, new_fp, whole_part,
		decimal_part = fp - (int)fp;
	
	int
		cycles = 10, sign = fp > 0 ? 1 : -1, counter = 0;
	
	std::valarray<double> vec_1{double((int) fp), 1}, vec_2{1,0}, temporary;
	
	fp *= sign;

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

#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	int n, d;
	double fpnum = 77.0 / 38.0;
	
	fptofrac(fpnum, n, d);
	
	// outputs 77 / 38
	cout << "floating point value: " << fpnum << endl 
	<< "fractional value: " << n << " / " << d << endl;
}
