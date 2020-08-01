#include <bits/stdc++.h>

#define UL unsigned long
#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>
#define BYTE unsigned char
#define UL_MAX 4294967295

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

UL ip_in()
{
    UL rv = 0;

    char ch;
    int val;
    
    for(int i = 0; i < 4; i++)
    {
        cin>>val;
        if(i<3)
            cin>>ch;
        rv <<= 8;
        rv += val;
    }
    return rv;
}

string ip_out(ULL ip)
{
    ostringstream ss;
    for(int i = 3; i >= 0; i--)
    {
        ss << (int)((ip >> 8*i) & 0xff);
        if(i)
            ss << ".";
    }
    return ss.str();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    
	// clock_t begin = clock();
#endif

	int m;
    UL IP[1002];
    
    while(cin>>m)
    {
        memset(IP, 0, sizeof(IP));
        
        IP[1000] = UL_MAX;
        
        for(int i = 0; i < m; i++)
        {
            IP[i] = ip_in();
        }
        
        for(int i = 0; i < m; i++)
        {
            IP[1000] &= IP[i];
            IP[1001] |= IP[i];
        }
        
        ULL temp = (IP[1000] ^ IP[1001]);
        int cnt = 0;
        while(temp)
        {
            temp >>= 1;
            cnt++;
        }

        //important: overflow
        IP[1001] = (cnt == 32)? 0 : ((~((1<<cnt) - 1)) & UL_MAX);
        IP[1000] &= IP[1001];
        
        
        for(int i = 1000; i < 1002; i++)
            cout<< ip_out(IP[i]) <<endl;
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
