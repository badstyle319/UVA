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
	
	int caseNum, no=1;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		int a,b, answer = 0;
		cin>>a>>b;
		for(int i=a;i<=b;i++){
			if(i%2)
				answer+=i;
		}
		cout<<"Case "<<no++<<": "<<answer<<endl;
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
