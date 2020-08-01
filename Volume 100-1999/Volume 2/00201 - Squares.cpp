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

	int n, case_no = 1;
    
    while(cin>>n)
    {
        int m;
        
        cin>>m;
        
        int H[9][9] = {0}, V[9][9] = {0};
        
        while(m--)
        {
            char c;
            int i, j;
            
            cin>>c>>i>>j;
            if(c == 'H')
                H[i-1][j-1] = 1;
            else
                V[j-1][i-1] = 1;
        }
        
        map<int, int> ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int size = 1; size < n; size++)
                {
                    bool flag = 1;
                    for(int k = 0; (i+k<n) && (j+k<n) && (k < size); k++)
                    {
                        
                        if(!H[i][j+k] || !H[i+size][j+k] || !V[i+k][j] || !V[i+k][j+size])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag)
                    {
                        if(!ans.count(size))
                            ans[size] = 0;
                        ans[size] += 1;
                    }
                }
            }
        }
        
        if(case_no > 1)
            cout<<endl<<"**********************************"<<endl<<endl;
        
        cout<<"Problem #"<< case_no++<<endl<<endl;
        if(ans.size())
        {
            for(auto kv:ans)
            {
                cout<<kv.second<<" square (s) of size "<<kv.first<<endl;
            }
        }
        else
            cout<<"No completed squares can be found."<<endl;
    }
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    
    // cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
    
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
