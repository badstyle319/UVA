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

struct point{
	int x,y;
};

double distance(int x1, int y1, int x2, int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int cmp(const point point1, const point point2){
	return point1.x<point2.x;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int caseNum, n;
	cin>>caseNum;
	while(caseNum-->0){
		///////////////
		cin>>n;
		vector<point> points(n);
		for(int i=0;i<n;i++){
			cin>>points[i].x>>points[i].y;
		}
		sort(points.begin(),points.end(), cmp);
		/*for(int i=0;i<points.size();i++){
			cout<<points[i].x<<' '<<points[i].y<<endl;
		}
		cout<<endl;*/
		
		point temp = points[n-1];
		/*temp.x = 0;
		temp.y = 0;*/
		int high = temp.y;
		double ans = 0;
		for(int i=n-1;i>=0;i--){
			if(points[i].y>high){
				if(ans==0)
					ans+=distance(points[i].x, points[i].y, temp.x, temp.y);
				else
					ans+=distance(points[i].x, points[i].y, temp.x, temp.y)*abs(points[i].y-high)/(points[i].y-temp.y);
				high = points[i].y;
			}
			temp = points[i];
		}
		cout<<fixed<<setprecision(2)<<ans<<endl;
		///////////////
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
