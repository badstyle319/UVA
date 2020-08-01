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

#define LL long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int caseNum, count, answer;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		answer = 0;
		cin>>count;
		int *nums = new int[count];
		for(int i=0;i<count;i++)
			cin>>nums[i];


		for(int target=1;target<=count;target++){
			int j=target-1;
			if(nums[j]==target)
				continue;

			while(nums[j]!=target)
				j++;
			for(int k=j;k>=target;k--){
				swap(nums[k], nums[k-1]);
				answer++;
			}
		}

		cout<<"Optimal train swapping takes "<<answer<<" swaps."<<endl;

		delete [] nums;
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
