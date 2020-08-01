#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	
	int caseNum;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		int count;
		cin>>count;
		int *nums = new int[count];

		for(int i=0;i<count;i++){
			cin>>nums[i];
		}

		map<int,int> dic;
		int head = 0, result = 0;
		for(int i=0;i<count;i++){
			if(dic.count(nums[i])>0){
				int idx = dic[nums[i]];
				for(int j=head;j<idx;j++)
					dic.erase(nums[j]);
				dic[nums[i]] = i;
				head = idx+1;
			}
			else{
				dic[nums[i]] = i;
			}
			result = max(result, i-head+1);
			/*if(dic.size()>result)
				result = dic.size();*/
		}
		cout<<result<<endl;
		delete []nums;
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
