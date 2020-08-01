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
		double H, U, D, F, height=0;
		int day=0;
		
		cin>>H>>U>>D>>F;
		if(!H)
			break;
		
		F = U*F/100;
		do{
			day++;
			height+=U;
			if(height>H)
				break;
			height-=D;
			U = max(0.0, U-F);
		}while(height>=0);
		cout<<(height>H?"success":"failure")<<" on day "<<day<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	// fclose(stdout);
	#endif 

	return 0;
}
