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
	
	int nums[4];
	while(cin>>nums[0]>>nums[1]>>nums[2]>>nums[3]){
		if(!nums[0] && !nums[1] && !nums[2] && !nums[3])
			break;

		int ans = 120;
		for(int i=0, clockwise=1;i<3;i++, clockwise=(clockwise+1)%2){
			if(nums[i]==nums[i+1])
				continue;

			if(clockwise){
				if(nums[i]<nums[i+1])
					ans+=40-nums[i+1]+nums[i];
				else if(nums[i]>nums[i+1])
					ans+=nums[i]-nums[i+1];
			}else{
				if(nums[i]<nums[i+1])
					ans+=nums[i+1]-nums[i];
				else if(nums[i]>nums[i+1])
					ans+=40-nums[i]+nums[i+1];
			}
		}
		cout<<ans*9<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
