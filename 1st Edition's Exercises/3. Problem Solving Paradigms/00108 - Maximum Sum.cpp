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
#include <climits>

#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	#endif
	
	int N;
	while(cin>>N){
		int answer = INT_MIN;
		vector< vector<int> > nums(N, vector<int>(N, 0));
		// int **nums = new int*[N];
		// for(int i=0;i<N;i++)
			// nums[i] = new int[N];

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>nums[i][j];
				if(i>=1)
					nums[i][j]+=nums[i-1][j];
				if(j>=1)
					nums[i][j]+=nums[i][j-1];
				if(i>=1 && j>=1)
					nums[i][j]-=nums[i-1][j-1];
			}
		}

		/*for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cout<<setw(3)<<nums[i][j]<<' ';
			cout<<endl;
		}*/

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				for(int w=i;w<N;w++){
					for(int h=j;h<N;h++){
						int temp = nums[w][h];
						if(i>=1)
							temp-=nums[i-1][h];
						if(j>=1)
							temp-=nums[w][j-1];
						if(i>=1 && j>=1)
							temp+=nums[i-1][j-1];
						answer = max(answer, temp);
					}
				}
			}
		}
		cout<<answer<<endl;
		// for(int i=0;i<N;i++)
			// delete [] nums[i];
		// delete [] nums;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	// fclose(stdout);
	#endif 
	
	return 0;
}
