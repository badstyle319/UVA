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

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int x, num;
	string line;
	while(cin>>x){
		getline(cin, line);
		getline(cin, line);
		stringstream ss(line);
		vector<int> poly;
		while(ss>>num)
			poly.push_back(num);
		int size = poly.size();
		
		for(int i=0;i<size;i++){
			poly[i]*=(size-1-i);
		}

		poly.pop_back();
		int val = 0;
		for(int i=0;i<poly.size();i++){
			val = val*x+poly[i];
		}
		cout<<val<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
