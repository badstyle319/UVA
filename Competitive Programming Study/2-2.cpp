#include <stdio.h>

int main()
{
	int a, b, c, caseNo = 1;
	while(scanf("%d%d%d", &a, &b, &c)==3)
	{
		int answer = -1;
		for(int i=10; i<=100; i++)
		{
			if(i%3==a && i%5==b && i%7==c)
			{
				answer = i;
				break;
			}
		}
		printf("Case %d: ", caseNo);
		if(answer==-1)
			printf("No answer");
		else
			printf("%d", answer);
		printf("\n");
		caseNo++;
	}
	
	return 0;
}