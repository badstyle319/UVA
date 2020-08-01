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

string normalize(string s)
{
    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    sort(s.begin(), s.end());
    return s;
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

	map<string, int> mp;
    VS words;
    string line;
    
    while(getline(cin, line))
    {
        if(line == "#")
            break;
        
        stringstream ss(line);
        string word;
        while(ss>>word)
        {
            words.push_back(word);
            string s = normalize(word);
            if(!mp.count(s))
                mp[s] = 0;
            mp[s] += 1;
        }
    }    
    sort(words.begin(), words.end());

    for(auto w:words)
    {
        if(mp[normalize(w)] == 1)
            cout<<w<<endl;
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
