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
#include <bitset>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	#endif
	
	while(1){
		string str;
		
		cin>>str;
		if(str=="#")
			break;
		
		int len = str.length();
		int found = 0;
		for(int i=len-1;i>0;i--){
			for(int j=i-1;j>=0;j--){
				if(str[i]>str[j]){
					swap(str[i], str[j]);
					sort(str.begin()+j+1, str.end());
					found = 1;
					break;
				}
			}
			if(found)
				break;
		}
		cout<<(found?str:"No Successor")<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	// fclose(stdout);
	#endif 

	return 0;
}
