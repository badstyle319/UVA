#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int caseNum;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		map<char, int> dic;
		map<char, int>::iterator it;
		for(int i='A';i<='Z';i++)
			dic[i]=0;
		
		string input;
		cin>>input;
		for(int i=0;i<input.length();i++){
			dic[toupper(input[i])]+=1;
		}
		dic['A']/=3;
		dic['R']/=2;
		
		int result = input.length();
		result = min(result, dic['M']);
		result = min(result, dic['A']);
		result = min(result, dic['R']);
		result = min(result, dic['G']);
		result = min(result, dic['I']);
		result = min(result, dic['T']);
		cout<<result<<endl;
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
