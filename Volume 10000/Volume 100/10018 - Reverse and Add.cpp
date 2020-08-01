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

#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string input;
	int caseNum;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		int answer = 0;
		cin>>input;
		while(1){
			int isPa = 1;
			for(int i=0,j=input.length()-1;i<j;i++,j--){
				if(input[i]!=input[j]){
					isPa = 0;
					break;
				}
			}
			if(isPa)
				break;

			int carry=0;
			string revStr = input;
			reverse(revStr.begin(),revStr.end());
			for(int i=input.length()-1;i>=0;i--){
				int temp = input[i]-'0'+revStr[i]-'0'+carry;
				input[i] = temp%10+'0';
				carry = temp/10;
			}
			if(carry)
				input.insert(0, 1, '1');
			answer++;
		}
		cout<<answer<<' '<<input<<endl;
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
