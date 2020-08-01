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

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	map<char, int> dic;
	dic['B'] = 1;
	dic['F'] = 1;
	dic['P'] = 1;
	dic['V'] = 1;
	dic['C'] = 2;
	dic['G'] = 2;
	dic['J'] = 2;
	dic['K'] = 2;
	dic['Q'] = 2;
	dic['S'] = 2;
	dic['X'] = 2;
	dic['Z'] = 2;
	dic['D'] = 3;
	dic['T'] = 3;
	dic['L'] = 4;
	dic['M'] = 5;
	dic['N'] = 5;
	dic['R'] = 6;
	
	string temp;
	while(cin>>temp){
		string buf;
		for(int i=0;i<temp.length();i++){
			if(dic.find(temp[i])!=dic.end())
				buf+=dic[temp[i]]+'0';
			else
				buf+='0';
		}
		for(int i=buf.length()-1;i>0;i--){
			if(buf[i]==buf[i-1])
				buf[i]='0';
		}
		for(int i=0;i<buf.length();i++)
			if(buf[i]!='0')
				cout<<buf[i];
		cout<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
