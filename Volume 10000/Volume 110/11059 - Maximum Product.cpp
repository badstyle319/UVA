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

	int case_no = 1;
	int N;
	
	while(cin>>N)
	{
		int nums[18];
		LL P = 0, temp;
		
		for(int i = 0; i < N; i++)
			cin>>nums[i];

		for(int i = 0; i < N; i++)
		{
			temp = nums[i];
			P = max(P, temp);
			for(int j = i+1; j < N; j++)
			{
				temp *= nums[j];
				P = max(P, temp);
				
			}
		}
		
		printf("Case #%d: The maximum product is %lld.\n\n", case_no++, P);
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
