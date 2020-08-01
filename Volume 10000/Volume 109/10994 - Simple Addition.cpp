#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

#define LL long long

using namespace std;

map<LL,int> dic;
int F(LL n){
	if(n==0)
		return 0;
	else if(n%10)
		return n%10;
	else
		return F(n/10);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	dic[0] = 0;
	LL p,q;
	while(cin>>p>>q){
		if(p<0 && q<0)
			break;
		
		LL answer = 0;
		for(LL i=p;i<=q;i++){
			cout<<i<<endl;
			if(dic.count(i)>0)
				answer+=dic[i];
			else
				answer+=F(i);
		}
			
		cout<<answer<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
