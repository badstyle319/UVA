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
#include <ctime>

#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	clock_t begin = clock();
	#endif
	
	string input;
	while(getline(cin, input)){
		if(input==".")
			break;
		else if(input==""){
			cout<<0<<endl;
			continue;
		}
		
		int len = input.length();
		vector<int> factors;
		int i=1, j=len;
		do{
			if(len%i==0){
				j = len/i;
				factors.push_back(i);
				if(i!=j)
					factors.push_back(j);
			}
			i++;
		}while(i<j);
		int ans = 1;
		sort(factors.begin(), factors.end());
		for(int i=0;i<factors.size();i++){
			string target = input.substr(0, factors[i]);
			int legal = 1;
			for(int j=target.size();j<input.size();j+=target.size()){
				if(target!=input.substr(j, target.size())){
					legal = 0;
					break;
				}
			}
			if(legal){
				ans = input.size()/target.size();
				break;
			}
		}
		cout<<ans<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	cout<<"elapsed: "<<elapsed_secs<<endl;
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
