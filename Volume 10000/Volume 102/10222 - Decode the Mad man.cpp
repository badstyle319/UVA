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
	
	string err="234567890-=ertyuiop[]\\dfghjkl;'cvbnm,./ ";
	string cor="`1234567890qwertyuiop[asdfghjklzxcvbnm, ";
	
	string input;
	getline(cin, input);
	for(int i=0;i<input.length();i++){
		int idx;
		for(idx=0;idx<err.length();idx++){
			if(err[idx]==tolower(input[i]))
				break;
		}
		cout<<cor[idx];
	}
	cout<<endl;
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
