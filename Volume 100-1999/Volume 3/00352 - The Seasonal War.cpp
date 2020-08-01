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

char nums[25][25];
int n;

void dfs(int i, int j, int answer){
	if(i<0 || i>=n || j<0 || j>=n)
		return;

	if(nums[i][j]=='1'){
		nums[i][j] = 'a'+answer;
		static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
		static int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
		for(int k=0;k<8;k++){
			int tx=i+dx[k];
			int ty=j+dy[k];
			dfs(tx,ty, answer);
		}
//		answer++;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int no=1;
	while(cin>>n){
		int answer = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>nums[i][j];

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(nums[i][j]=='1'){
					answer+=1;
					dfs(i, j, answer);
				}
			}
		}
		cout<<"Image number "<<no++<<" contains "<<answer<<" war eagles."<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
