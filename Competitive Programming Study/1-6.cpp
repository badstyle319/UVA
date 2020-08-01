#include <stdio.h>

#define IsTriangle(a,b,c) ((a+b)>c && (b+c)>a && (a+c)>b)
#define SumEqual(a,b,c) ((a+b)==c || (b+c)==a || (a+c)==b)

int main()
{
	int a, b, c;
	
	scanf("%d%d%d", &a, &b, &c);
	if(IsTriangle(a, b, c))
	{
		if(SumEqual(a*a, b*b, c*c))
			printf("yes");
		else
			printf("no");
	}
	else
		printf("not a triangle");
	printf("\n");
	
	return 0;
}