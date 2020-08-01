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

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string input, token;
	int caseNum, no=1;
	cin>>caseNum;
	getline(cin, input);
	while(caseNum-->0){
		///////////////
		getline(cin, input);
		stringstream ss1(input);
		vector<string> data;

		float P=0, U=0, I=0;
		while(ss1>>token){
			if(token.find('=')!=string::npos){
				token.erase(token.find_last_not_of(',')+1);
				size_t pos = token.find('=');
				string str1 = token.substr(0, pos);
				string str2 = token.substr(pos+1);

				if(str1=="P"){
					sscanf(str2.c_str(), "%f", &P);
					if(str2.find('m')!=string::npos)
						P*=0.001;
					else if(str2.find('k')!=string::npos)
						P*=1000;
					else if(str2.find('M')!=string::npos)
						P*=1000000;
				}
				else if(str1=="U"){
					sscanf(str2.c_str(), "%f", &U);
					if(str2.find('m')!=string::npos)
						U*=0.001;
					else if(str2.find('k')!=string::npos)
						U*=1000;
					else if(str2.find('M')!=string::npos)
						U*=1000000;
				}
				else{
					sscanf(str2.c_str(), "%f", &I);
					if(str2.find('m')!=string::npos)
						I*=0.001;
					else if(str2.find('k')!=string::npos)
						I*=1000;
					else if(str2.find('M')!=string::npos)
						I*=1000000;
				}
			}
		}
		cout<<"Problem #"<<no<<endl;
		no++;
		if(!P)
			cout<<fixed<<setprecision(2)<<"P="<<U*I<<"W"<<endl;
		else if(!U)
			cout<<fixed<<setprecision(2)<<"U="<<P/I<<"V"<<endl;
		else
			cout<<fixed<<setprecision(2)<<"I="<<P/U<<"A"<<endl;
		cout<<endl;
		///////////////
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
