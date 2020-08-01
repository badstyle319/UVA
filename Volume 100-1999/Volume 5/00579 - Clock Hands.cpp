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

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string input;
	while(cin>>input){
		if(input=="0:00")
			break;
		
		int idx;
		for(int i=0;i<input.length();i++)
			if(input[i]==':'){
				idx = i;
				break;
			}
		int H = atoi(input.substr(0, idx).c_str());
		int M = atoi(input.substr(idx+1).c_str());
		
		float answer = abs(H*30+0.5*M-6*M);
		if(answer>=180)
			answer = 360-answer;
		cout.setf(ios::fixed);
		cout.precision(3);
		cout<<answer<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
