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

    string s1, s2;
    
    while(cin>>s1>>s2)
    {
        int pos1[26] = {0};
        int pos2[26] = {0};
        
        for(int i = 0; i < s1.length(); i++)
            pos1[s1[i]-'A']++;
        for(int i = 0; i < s2.length(); i++)
            pos2[s2[i]-'A']++;
        sort(pos1, pos1+26);
        sort(pos2, pos2+26);
        
        bool result = true;
        for(int i = 0; i < 26; i++)
        {
            if(pos1[i]!=pos2[i])
            {
                result = false;
                break;
            }
        }
        cout<<(result?"YES":"NO")<<endl;
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
