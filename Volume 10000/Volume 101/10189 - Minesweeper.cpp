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

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int row, col, no=1;
	while(cin>>row>>col){
		if(!row && !col)
			break;
		else if(no>1)
			cout<<endl;

		char **nums = new char*[row];
		for(int i=0;i<row;i++){
			nums[i] = new char[col];
			memset(nums[i], '0', sizeof(char)*col);
		}

		char c;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++){
				cin>>c;
				if(c=='*'){
					nums[i][j] = c;
					static int dx[] = {-1,0,1,-1,1,-1,0,1};
					static int dy[] = {-1,-1,-1,0,0,1,1,1};
					for(int k=0;k<8;k++){
						int x=i+dx[k];
						int y=j+dy[k];
						if(x>=0 && x<row && y>=0 && y<col && isdigit(nums[x][y]))
							nums[x][y]+=1;
					}
				}
			}

		cout<<"Field #"<<no++<<":"<<endl;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<nums[i][j];
			}
			cout<<endl;
		}

		for(int i=0;i<row;i++)
			delete [] nums[i];
		delete [] nums;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
