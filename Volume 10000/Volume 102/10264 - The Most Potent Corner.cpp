#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

#define LL long long
#define ULL unsigned long long

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int N;
	while(cin>>N){
		vector<int> v(1<<N);
		vector<int> sum(1<<N);
		for(int i=0;i<v.size();i++)
			cin>>v[i];
		int ans=-1;
		for(int i=0;i<v.size();i++){
			for(int j=0;j<N;j++){
				sum[i]+=v[i^(1<<j)];
			}
		}
		for(int i=0;i<v.size();i++){
			for(int j=0;j<N;j++){
				ans = max(ans, sum[i]+sum[i^(1<<j)]);
			}
		}
		cout<<ans<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
