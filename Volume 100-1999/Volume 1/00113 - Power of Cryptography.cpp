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

string strMultiply(string s, int n){
	string answer;
	int carry = 0;
	for(int i=s.length()-1;i>=0;i--){
		int temp = (s[i]-'0')*n+carry;
		carry = temp/10;
		answer.insert(0, 1, temp%10+'0');
	}
	while(carry){
		answer.insert(0, 1, carry%10+'0');
		carry = carry/10;
	}
	return answer;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	double n, p;
	while(cin>>n>>p){
		double answer = round(pow(p, 1.0/n));
		cout<<(int)answer<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
