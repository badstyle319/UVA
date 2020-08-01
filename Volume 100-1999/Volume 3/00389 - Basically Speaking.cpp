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

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	map<char, int> dic;
	for(int i='0';i<='9';i++)
		dic[i] = i-'0';
	for(int i='A';i<='F';i++)
		dic[i] = i-'A'+10;
	string digits="0123456789ABCDEF";


	string input;
	int base, target;
	while(cin>>input>>base>>target){
		ULL val = 0, t=0;
		string answer;
		for(int i=input.length()-1;i>=0;i--){
			if(!t)
				t++;
			else
				t*=base;
			val+=t*dic[input[i]];
		}

		while(1){
			ULL a = val/target;
			ULL b = val%target;
			answer.insert(0, 1, digits[b]);
			val = a;
			if(!a || answer.length()>7)
				break;
		}
		if(answer.length()>7)
			cout<<setw(7)<<"ERROR"<<endl;
		else
			cout<<setw(7)<<answer<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
