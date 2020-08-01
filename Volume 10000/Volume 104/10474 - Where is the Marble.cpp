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
    
	clock_t begin = clock();
#endif

	int N, Q, case_no = 1;
    
    while(cin>>N>>Q)
    {
        if(!N && !Q)
            break;
        
        VI v;
        int num;
        
        while(N--)
        {
            cin>>num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        
        cout<<"CASE# " << case_no++ << ":" <<endl;
        while(Q--)
        {
            cin>>num;
            
            auto it = lower_bound(v.begin(), v.end(), num) - v.begin();
            
            cout<<num;
            if(v[it] == num)
                cout<<" found at "<<(it+1);
            else
                cout<<" not found";
            cout<<endl;
        }
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
