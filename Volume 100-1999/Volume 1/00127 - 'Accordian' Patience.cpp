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
#include <stack>

#define LL long long
#define ULL unsigned long long

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int match(string a, string b){
	return a[0]==b[0] || a[1]==b[1];
}

void print(vector< stack<string> > arr){
	for(int i=0;i<arr.size();i++)
		cout<<" "<<arr[i].top();
	cout<<endl;
}

int findMatch(vector< stack<string> > &arr){
	if(arr.size()==0)
		return 0;
	
	for(int i=1;i<arr.size();i++){
		string target = arr[i].top();
		int pos = -1;
		for(int j=i;j>0;){
			if(j>=3 && match(arr[j-3].top(), target)){
				pos = j-3;
				j-=3;
			}else if(j>=1 && match(arr[j-1].top(), target)){
				pos = j-1;
				j-=1;
			}else{
				break;
			}
		}
		if(pos!=-1){
			arr[pos].push(target);
			arr[i].pop();
			if(arr[i].empty())
				arr.erase(arr.begin()+i);
			return 1;
		}
	}
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string line;
	while(1){
		getline(cin, line);
		if(line[0]=='#')
			break;

		vector< stack<string> > arr(52, stack<string>());
		stringstream ss(line);
		string token;
		
		for(int i=0;i<26;i++){
			ss>>token;
			arr[i].push(token);
		}
		getline(cin, line);
		ss.clear();
		ss.str(line);
		for(int i=26;i<52;i++){
			ss>>token;
			arr[i].push(token);
		}
		
		do{
			// print(arr);
		}while(findMatch(arr));
		
		cout<<arr.size()<<" pile"<<(arr.size()==1?"":"s")<<" remaining:";
		for(int i=0;i<arr.size();i++)
			cout<<" "<<arr[i].size();
		cout<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
