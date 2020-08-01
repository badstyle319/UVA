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
	
	int a, b;
	while(cin>>a>>b){
		int flag[32];
		for(int i=0;i<32;i++){
			unsigned bit = 1<<i;
			if(bit&a && bit&b)
				flag[31-i] = 0;
			else if(bit&a || bit&b)
				flag[31-i] = 1;
			else
				flag[31-i] = 0;
		}
		int val=0;
		for(int i=0;i<32;i++)
			val = val*2+flag[i];
		cout<<val<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
