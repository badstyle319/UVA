#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>

#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int count, no=1;
	while(cin>>count){
		if(!count)
			break;
		
		int *nums = new int[count];
		int sum = 0;
		for(int i=0;i<count;i++){
			cin>>nums[i];
			sum+=nums[i];
		}
		
		int avg=sum/count;
		int answer=0;
		for(int i=0;i<count;i++)
			if(nums[i]>avg)
				answer+=nums[i]-avg;
		
		cout<<"Set #"<<no++<<endl;
		cout<<"The minimum number of moves is "<<answer<<"."<<endl;
		cout<<endl;
		
		delete [] nums;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
