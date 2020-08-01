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

int generate(LL temp){
	if(temp==1)
		return 3;
	if(dic.count(temp))
		return dic[temp];
	
	int origNum = temp;
	int count = 0;
	while(temp!=1){
		count+=1;
		if(temp%2)
			temp = 3*temp+1;
		else
			temp/=2;
		if(dic.count(temp))
			return count+dic[temp];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int i, j;
	dic[1] = 0;
	while(cin>>i>>j){
		if(!i && !j)
			break;
		if(i>j)
			swap(i, j);
		int result = 0, answer=0;
		for(LL k=i;k<=j;k++){
			int t=generate(k);
			if(t>result){
				result = t;
				answer = k;
			}
		}
		cout<<"Between "<<i<<" and "<<j<<", "<<answer<<" generates the longest sequence of "<<result<<" values."<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
