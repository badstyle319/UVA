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

	int N;
	while(cin>>N){
		if(N<10)
			cout<<N<<endl;
		else{
			N-=9;
			for(int dNum=2;;dNum++){
				int digitCnt = (pow(10.0, dNum)-pow(10.0, dNum-1))*dNum;
				if(N<=digitCnt){
					N--;
					char buf[dNum+1];
					memset(buf, 0, dNum+1);
					int num = pow(10.0, dNum-1)+N/dNum;
					sprintf(buf, "%d", num);
					cout<<buf[N%dNum]<<endl;
					break;
				}
				N-=digitCnt;
			}
		}
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
