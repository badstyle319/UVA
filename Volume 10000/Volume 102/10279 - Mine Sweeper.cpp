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
	
	int caseNum;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		int n;
		cin>>n;
		vector<string> arr(n, "");
		vector<string> click(n, "");
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++)
			cin>>click[i];
		int exploded = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(click[i][j]=='x'){
					if(arr[i][j]=='*'){
						exploded = 1;
					}else{
						int cnt = 0;
						for(int k=0;k<8;k++){
							int x=i+dx[k];
							int y=j+dy[k];
							if(x>=0 && x<n && y>=0 && y<n){
								if(arr[x][y]=='*')
									cnt++;
							}
						}
						click[i][j] = '0'+cnt;
					}
				}
			}
		}
		if(exploded)
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j]=='*')
					click[i][j] = arr[i][j];
			}
		}
		for(int i=0;i<n;i++)
			cout<<click[i]<<endl;
		if(caseNum)
			cout<<endl;
		///////////////
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
