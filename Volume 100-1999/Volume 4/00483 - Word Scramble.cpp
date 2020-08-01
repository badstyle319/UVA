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
	
	string input, temp;
	while(getline(cin, input)){
		stringstream ss(input);
		vector<string> strs;
		while(ss>>temp){
			reverse(temp.begin(), temp.end());
			strs.push_back(temp);
		}
		for(int i=0;i<strs.size();i++){
			if(i)
				cout<<' ';
			cout<<strs[i];
		}
		cout<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
