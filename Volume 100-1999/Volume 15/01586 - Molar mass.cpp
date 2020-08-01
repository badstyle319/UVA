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
    
	int T;
    
    cin>>T;
    while(T--)
    {
        double ans = 0, factor;
        string s;
        int n = 0;
        
        cin>>s;
        for(int i = 0; i < s.length(); i++)
        {
            if(!isdigit(s[i]))
            {
                if(s[i] == 'C')
                    factor = 12.01;
                else if(s[i] == 'H')
                    factor = 1.008;
                else if(s[i] == 'O')
                    factor = 16.00;
                else
                    factor = 14.01;
                if( (i+1 < s.length() && !isdigit(s[i+1])) || (i+1) >= s.length())
                    ans += factor;
                n = 0;
            }
            else
            {
                n = n * 10 + s[i]-'0';
                if( (i+1 < s.length() && !isdigit(s[i+1])) || (i+1) >= s.length())
                    ans += n * factor;
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
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
