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
	
	int caseNum;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		LL a, b;
		cin>>a>>b;
		if(a<b)
			cout<<"<";
		else if(a>b)
			cout<<">";
		else
			cout<<"=";
		cout<<endl;
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
