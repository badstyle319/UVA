#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
	
	int caseNum;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		int count, total = 0;
		float avg;
		vector<int> nums;
		cin>>count;
		
		while(count-->0){
			int num;
			cin>>num;
			nums.push_back(num);
			total += num;
		}
		avg = (float)total/nums.size();
		sort(nums.begin(), nums.end());
		int i;
		for(i=0;i<nums.size();i++){
			if(nums[i]>avg)
				break;
		}
		float out = (float)(nums.size()-i)/nums.size()*100;
		cout.setf(ios::fixed);
		cout.precision(3);
		cout<<out<<'%'<<endl;
		
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
