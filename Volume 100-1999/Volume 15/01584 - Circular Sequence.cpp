#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PF printf

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int cmp(const char* s, int len, int pos1, int pos2)
{
    for(int i = 0; i < len; i++)
    {
        char ch1 = s[(pos1+i)%len];
        char ch2 = s[(pos2+i)%len];
        if(ch1 != ch2)
            return ch1 < ch2;
    }
    return 0;
} 

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
    string str;
    
    cin>>T;
    for(int i = 0; i < T; i++)
    {
        cin>>str;
        
        int ans = 0;
        int len = str.length();

        for(int j = 1; j < len; j++)
        {
            if(cmp(str.c_str(), len, j, ans))
                ans = j;
        }
        
        for(int i = 0; i < len; i++)
            cout<<str[(ans+i)%len];
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
