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
	//6227020800
	int n;
	while(cin>>n){
		string ans = "1";
		if(n>=0){
			for(int i=2;i<=n;i++){
				ans = strMultiply(ans, i);
				if( (ans.length()==10 && ans.compare(string("6227020800"))>0) || ans.length()>10){
					ans = "Overflow!";
					break;
				}
			}
		}else{
			n = 0-n;
			if(n%2)
				ans = "Overflow!";
		}
		if(ans!="Overflow!"){
			if(ans.length()<5)
				ans = "Underflow!";
		}
		cout<<ans<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
