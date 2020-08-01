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
	
	// int caseNum;
	// cin>>caseNum;
	// while(caseNum-->0){
		// ///////////////
		// ///////////////
	// }
	int count;
	while(cin>>count){
		int flag[3001] = {0}, op1, op2;
		cin>>op1;
		for(int i=1;i<count;i++){
			cin>>op2;
			int val = abs(op1-op2);
			if(val>=1 && val<count)
				flag[val] = 1;
			op1 = op2;
		}
		
		int legal = 1;
		for(int i=1;i<=count-1;i++)
			if(flag[i]==0){
				legal = 0;
				break;
			}
		if(legal)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
