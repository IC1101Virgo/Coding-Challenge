#include <iostream>
#include <math.h>
using namespace std;


bool checkPowerof4(unsigned n)
{
	
	double i = log(n) / log(4);

	
	return i == trunc(i);
}

int main()
{
	unsigned n = 256;

	if (checkPowerof4(n))
		cout << n << " is power of 4";
	else
		cout << n << " is not a power of 4";

	return 0;
}