#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PF printf

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	clock_t begin = clock();
#endif

    int N, T;
    map<int,int> mp;
    
    for(int i = 1; i <= 100000; i++)
    {
        int sum = i;
        int num = i;
        while(num)
        {
            sum += num % 10;
            num /= 10;
        }
        if(mp.count(sum))
            mp[sum] = min(mp[sum], i);
        else
            mp[sum] = i;
    }
    
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        PF("%d\n", mp[N]);
    }

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	PF("elapsed: %.3lf seconds\n", elapsed_secs);
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
