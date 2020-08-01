#include <stdio.h>

int main()
{
	int n;
	
	while(scanf("%d", &n)==1 && n)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=1; j<=i; j++)
				printf(" ");
			for(int j=1; j<(n-i)*2; j++)
				printf("#");
			printf("\n");
		}
	}
	return 0;
}