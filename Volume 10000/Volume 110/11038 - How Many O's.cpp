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

using namespace std;

LL solve(LL num){
	if(num<0)
		return 0;
	LL rv = 1;
	int i=1, cnt;
	while(cnt=num/pow(10.0, i)){
		if(i==1)
			rv+=cnt;
		else{
			int t = num/pow(10.0, i-1);
			if(t%10>0)
				rv+=cnt*pow(10.0, i-1);
			else{
				rv += (cnt-1)*pow(10.0, i-1)+fmod(num, pow(10.0, i-1))+1;
			}
				
		}
		i++;
	}
	return rv;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	LL m,n;
	while(cin>>m>>n){
		if(m<0)
			break;
		cout<<solve(n)-solve(m-1)<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
