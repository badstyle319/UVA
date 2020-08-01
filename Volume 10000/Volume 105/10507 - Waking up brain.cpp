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
	
	string line;
	int N, M;
	while(cin>>N>>M){
		vector< vector<char> > arr(N,vector<char>());
		map<char,int> flagDic;
		map<char,int> idxDic;
		cin>>line;
		for(int i=0;i<line.length();i++){
			if(idxDic.count(line[i])==0)
				idxDic[line[i]] = idxDic.size()-1;
			flagDic[line[i]] = 1;
		}
		for(int i=0;i<M;i++){
			cin>>line;
			for(int j=0;j<line.length();j++){
				if(idxDic.count(line[j])==0)
					idxDic[line[j]] = idxDic.size()-1;
			}
			char ch1 = line[0];
			char ch2 = line[1];
			arr[idxDic[ch1]].push_back(ch2);
			arr[idxDic[ch2]].push_back(ch1);
		}
		/*for(int i=0;i<arr.size();i++){
			for(map<char,int>::iterator it=idxDic.begin();it!=idxDic.end();it++)
				if(it->second==i){
					cout<<it->first<<"->";
					break;
				}
			for(int j=0;j<arr[i].size();j++){
				cout<<arr[i][j]<<' ';
			}
			cout<<endl;
		}*/

		int year = 0;
		while(flagDic.size()<N){
			int origN = flagDic.size();
			string flagToAdd;
			for(int i=0;i<arr.size();i++){
				char idxCh;
				for(map<char,int>::iterator it=idxDic.begin();it!=idxDic.end();it++)
					if(it->second==i){
						idxCh = it->first;
						break;
					}
				int flagCnt = 0;
				for(int j=0;j<arr[i].size();j++){
					if(flagDic.count(arr[i][j])>0)
						flagCnt++;
				}
				if(flagCnt>=3 && flagDic.count(idxCh)==0)
					flagToAdd+=idxCh;
			}
			for(int i=0;i<flagToAdd.length();i++)
				flagDic[flagToAdd[i]] = 1;
			//cout<<origN<<' '<<flagDic.size()<<endl;
			if(origN==flagDic.size())
				break;
			year++;
		}
		if(flagDic.size()==N)
			cout<<"WAKE UP IN, "<<year<<", YEARS";
		else
			cout<<"THIS BRAIN NEVER WAKES UP";
		cout<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
