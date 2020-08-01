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

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string line;
	int num;
	while(getline(cin, line)){
		stringstream ss(line);
		vector<int> polynomial;
		vector<int> questions;
		while(ss>>num)
			polynomial.push_back(num);

		getline(cin, line);
		ss.clear();
		ss.str(line);
		while(ss>>num)
			questions.push_back(num);

		for(int i=0;i<questions.size();i++){
			if(i)
				cout<<' ';

			int val=0;
			for(int j=0;j<polynomial.size();j++){
				if(j){
					val = val*questions[i]+polynomial[j];
				}else
					val = polynomial[j];
			}
			cout<<val;
		}
		cout<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
