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

struct point{
	int x,y;
};

point judge(vector<point> arr){
	for(int i=0;i<=500;i++){
		for(int j=-500;j<=500;j++){
			int illegal = 0, temp = 0;
			for(int k=0;k<arr.size();k++){
				int t = arr[k].x*i+arr[k].y*j;
				if(t==0){
					illegal = 1;
					break;
				}else if(t<0)
					temp--;
				else
					temp++;
			}
			if(!illegal && !temp){
				point p;
				p.x = i;
				p.y = j;
				return p;
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	
	int N;
	while(cin>>N){
		if(!N)
			break;

		vector<point> vec(2*N, point());
		for(int i=0;i<2*N;i++){
			cin>>vec[i].x>>vec[i].y;
		}
		
		point p = judge(vec);
		cout<<p.x<<' '<<p.y<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
