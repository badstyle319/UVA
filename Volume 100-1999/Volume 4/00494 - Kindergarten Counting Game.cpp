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

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string input;
	while(getline(cin, input)){
		int answer=0;
		int conseq = 0;
		for(int i=0;i<input.length();i++){
			if(isalpha(input[i])){
				conseq++;
			}else{
				if(conseq>0)
					answer++;
				conseq=0;
			}
		}
		cout<<answer<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
