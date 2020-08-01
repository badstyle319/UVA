#include <stdio.h>

int main()
{
	int caseNo = 1;
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c)==3 && a && b && c)
	{
		// double result = (double)a/b;
		// printf("Case %d: %.*lf\n", caseNo++, c, result);
		
		printf("Case %d: %d", caseNo++, a/b);
		if(c>0)
		{
			printf(".");
			int remainder = a % b;
			int temp;
			for(int i=0; i<c; i++)
			{
				temp = remainder * 10 / b;
				remainder = remainder * 10 % b;
				//末位四捨五入
				if(i==c-1 && remainder * 10 / b >=5)
					temp += 1;

				printf("%d", temp);
			}
		}
		printf("\n");
	}
	
	return 0;
}