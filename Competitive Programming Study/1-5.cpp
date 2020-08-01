#include <stdio.h>

int main()
{
	int n;
	int cost;
	
	scanf("%d", &n);
	
	cost = 95 * n;
	if(cost>=300)
		printf("%.2lf\n", cost * 0.85);
	else
		printf("%.2lf\n", (double)cost);
	
	return 0;
}