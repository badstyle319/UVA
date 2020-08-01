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
        string s;
        int ans = s.length();

        cin>>s;
        for(int R = 0; R < s.length(); R++)
        {
            bool bFlag = 1;
            for(int L = R + 1; L < s.length(); L += R+1)
            {
                if(strncmp(s.c_str(), &s[L], R+1))
                {
                    bFlag = 0;
                    break;
                }
            }
            if(bFlag)
            {
                ans = R + 1;
                break;
            }
        }
        cout<<ans<<endl;
        if(N)
            cout<<endl;
    }
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    
    cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
    
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
