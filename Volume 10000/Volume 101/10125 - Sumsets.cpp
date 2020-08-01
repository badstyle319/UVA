#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <climits>

#define LL long long

using namespace std;

int n;
int nums[1000];

int found(){
	//a+b+c=d, d will not always be the max, ex.:-3+2+1=0
	for(int d=n-1;d>=0;d--){
		for(int a=0;a<n;a++){
			for(int b=a+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					if(nums[d]==(nums[a]+nums[b]+nums[c]) && a!=d && b!=d && c!=d)
						return nums[d];
				}
			}
		}
	}
	return INT_MAX;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	while(cin>>n){
		if(!n)
			break;
		
		for(int i=0;i<n;i++)
			cin>>nums[i];
		sort(nums, nums+n);
		
		int ans = found();
		if(ans==INT_MAX)
			cout<<"no solution"<<endl;
		else
			cout<<ans<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
