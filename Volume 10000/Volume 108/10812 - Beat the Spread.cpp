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
	
	int caseNum;
	LL sum, subtract, a, b;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		cin>>sum>>subtract;
		if(sum<=subtract || (sum+subtract)%2 || (sum-subtract)%2){
			if(!sum && !subtract)
				cout<<"0 0"<<endl;
			else
				cout<<"impossible"<<endl;
			continue;
		}
		a = (sum+subtract)/2;
		b = (sum-subtract)/2;
		if(a<b)
			swap(a, b);
		cout<<a<<' '<<b<<endl;
		///////////////
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
