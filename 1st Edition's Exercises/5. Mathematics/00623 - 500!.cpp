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

string strMultiply(string str, int n){
	int carry = 0;
	for(int i=str.length()-1;i>=0;i--){
		int temp = (str[i]-'0')*n+carry;
		str[i] = temp%10+'0';
		carry = temp/10;
	}
	while(carry){
		str.insert(0, 1, carry%10+'0');
		carry/=10;
	}
	return str;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	map<int,string> dic;
	dic[0] = "1";
	for(int i=1;i<=1000;i++){
		// cout<<dic[i-1]<<' '<<i<<endl;
		dic[i] = strMultiply(dic[i-1], i);
		// cout<<dic[i]<<endl;
	}
	int n;
	while(cin>>n){
		cout<<n<<"!"<<endl;
		cout<<dic[n]<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
