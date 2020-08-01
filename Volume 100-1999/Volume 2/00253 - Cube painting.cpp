#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>

using namespace std;

template<typename T>
void PV(vector<T> &v)
{
    cout<<v.size()<<":";
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl;
};

// static int dx[] = {-1,-1,-1,0,0,1,1,1};
// static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    
	// clock_t begin = clock();
#endif

    string line;
    while(cin>>line)
    {   
        string src = line.substr(0, 6);
        string dst = line.substr(6, 6);
        bitset<3> match;
        
        // cout<<src<<" "<<dst<<endl;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(!match.test(j) && ( (src[i] == dst[j] && src[5-i] == dst[5-j]) || (src[i] == dst[5-j] && src[5-i] == dst[j]) ) )
                {
                    // cout<<src[i]<<src[5-i]<<" "<<dst[j]<<dst[5-j]<<endl;
                    match.set(j);
                    break;
                }
            }
        }
        
        if(match.count() == 3)
            cout<<"TRUE";
        else
            cout<<"FALSE";
        cout<<endl;
    }
	
	
#ifndef ONLINE_JUDGE
	// clock_t end = clock();
	// double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    
    // cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
    
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
