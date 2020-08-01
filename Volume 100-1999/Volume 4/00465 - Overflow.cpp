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
#include <climits>

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
	while(getline(cin, line)){
		cout<<line<<endl;
		stringstream ss(line);
		double a, b, c;
		char op;
		ss>>a>>op>>b;
		/*ss>>dec>>a;
		ss>>op;
		ss>>dec>>b;*/
		if(a>INT_MAX )
			cout<<"first number too big"<<endl;
		if(b>INT_MAX)
			cout<<"second number too big"<<endl;
		if(op=='+')
			c = a+b;
		else
			c = a*b;
		if(c>INT_MAX)
			cout<<"result too big"<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
