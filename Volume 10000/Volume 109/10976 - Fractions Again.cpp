#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define dbg printf

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

	int k;
	while(cin>>k)
	{
		int x, temp;
		vector<pair<int,int>> ans;
		
		for(int y = k+1; y <= 2*k; y++)
		{
			temp = k * y;
			if(temp % (y-k) == 0)
			{
				x = temp / (y - k);
				ans.push_back(make_pair(x, y));
			}
		}
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++)
			printf("1/%d = 1/%d + 1/%d\n", k, ans[i].first, ans[i].second); 
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
