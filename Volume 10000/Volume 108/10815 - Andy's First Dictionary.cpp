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

	string line;
    set<string> dict;
    
    while(getline(cin, line))
    {
        for(int i = 0; i < line.length(); i++)
        {
            if(isalpha(line[i]))
                line[i] = tolower(line[i]);
            else
                line[i] = ' ';      
        }
        
        stringstream ss(line);
        string word;
        
        while(ss>>word)
        {
            dict.insert(word);
        }
    }
    for(auto it:dict)
        cout<< it <<endl;
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    
    cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
    
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
