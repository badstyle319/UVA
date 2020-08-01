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
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	
	int caseNum;
	cin>>caseNum;
	while(caseNum--)
    {
		///////////////
		int amp, freq;
        
		cin>>amp>>freq;
		while(freq--)
        {
			for(int i = 1; i <= amp; i++)
            {
				for(int j = 1; j <= i; j++)
                {
					cout<<i;
				}
				cout<<endl;
			}
			for(int i = amp - 1; i >= 1; i--)
            {
				for(int j = 1; j <= i; j++)
					cout<<i;
				cout<<endl;
			}
			if(freq)
				cout<<endl;
		}
		if(caseNum)
			cout<<endl;
		///////////////
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif 
	
	return 0;
}
