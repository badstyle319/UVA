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
int readint(int len)
{
    int rv = 0;
    for(int i = 0; i < len;)
    {
        char ch;
        do{
            cin>>ch;
        }while(ch == '\r' || ch == '\n');
        
        rv = rv * 2 + ch - '0';
        i++;
    }
    return rv;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    
	// clock_t begin = clock();
#endif

	string line;
    while(getline(cin, line))
    {        
        char codes[8][1<<8] = {0};
        
        for(int len = 1, i = 0; len <= 7 && i < line.length(); len++)
        {
            for(int j = 0; j < (1 << len) - 1 && i < line.length(); j++)
            {
                if(line[i] == '\r' || line[i] == '\n')
                    continue;
                
                codes[len-1][j] = line[i++];
            }
        }

        while(1)
        {
            int len = readint(3);

            if(len == 0)
                break;
            
            while(1)
            {
                int v = readint(len);

                if(v == (1<<len) - 1)
                    break;
                
                cout<<codes[len - 1][v];
            }
        }
        cout<<endl;
        
        //important: get rid of current line
        getline(cin, line);
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
