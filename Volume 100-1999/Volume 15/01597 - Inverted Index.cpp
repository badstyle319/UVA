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

typedef struct InvertedIndex{
	int volume;
	int line;
}ii;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int volumeNum;
	cin>>volumeNum;
	string line;
	getline(cin,line);
	//save articles
	vector< vector<string> > articles(volumeNum);
	for(int i=0;i<volumeNum;i++){
		do{
			getline(cin,line);
			if(line=="**********")
				break;
			articles[i].push_back(line);
		}while(1);
	}
	//convert to inverted index
	map<string, vector<ii> > dic;
	map<string, vector<ii> >::iterator it;
	const char *delim = " ,-.()!?";
	char *pch;
	char buf[81];
	for(int i=0;i<articles.size();i++){
		for(int j=0;j<articles[i].size();j++){
			line = articles[i][j];
			memset(buf, 0, sizeof(buf));
			strncpy(buf, line.c_str(), line.length());
			pch = strtok(buf, delim);
			while(pch){
				// cout<<pch<<endl;
				string token(pch);
				transform(token.begin(),token.end(),token.begin(), ::tolower);
				// cout<<token<<' '<<i+1<<' '<<j+1<<endl;
				if(!dic.count(token))
					dic[token] = vector<ii>();
				ii val;
				val.volume = i;
				val.line = j;
				int found = 0;
				for(int k=0;k<dic[token].size();k++)
					if(dic[token][k].volume==val.volume && dic[token][k].line==val.line){
						found = 1;
						break;
					}
				if(!found)
					dic[token].push_back(val);
				pch = strtok(NULL, delim);
			}
		}
	}
	
	int caseNum;
	cin>>caseNum;
	getline(cin, line);
	while(caseNum-->0){
		///////////////
		getline(cin, line);
		int type = 0;
		if(line.find("AND")!=string::npos){
			type = 1;
		}else if(line.find("NOT")!=string::npos){
			type = 2;
		}else if(line.find("OR")!=string::npos){
			type = 3;
		}
		for(it=dic.begin();it!=dic.end();it++){
			for(int i=0;i<it->second.size();i++){
				// cout<<"volume:"<<it->second.at(i).volume<<" line:"<<it->second.at(i).line<<endl;
			}
		}
		switch(type){
			case 0:
				// vector<ii> ptr = dic[line];
				for(int i=0;i<dic[line].size();i++){
					cout<<articles[dic[line][i].volume][dic[line][i].line]<<endl;
					if(i==dic[line].size()-1)
						cout<<"==========";
					else
						cout<<"---------";
					cout<<endl;
				}
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
		}
		///////////////
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
