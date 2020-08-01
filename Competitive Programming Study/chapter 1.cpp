#include <stdio.h>
#include <math.h>

#define DBG(s){printf(s "\n");}

int main()
{
	DBG("ep. 1~4");
	printf("%d\n", 1+2);
	printf("%d\n", 3-4);
	printf("%d\n", 5*6);
	printf("%d\n", 8/5);
	
	DBG("ep. 5~7");
	printf("%.1f\n", 8.0/5.0);
	printf("%.2f\n", 8.0/5.0);
	printf("%d\n", 8.0/5.0);
	
	DBG("ep. A1");
	printf("%d\n", 11111*11111);
	printf("%d\n", 111111*111111);
	
	DBG("ep. A2");
	printf("%lf\n", (double)111111111*111111111);
	
	DBG("ep. A3");
	double a3 = sqrt(-10);
	printf("%lf\n", a3);
	
	DBG("ep. A4");
	double a4 = 1.0/0.0;
	printf("%lf\n", a4);
	
	// DBG("ep. A5");
	// int a5 = 1/0; //crash
	// printf("%d\n", a5);
	
	int a, b;
	DBG("ep. B1~B2");
	scanf("%d%d", &a, &b);
	printf("%d %d\n", a, b);
	
	char c;
	DBG("ep. B3");
	scanf("%d%d", &a, &c);
	printf("%d %d\n", a, c);
	
	printf("%%\n");
	
	return 0;
}