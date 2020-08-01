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
//N,E,S,W
static int dx[] = {-1,0,1,0};
static int dy[] = {0,1,0,-1};

int go(int x, int y, int target, vector< vector<int> > arr, int direction){
	if(x==0 && y==target)
		return 1;
	
	if(!arr[x][y])
		direction--;
	else
		direction++;
	arr[x][y] = !arr[x][y];
	// cout<<"after:"<<endl;
	// for(int i=0;i<arr.size();i++){
			// for(int j=0;j<arr[i].size();j++){
				// cout<<arr[i][j]<<' ';
			// }
			// cout<<endl;
		// }
	direction+=4;
	direction%=4;
	x+=dx[direction];
	y+=dy[direction];
	// cout<<"target:"<<x<<' '<<y<<endl;
	if(x<0 || y<0 || x>target || y>target)
		return 0;
	else
		return go(x,y,target, arr, direction);
}

void print(vector< vector<int> > arr){
	for(int i=0;i<arr.size();i++){
		for(int j=0;i<arr[i].size();j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int n,x,y;
	string c;
	while(cin>>n>>c>>x>>y){
		if(!n && c=="0" && !x && !y)
			break;

		vector< vector<int> > arr(n, vector<int>(n)); 
		// ULL t;
		// for(int i=0,row=0, col=n-1,t=c;t>0;i++){
			// arr[row][col] = t & 1;
			// t >>= 1;
			// col--;
			// if(col<0){
				// col = n-1;
				// row++;
			// }
		// }
		int row=0,col=n-1;
		while(c.length()>0){
			arr[row][col] = (c[c.length()-1]-'0')%2;
			col--;
			if(col<0){
				col = n-1;
				row++;
			}
			int ten = 0;
			for(int i=0;i<c.length();i++){
				int num = c[i]-'0'+ten*10;
				if(num/2)
					c[i] = num/2+'0';
				else
					c[i] = '0';
				ten = num%2;
			}
			while(c.length()>0 && c[0]=='0')
				c.erase(0, 1);
		}
		
		// cout<<"init:"<<endl;
		// for(int i=0;i<arr.size();i++){
			// for(int j=0;j<arr[i].size();j++){
				// cout<<arr[i][j]<<' ';
			// }
			// cout<<endl;
		// }
		//x for column, y for row
		int answer = go(n-y,x-1, n-1, arr, 0);
		if(answer)
			cout<<"Yes";
		else
			cout<<"Kaputt!";
		cout<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
