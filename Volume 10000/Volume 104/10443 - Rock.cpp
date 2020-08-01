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

static int dx[] = {-1,1,0,0};
static int dy[] = {0,0,-1,1};

char arr[2][101][101];
int row,col,n;

void go(int x, int y, char arr1[101][101], char arr2[101][101]){
	char ch = arr1[x][y];
	int lose;
	switch(ch){
		case 'R':
			lose=0;
			for(int i=0;i<4;i++){
				int tx=x+dx[i];
				int ty=y+dy[i];
				if(tx>=0 && tx<row && ty>=0 && ty<col){
					if(arr1[tx][ty]=='P'){
						lose = 1;
						break;
					}
				}
			}
			if(lose)
				arr2[x][y] = 'P';
			else
				arr2[x][y] = arr1[x][y];
			break;
		case 'S':
			lose=0;
			for(int i=0;i<4;i++){
				int tx=x+dx[i];
				int ty=y+dy[i];
				if(tx>=0 && tx<row && ty>=0 && ty<col){
					if(arr1[tx][ty]=='R'){
						lose = 1;
						break;
					}
				}
			}
			if(lose)
				arr2[x][y] = 'R';
			else
				arr2[x][y] = arr1[x][y];
			break;
		case 'P':
			lose=0;
			for(int i=0;i<4;i++){
				int tx=x+dx[i];
				int ty=y+dy[i];
				if(tx>=0 && tx<row && ty>=0 && ty<col){
					if(arr1[tx][ty]=='S'){
						lose = 1;
						break;
					}
				}
			}
			if(lose)
				arr2[x][y] = 'S';
			else
				arr2[x][y] = arr1[x][y];
			break;
	}
}

void print(char arr[101][101]){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}

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
		cin>>row>>col>>n;
		
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>arr[0][i][j];

		for(int k=0;k<n;k++){
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					go(i,j, arr[k%2], arr[(k+1)%2]);

		}
		print(arr[n%2]);
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
