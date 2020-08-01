#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>

using namespace std;

template<typename T>
void PV(vector<T> &v)
{
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl;
};

// static int dx[] = {-1,-1,-1,0,0,1,1,1};
// static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    
	clock_t begin = clock();
#endif

	int t, case_no = 1;
    
    while(cin>>t)
    {
        if(!t)
            break;
        
        map<int, int> team;
        queue<int> q, tq[1001];
        int num, people;
        
        for(int i = 0; i < t; i++)
        {
            cin>>people;
            while(people--)
            {
                cin>>num;
                team[num] = i;
            }
        }
        
        cout << "Scenario #" << case_no++ <<endl;
        
        string cmd;
        while(cin>>cmd)
        {
            if(cmd[0] == 'S')
                break;
            else if(cmd[0] == 'E')
            {
                cin>>num;
                int teamNo = team[num];
                if(tq[teamNo].empty())
                    q.push(teamNo);
                tq[teamNo].push(num);
            }
            else if(cmd[0] == 'D')
            {
                int teamNo = q.front();
                int peopleNo = tq[teamNo].front();
                cout<<peopleNo<<endl;
                tq[teamNo].pop();
                if(tq[teamNo].empty())
                    q.pop();
            }
        }
        cout<<endl;
    }
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    
    cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
    
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
