#include <stdio.h>

int main()
{
	long long n, m;
	int caseNo = 1;
	while(scanf("%I64d %I64d", &n, &m)==2 && n && m)
	{
		double result = 0;
		for(long long i=n; i<=m; i++)
		{
			result += 1.0/(i*i);
		}
		printf("Case %d: %.5lf\n", caseNo++, result);
	}
	
	return 0;
}