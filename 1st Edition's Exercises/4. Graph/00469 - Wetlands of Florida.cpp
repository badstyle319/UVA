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

vector<string> arr;
int answer = 0;

void flood(int r, int c, char ch){
	if(r>=arr.size() || r<0 || c>=arr[0].length() || c<0)
		return;

	if(arr[r][c]==ch){
		answer++;
		arr[r][c] = tolower(ch);
		static int dx[] = {-1,-1,-1,0,0,1,1,1};
		static int dy[] = {-1,0,1,-1,1,-1,0,1};
		for(int k=0;k<8;k++)
			flood(r+dx[k], c+dy[k], ch);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string line;
	int caseNum, r, c;
	cin>>caseNum;
	getline(cin, line);//consume the ending after the case number
	getline(cin, line);//consume the blank line
	while(caseNum-->0){
		///////////////
		arr.clear();
		getline(cin, line);
		while(1){
			if(line.length()>0 && (line[0]=='L' || line[0]=='W')){
				arr.push_back(line);
			}else
				break;
			getline(cin, line);
		}
		stringstream ss(line);
		ss>>r>>c;
		r--;c--;
		answer = 0;
		for(int i=0;i<arr.size();i++)
			for(int j=0;j<arr[i].size();j++)
				arr[i][j] = toupper(arr[i][j]);
		flood(r, c, arr[r][c]);
		cout<<answer<<endl;
		while(getline(cin, line)){
			if(line.length()>0){
				stringstream ss2(line);
				ss2>>r>>c;
				r--;c--;
				answer = 0;
				for(int i=0;i<arr.size();i++)
					for(int j=0;j<arr[i].size();j++)
						arr[i][j] = toupper(arr[i][j]);
				flood(r, c, arr[r][c]);
				cout<<answer<<endl;
			}else
				break;
		}
		if(caseNum)
			cout<<endl;
		///////////////
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
