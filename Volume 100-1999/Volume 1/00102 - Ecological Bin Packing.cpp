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
#include <climits>

#define LL long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string original = "BGC";

	int nums[9];
	while(cin>>nums[0]>>nums[1]>>nums[2]>>nums[3]>>nums[4]>>nums[5]>>nums[6]>>nums[7]>>nums[8]){
		LL total = 0, result = LONG_MAX;
		string answer;
		for(int i=0;i<9;i++)
			total += nums[i];

		int idxs[] = {0,1,2};
		do{
			LL sum = total;
			for(int i=0;i<3;i++){
				if(idxs[i]==0)
					sum-=nums[0+i*3];
				else if(idxs[i]==1)
					sum-=nums[2+i*3];
				else
					sum-=nums[1+i*3];
			}
			if(sum<result){
				result = sum;
				string tAnswer;
				for(int i=0;i<3;i++)
					if(idxs[i]==0)
						tAnswer+="B";
					else if(idxs[i]==1)
						tAnswer+="C";
					else
						tAnswer+="G";
				answer = tAnswer;
			}
		} while ( next_permutation(idxs, idxs+3));

		cout<<answer<<' '<<result<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
