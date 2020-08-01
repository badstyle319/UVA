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
#include <bitset>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

void ans(string str, int &deg){	
	int sum=0;
	for(int i=0;i<str.size();i++)
		sum+=str[i]-'0';
	if(sum%9==0){
		deg++;
		stringstream ss;
		ss<<sum;
		if(sum!=9)
			ans(ss.str(), deg);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	while(1){
		string str;
		int degree=0;
		
		cin>>str;
		if(str=="0")
			break;
		
		ans(str, degree);
		if(degree>0)
			cout<<str<<" is a multiple of 9 and has 9-degree "<<degree<<"."<<endl;
		else
			cout<<str<<" is not a multiple of 9."<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 

	return 0;
}
