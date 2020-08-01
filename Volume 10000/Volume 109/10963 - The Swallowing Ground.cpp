#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

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
		int count, legal=1, diff, yMax, yMin;
		cin>>count;
		cin>>yMax>>yMin;
		diff = yMax-yMin;
		for(int i=1;i<count;i++){
			cin>>yMax>>yMin;
			if((yMax-yMin)!=diff)
				legal = 0;
		}
		if(legal>0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		
		if(caseNum>0)
			cout<<endl;
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
