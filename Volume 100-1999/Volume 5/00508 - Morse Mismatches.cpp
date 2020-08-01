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

// static int dx[] = {-1,-1,-1,0,0,1,1,1};
// static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    
	// clock_t begin = clock();
#endif

    map<char, string> morse;
    map<string, string> words;
    string s1, s2;
    
    while(cin>>s1)
    {
        if(s1 != "*")
        {
            cin>>s2;
            morse[s1[0]] = s2;
        }
        else
        {
            while(cin>>s1)
            {
                if(s1 == "*")
                    break;
                
                words[s1] = "";
                for(char ch:s1)
                {
                    words[s1].append(morse[ch]);
                }
            }
            // for(auto kv:words)
                // cout<<kv.first<<" "<<kv.second<<endl;
            // cout<<endl;
            while(cin>>s1)
            {
                if(s1 == "*")
                    break;

                // cout<<s1<<endl;
                set<string> match;
                pair<int, string> partial(480, s1);
                for(auto kv:words)
                {
                    if(kv.second == s1)
                    {
                        match.insert(kv.first);
                    }
                    else
                    {
                        int nMin = min((int)kv.second.length(), (int)s1.length());
                        if(kv.second.substr(0, nMin) == s1.substr(0, nMin))
                        {
                            int diff = abs((int)kv.second.length() - (int)s1.length());
                            if(diff < partial.first)
                                partial = make_pair(diff, kv.first);
                        }
                    }
                }
                if(match.size())
                {
                    cout<< *match.begin();
                    if(match.size() > 1)
                        cout<<"!";
                    cout<<endl;
                }
                else
                {
                    cout<<partial.second<<"?"<<endl;
                }
            }
            morse.clear();
            words.clear();
        }
        
    }
	
#ifndef ONLINE_JUDGE
	// clock_t end = clock();
	// double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    
    // cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
    
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
