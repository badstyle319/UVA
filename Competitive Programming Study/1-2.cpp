#include <stdio.h>

int main()
{
	double f; //Fahrenheit
	double c; //Celsius
	
	scanf("%lf", &f);
	
	c = 5 * (f - 32) / 9.0;
	printf("%.3lf\n", c);
	
	return 0;
}