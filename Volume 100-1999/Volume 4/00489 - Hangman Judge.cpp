#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PF printf

using namespace std;

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

    int Round;
    string t, g;

    while(cin>>Round>>t>>g)
    {
        LL flag = 0;
        int win = 0, lose = 0, wrong = 0;
        
        for(int i = 0; i < t.length(); i++)
            flag |= 1 << (t[i] - 'a');

        for(int i = 0; i < g.length(); i++)
        {
            if(flag & (1 << (g[i] - 'a')))
            {
                flag &= ~(1 << (g[i] - 'a'));
                if(!flag)
                {
                    win = 1;
                    break;
                }
            }
            else
            {    
                wrong++;
                if(wrong > 6)
                {
                    lose = 1;
                    break;
                }
            }
        }
        cout<<"Round "<<Round<<endl;
        if(win)
            cout<<"You win.";
        else if(lose)
            cout<<"You lose.";
        else
            cout<<"You chickened out.";
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
