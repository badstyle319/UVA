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
		if(!N)
			break;

		int nums[N];
		for(int i=0;i<N;i++)
			cin>>nums[i];
		sort(nums,nums+N);
		LL ans = 0;
		for(int i=0;i<N-1;i++){
			nums[i+1]+=nums[i];
			ans+=nums[i+1];
			for(int j=i+1;j<N-1;j++){
				if(nums[j+1]<nums[j]){
					swap(nums[j+1], nums[j]);
				}
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
