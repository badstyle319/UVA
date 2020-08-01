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
	
	int caseNum, no=1;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		int row, col, c;
		cin>>row>>col>>c;
		vector<string> arr(row, "");
		vector<int> test;
		cout<<"Case #"<<no++<<":"<<endl;
		
		for(int i=0;i<row;i++)
			cin>>arr[i];
		if(!c){
			for(int i=0;i<row;i++)
				cout<<arr[i]<<endl;
		}else{
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					if(arr[i][j]=='.')
						;
				}
			}
		}

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
