#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <iomanip>
#include <limits>

#define UL unsigned long
#define LL long long

using namespace std;

struct point{
	int x;
	int y;
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	
	int caseNum;
	cin>>caseNum;
	while(caseNum-->0){
		/////////////
		int lines;
		cin>>lines;
		vector<point> data;
		vector<point>::iterator it;
		while(lines-->0){
			point p;
			cin>>p.x;
			cin>>p.y;
			for(it=data.begin();it!=data.end();it++)
				if((*it).x>p.x)
					break;
				else if((*it).x==p.x){
					if((*it).y>p.y)
						break;
				}
			data.insert(it, p);
		}
		
		int sz = data.size(), legal = 1;
		point temp;
		temp.x = (data[0].x+data[sz-1].x);
		temp.y = (data[0].y+data[sz-1].y);
		for(int i=1,j=sz-2;i<=j;i++,j--){
			if((data[i].x+data[j].x)!=temp.x || (data[i].y+data[j].y)!=temp.y){
				legal = 0;
				break;
			}	
		}
		if(legal)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		/////////////
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	
	return 0;
}