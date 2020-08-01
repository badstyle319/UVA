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
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	clock_t begin = clock();
#endif

	int N, first = 1;
	int flag[11] = {0};
	map<int, int> mp;
	
	while(cin>>N)
	{
		if(!N)
			break;
		
		if(first)
			first = 0;
		else
			printf("\n");
		
		int found = 0;
		for(int n = 1234; n <= 98765; n++)
		{
			memset(flag, 0, sizeof(flag));
			
			int temp = n;
			for(int i = 0; i < 5; i++)
			{
				int digit = temp % 10;
				temp /= 10;
				if(flag[digit])
				{
					flag[10] = 1;
					break;
				}
				flag[digit] = 1;
			}
			
			if(flag[10])
				continue;
			
			temp = n * N;
			if(temp > 98765)
				break;
			for(int i = 0; i < 5; i++)
			{
				int digit = temp % 10;
				temp /= 10;
				if(flag[digit])
				{
					flag[10] = 1;
					break;
				}
				flag[digit] = 1;
			}
			
			if(flag[10])
				continue;

			found = 1;
			printf("%05d / %05d = %d\n", n * N, n, N);
			
		}
		if(!found)
			printf("There are no solutions for %d.\n", N);
	}
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	printf("elapsed: %.3lf seconds\n", elapsed_secs);
	fclose(stdin);
	// fclose(stdout);
#endif 

	return 0;
}
