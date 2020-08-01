#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

// #define LL long long

using namespace std;

map<int,int> dic;

int generate(int temp){
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
	dic[1] = 1;
	
	while(cin>>i>>j){
		int origI=i, origJ=j;
		if(i>j)
			swap(i,j);
		int result = 0;
		for(int k=i;k<=j;k++){
			result = max(result, generate(k));
		}
		cout<<origI<<' '<<origJ<<' '<<result<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
