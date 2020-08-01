#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>

using namespace std;

template<typename T>
void PV(vector<T> &v)
{
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

	int n, d;

    while(cin>>n>>d)
    {
        int r;
        map<int,int> dict;
        string ans = "";
   
        cout<<n<<"/"<<d<<" = "<< int(n/d);
        r = n % d;
        cout<<".";
        if(r)
        {
            int idx = 0;
            while(r)
            {
                if(!dict.count(r))
                {
                    dict[r] = idx++;
                }
                else 
                    break;
                
                r *= 10;
                ans.push_back(r / d + '0');
                r %= d;
            }
        }
        
        if(!r)
        {
            cout<<ans<<"(0)";
            ans = "0";
        }
        else
        {
            cout<<ans.substr(0, dict[r])<<"(";
            if(ans.length() <= 50)
                cout<<ans.substr(dict[r]);
            else
                cout<<ans.substr(dict[r], 50 - dict[r])<<"...";
            cout<<")";
        }
        cout<<endl<<"   "<<setw(-2)<< ans.length() - dict[r] <<" = number of digits in repeating cycle"<<endl<<endl;
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
