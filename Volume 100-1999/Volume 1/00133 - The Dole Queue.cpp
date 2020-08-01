#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>

using namespace std;

template<typename T>
void PV(vector<T> &v)
{
    cout<<endl<<"===start==="<<endl;
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl<<"====end===="<<endl;
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

	int N, k, m;
    
    
    while(cin>>N>>k>>m)
    {
        if(!N && !k && !m)
            break;
        
        vector<int> v;
        for(int i = N; i > 0; i--)
            v.push_back(i);
        
        int kPos = N - 1;
        int mPos = 0;
        int total = N;
        
        while(total)
        {
            // cout<<endl<<"K at "<<kPos<<", M at "<<mPos<<endl;
            for(int i = 0;;)
            {
                if(v[kPos])
                    i++;
                
                if(i == k)
                    break;
                
                kPos--;
                kPos = (kPos + v.size()) % v.size();
            };
            
            for(int i = 0;;)
            {
                if(v[mPos])
                    i++;
                
                if(i == m)
                    break;
                
                mPos++;
                mPos %= v.size();
            }
         
            if(kPos == mPos)
            {
                cout<<setw(3)<<v[kPos];
                v[kPos] = 0;
                total--;
            }
            else
            {
                cout<<setw(3)<<v[kPos]<<setw(3)<<v[mPos];
                v[kPos] = 0;
                v[mPos] = 0;
                total -= 2;
            }
            if(total)
                cout<<",";
            else
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
