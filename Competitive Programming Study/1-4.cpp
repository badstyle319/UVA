#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	
	printf("%lf\n", sin(n * M_PI / 180.0));
	printf("%lf\n", cos(n * M_PI / 180.0));
	
	return 0;
}