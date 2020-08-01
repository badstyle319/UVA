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

void go(char** arr, int row, int col, char c, int N){
	if(row>=0 && row<N && col>=0 && col<N && arr[row][col]==c){
		arr[row][col] = '1';
		static int dx[] = {-1, -1, 0, 0, 1, 1};
		static int dy[] = {-1, 0, -1, 1, 0, 1};
		for(int i=0;i<6;i++){
			go(arr, row+dx[i], col+dy[i], c, N);
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int N, no=1;
	while(cin>>N){
		if(!N)
			break;
		
		char **arr = new char*[N];
		for(int i=0;i<N;i++)
			arr[i] = new char[N];
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cin>>arr[i][j];
		}
		
		for(int i=0;i<N;i++){
			go(arr, 0, i, 'b', N);
		}
		
		int bWin = 0;
		for(int i=0;i<N;i++){
			if(arr[N-1][i]=='1'){
				bWin = 1;
				break;
			}
		}
		cout<<no++<<' ';
		if(bWin)
			cout<<"B";
		else
			cout<<"W";
		cout<<endl;
	
		// for(int i=0;i<N;i++){
			// for(int j=0;j<N;j++){
				// cout<<arr[i][j];
			// }
			// cout<<endl;
		// }
	
		for(int i=0;i<N;i++)
			delete [] arr[i];
		delete [] arr;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
