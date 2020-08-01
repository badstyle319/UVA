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

map< set<int>, int > mp;
map<int, set<int> > dict;

int getID(set<int> mSet)
{
    if(mp.count(mSet))
        return mp[mSet];
    mp[mSet] = mp.size() - 1;
    dict[mp[mSet]] = mSet;
    return mp[mSet];
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

	int T, N;
    
    cin>>T;
    while(T--)
    {
        stack<int> s;
        
        mp.clear();
        dict.clear();
        
        cin>>N;
        for(int i = 0; i < N; i++)
        {
            set<int> s1, s2, s3;
            string cmd;
            
            cin>>cmd;
            switch(cmd[0])
            {
                case 'P':
                    s.push(getID(set<int>()));
                    break;
                case 'D':
                    s.push(s.top());
                    break;
                case 'U':
                    s1 = dict[s.top()];
                    s.pop();
                    s2 = dict[s.top()];
                    s.pop();
                    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
                    s.push(getID(s3));
                    break;
                case 'I':
                    s1 = dict[s.top()];
                    s.pop();
                    s2 = dict[s.top()];
                    s.pop();
                    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
                    s.push(getID(s3));
                    break;
                case 'A':
                    s1 = dict[s.top()];
                    s.pop();
                    s2 = dict[s.top()];
                    s.pop();
                    s2.insert(getID(s1));
                    s.push(getID(s2));
                    break;
            }
            cout<<dict[s.top()].size()<<endl;
        }
        cout<<"***"<<endl;
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
