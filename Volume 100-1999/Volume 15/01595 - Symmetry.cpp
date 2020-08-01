#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>

using namespace std;

template<typename T>
void PV(vector<T> &v)
{
    cout<<v.size()<<":";
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl;
};

struct point
{
	int x, y;
    
    friend ostream& operator<<(ostream& stream, const point &p)
	{
		stream << "(" << p.x << "," << p.y << ")";
		return stream;
	}
	
	friend istream& operator>>(istream& in, point &p)
	{
		in >> p.x >> p.y;
		return in;
	}
};

int cmp(point p1, point p2)
{
	if(p1.x == p2.x)
		return p1.y < p2.y;
	else
		return p1.x < p2.x;
}

// static int dx[] = {-1,-1,-1,0,0,1,1,1};
// static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int caseNum, count;
	cin>>caseNum;
	while(caseNum--)
    {
		cin>>count;
		
		vector<point> points(count, point());
        
		for(int i = 0; i < count; i++)
            cin>> points[i];
		sort(points.begin(), points.end(), cmp);
        // PV(points);

		int symmetry = 1;
		int medianX = points.front().x + points.back().x;
		for(int i = 0, j = points.size() - 1; i < j; i++, j--)
        {
			if(medianX != (points[i].x + points[j].x))
            {
				symmetry = 0;
				break;
			}
			int found = 0;
			for(int k = 0; k < points.size(); k++)
            {
				if(points[k].x == points[i].x && points[k].y == points[j].y)
                {
					found = 1;
					break;
				}
			}
			if(!found){
				symmetry = 0;
				break;
			}
		}
		
		if(symmetry)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif 
	
	return 0;
}
