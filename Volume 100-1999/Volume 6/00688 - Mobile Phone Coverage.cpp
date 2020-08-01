#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

typedef struct
{
	float x;
	float y1, y2;
} Point;

int cmp(Point p1, Point p2)
{
	return abs(p1.x) < abs(p2.x);
}

float solve(int n)
{
	vector<Point> d;
	Point p;
	float x, y, r, sum = 0;
	int cnt = 0;
	vector<int> h;
	
	for(int i=0; i<n; i++)
	{
		cin>>x>>y>>r;
		d.push_back({.x = x-r, .y1 = y-r, .y2 = -y-r});
		d.push_back({.x = -x-r, .y1 = y-r, .y2 = -y-r});
	}
	sort(d.begin(), d.end(), cmp);
	
	for(int i=0; i<d.size()-1; i++)
	{
		float w =  abs(abs(d[i].x) - abs(d[i+1].x));
		if(d[i].x>=0)
		{
			h.push_back(d[i].y1);
			h.push_back(d[i].y2);
			while(d[i+1].x==d[i].x)
			{
				h.push_back(d[i+1].y1);
				h.push_back(d[i+1].y2);
				i++;
			}
		}
		sort(h.begin(), h.end(), [](int v1, int v2){ return abs(v1) < abs(v2);});
		
		if(h.size()>0)
		{
			int cnt = 0, h1;
			for(int j=0; j<h.size(); j++)
			{
				if(cnt==0)
					h1 = h[j];
				if(h[j]>=0)
					cnt++;
				else
					cnt--;
				if(cnt==0)
				{
					sum += (abs(h[j])-h1) * w;
				}
			}
		}
		if(d[i+1].x<0)
		{
			h.erase(std::remove(h.begin(), h.end(), d[i+1].y1), h.end());
			h.erase(std::remove(h.begin(), h.end(), d[i+1].y2), h.end());	
		}
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	clock_t begin = clock();
#endif
	
	int n, no = 1;
	do{
		cin>>n;
		if(n==0)
			break;
		
		printf("%d %.2f\n", no++, solve(n));
	}while(1);
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	cout<<"elapsed: "<<elapsed_secs<<endl;
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
