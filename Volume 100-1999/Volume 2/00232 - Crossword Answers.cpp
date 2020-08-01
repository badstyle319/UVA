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

    int R, C, case_no = 1;
    char arr[11][11];
    
    while(cin>>R>>C)
    {
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cin>>arr[i][j];
            }
        }
        
        map<pair<int,int>, pair<int,int>> mp;
        
        int idx = 1;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(arr[i][j] == '*')
                    continue;
                
                int nFlag = 0;
                if(j-1<0 || (j-1>=0 && arr[i][j-1] == '*'))
                    nFlag |= 1;
                if(i-1<0 || (i-1>=0 && arr[i-1][j] == '*'))
                    nFlag |= 2;
                if(nFlag)
                {
                    mp[make_pair(i,j)] = make_pair(nFlag, idx++);    
                }
            }
        }
        
        if(case_no!=1)
            cout<<endl;
        
        cout<<"puzzle #"<< case_no++ <<":"<<endl;
        cout<<"Across"<<endl;
        for(auto kv:mp)
        {
            if(kv.second.first & 1)
            {
                cout<<setw(3)<<kv.second.second<<".";
                for(int c = kv.first.second; c < C; c++)
                {
                    if(arr[kv.first.first][c] == '*')
                        break;
                    cout<<arr[kv.first.first][c];
                }
                cout<<endl;
            }
        }
        cout<<"Down"<<endl;
        for(auto kv:mp)
        {
            if(kv.second.first & 2)
            {
                cout<<setw(3)<<kv.second.second<<".";
                for(int r = kv.first.first; r < R; r++)
                {
                    if(arr[r][kv.first.second] == '*')
                        break;
                    cout<<arr[r][kv.first.second];
                }
                cout<<endl;
            }
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
