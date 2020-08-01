#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\UVA\\in.txt", "r", stdin);
	freopen("D:\\UVA\\out.txt", "w", stdout);
#endif
	
    int n;
	string line;
    map<int,int> dic;
    vector< vector<int> > buf;
    
	cin>>n;
	buf.resize(n, vector<int>());
    
	for(int i = 0; i < n; i++)
    {
		buf[i].push_back(i);
		dic[i] = i;
	}
    
	while(getline(cin, line))
    {
		if(line == "quit")
			break;

		stringstream ss(line);
		string cmd1, cmd2;
		int a, b;
        
		ss>>cmd1>>a>>cmd2>>b;
		/***this is important***/
		if(dic[a] == dic[b])
			continue;

		if(cmd2 == "onto")
        {
			while(buf[dic[b]].back() != b)
            {
				int val = buf[dic[b]].back();
				buf[val].push_back(val);
				dic[val] = val;
				buf[dic[b]].pop_back();
			}
		}
        
		if(cmd1 == "move")
        {
			while(buf[dic[a]].back() != a)
            {
				int val = buf[dic[a]].back();
				buf[val].push_back(val);
				dic[val] = val;
				buf[dic[a]].pop_back();
			}
		}
		
		int idx = 0;
		while(buf[dic[a]][idx] != a)
			idx++;
        
		vector<int> temp(buf[dic[a]].begin() + idx, buf[dic[a]].end());
		buf[dic[a]].erase(buf[dic[a]].begin() + idx, buf[dic[a]].end());
		for(int i = 0; i < temp.size(); i++)
        {
			buf[dic[b]].push_back(temp[i]);
			dic[temp[i]] = dic[b];
		}
	}

	for(int i = 0; i < n;i++)
    {
		cout<<i<<":";
		for(int j = 0; j < buf[i].size(); j++)
			cout<<' '<<buf[i][j];
		cout<<endl;
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif 
	
	return 0;
}
