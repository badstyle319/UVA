#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

#define LL long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	vector<LL> nums;
	vector<LL>::iterator it;
	LL num;
	while(cin>>num){
		for(it=nums.begin();it!=nums.end();it++){
			if((*it)>num)
				break;
		}
		nums.insert(it, num);
		int sz = nums.size();
		if(sz%2==0){
			cout<<(nums[sz/2-1]+nums[sz/2])/2<<endl;
		}
		else{
			cout<<nums[sz/2]<<endl;
		}
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
