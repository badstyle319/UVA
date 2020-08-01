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

int f91(int n){
	if(n<=100)
		return f91(f91(n+11));
	else
		return n-10;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int num;
	while(cin>>num){
		if(!num)
			break;
		
		cout<<"f91("<<num<<") = "<<f91(num)<<endl;
		
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
