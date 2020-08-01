#include <bits/stdc++.h>
#define _ io_base::sync_with_stdio(0);cin.tie(0);

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

typedef struct
{
	int arrival;
	int leave;
}Guest;

void solve()
{
	int N, counter = 0, maximum = 0;
	vector<int> time;
	
	cin>>N;
	for(int i=0; i<N; i++)
	{
		Guest g;
		cin>>g.arrival>>g.leave;
		time.push_back(g.arrival);
		time.push_back(-g.leave);
	}
	
	sort(time.begin(), time.end(),
		[](int i, int j)
		{
			return abs(i) < abs(j);
		});
	
	for(auto v: time)
	{
		if(v>=0)
			counter++;
		else
			counter--;
		maximum = max(maximum, counter);
	}
	cout<<maximum<<" ";
	
	counter = 0;
	int flag = 0;
	for(int i=0; i<N*2; i++)
	{
		if(time[i]>=0)
			counter++;
		else
			counter--;
		if(!flag && counter == maximum)
		{
			cout<<time[i]<<"-";
			flag = 1;
		}
		else if(flag && (time[i]<0 || i==N-1))
		{
			cout<<abs(time[i])<<" ";
			flag = 0;
		}
	}
}

int main()
{
	int case_num, no=1;
	cin>>case_num;
	while(case_num-->0){
		cout<<"Case #"<<no++<<": ";
		solve();
	}

	return 0;
}
