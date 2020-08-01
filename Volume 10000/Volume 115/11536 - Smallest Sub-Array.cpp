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

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int caseNum, no=1;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		int N,M,K;
		cin>>N>>M>>K;
		vector<int> Xs;
		for(int i=1;i<=N;i++){
			switch(i){
				case 1:
				case 2:
				case 3:
					Xs.push_back(i);
					break;
				default:
					Xs.push_back((Xs[i-2]+Xs[i-3]+Xs[i-4])%M+1);
					break;
			}
		}
		// cout<<"N="<<N<<" M="<<M<<" K="<<K<<endl;
		// for(int i=0;i<Xs.size();i++)
			// cout<<Xs[i]<<endl;
		// cout<<endl;
		int result = N+1;
		map<int,int> dic;
		for(int i=-1, j=0;j<Xs.size();){
			if(Xs[j]<=K){
				if(i==-1)
					i=j;
				dic[Xs[j]]+=1;
				while(dic[Xs[i]]>1){
					dic[Xs[i]]-=1;
					i++;
					while(Xs[i]>K)
						i++;
				}
			}
			if(dic.size()==K)
				result = min(result, j-i+1);
			j++;
			// for(map<int,int>::iterator it=dic.begin();it!=dic.end();it++)
				// cout<<it->first<<' ';
			// cout<<endl;
		}
		cout<<"Case "<<no++<<": ";
		if(result==N+1)
			cout<<"sequence nai"<<endl;
		else
			cout<<result<<endl;
		///////////////
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
