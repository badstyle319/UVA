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

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

char arr[101][101];
int m, n;

void flood(int x, int y){
	if(x<0 || x>=m || y<0 || y>=n)
		return;

	if(arr[x][y]=='@'){
		arr[x][y] = '*';
		for(int i=0;i<8;i++)
			flood(x+dx[i], y+dy[i]);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	while(cin>>m>>n){
		if(!m && !n)
			break;
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		
		int answer = 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				if(arr[i][j]=='@'){
					answer++;
					flood(i, j);
				}
		}
		cout<<answer<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
