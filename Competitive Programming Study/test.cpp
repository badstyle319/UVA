#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	clock_t begin = clock();
#endif

	//1.5.2
	{	
		int num1, num5;
		double num2, num3, num4;

		num1 = 11111*11111;
		num2 = 11111*11111.0;
		printf("num1=%d\n", num1);
		printf("num2=%lf\n", num2);
		
		num1 = 111111*111111;
		num2 = 111111*111111.0;
		printf("num1=%d\n", num1);
		printf("num2=%lf\n", num2);
		
		num1 = 111111111*111111111;
		num2 = 111111111*111111111.0;
		printf("num1=%d\n", num1);
		printf("num2=%lf\n", num2);
		
		num3 = sqrt(-10.0);
		printf("num3=%lf\n", num3);
		
		num4 = 1.0/0.0;
		printf("num4=%lf\n", num4);
		num4 = 0.0/0.0;
		printf("num4=%lf\n", num4);
		
		// num5 = 1/0;
		// printf("num5=%d\n", num5);
	}
	
	//1-15
	{
		int a, b;
		
		scanf("%d%d", &a, &b);
		printf("%d %d\n", a, b);
	}
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	printf("elapsed: %.3lf seconds\n", elapsed_secs);
	// fclose(stdin);
	// fclose(stdout);
#endif 

	return 0;
}
