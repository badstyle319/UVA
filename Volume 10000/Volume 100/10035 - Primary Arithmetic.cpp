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

#define LL long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	LL a, b;
	while(cin>>a>>b){
		if(!a && !b)
			break;

		int result = 0, carry = 0;
		while(a || b){
			carry = (a%10+b%10+carry)/10;
			result+=carry;
			a/=10;
			b/=10;
		}
		if(result){
			cout<<result;
			cout<<" carry operation";
			if(result>1)
				cout<<"s";
			cout<<"."<<endl;
		}
		else
			cout<<"No carry operation."<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
