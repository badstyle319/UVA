#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PF printf

using namespace std;

// static int dx[] = {-1,-1,-1,0,0,1,1,1};
// static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	clock_t begin = clock();
#endif

    int N;

    cin>>N;
    while(N--)
    {
        int digit[10] = {0};
        int num;
        
        cin>>num;
        for(int i = 1; i <= num; i++)
        {
            int n = i;
            while(n)
            {
                digit[n%10]++;
                n /= 10;
            }
        }
        cout<<digit[0];
        for(int i = 1; i < 10; i++)
            cout<<" "<<digit[i];
        cout<<endl;
    }
	
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	printf("elapsed: %.3lf seconds\n", elapsed_secs);
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
