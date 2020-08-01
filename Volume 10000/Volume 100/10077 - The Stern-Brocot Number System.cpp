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
	
	int m,n;
	while(cin>>m>>n){
		if(m==1 && n==1)
			break;
		int n1=0, d1=1, n2=1, d2=0, n3=1, d3=1;
		while(1){
			n3 = n1+n2;
			d3 = d1+d2;
			int t1 = m*d3;
			int t2 = n3*n;
			if(t1<t2){
				n2 = n3;
				d2 = d3;
				cout<<"L";
			}else if(t1>t2){
				n1 = n3;
				d1 = d3;
				cout<<"R";
			}else{
				cout<<endl;
				break;
			}
		}
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
