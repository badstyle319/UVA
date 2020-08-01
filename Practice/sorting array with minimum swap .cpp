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

    int n;
    while(cin>>n)
    {
        int ans = 0, num;
        vector< pair<int, int> > v;
        
        for(int i = 0; i < n; i++)
        {
            cin>>num;
            v.push_back(make_pair(num, i));
        }
        
        sort(v.begin(), v.end());
        
        for(auto p:v)
            cout<<"("<<p.first<<","<<p.second<<") ";
        cout<<endl;
        
        for(int i = 0; i < n; i++)
        {
            if(v[i].second == i)
                continue;
            
            v[i].swap(v[v[i].second]);
            for(auto p:v)
                cout<<"("<<p.first<<","<<p.second<<") ";
            cout<<endl;
            
            ans++;
            if(v[i].second != i)
                i--;
        }
        
        cout << ans << endl;
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
