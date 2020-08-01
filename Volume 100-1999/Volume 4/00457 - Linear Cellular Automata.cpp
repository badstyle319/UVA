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

int dna[10];
void go(int i, int arr1[42], int arr2[42]){
	int t = arr1[i-1]+arr1[i]+arr1[i+1];
	arr2[i] = dna[t];
}

void print(int dish[42]){
	for(int i=1;i<41;i++){
		int val = dish[i];
		switch(val){
			case 0:
				cout<<' ';
				break;
			case 1:
				cout<<'.';
				break;
			case 2:
				cout<<'x';
				break;
			case 3:
				cout<<'W';
				break;
		}
	}
	cout<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int dish[2][42];
	int caseNum;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		for(int i=0;i<10;i++)
			cin>>dna[i];
		for(int i=0;i<42;i++){
			dish[0][i] = 0;
			dish[1][i] = 0;
		}
		dish[0][20]=1;

		print(dish[0]);
		for(int i=0;i<49;i++){
			for(int j=1;j<41;j++)
				go(j, dish[i%2], dish[(i+1)%2]);
			print(dish[(i+1)%2]);
		}
		///////////////
		if(caseNum)
			cout<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
