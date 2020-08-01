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

	int N, R, C;
    while(cin>>N>>R>>C)
    {
        if(!N && !R && !C)
            break;
         
        char board[10][9] = {};        
        char ch;
        int r, c;
        while(N--)
        {
            cin>>ch>>r>>c;
            board[r-1][c-1] = ch;
        }
        
        // for(int i = 0; i < 10; i++)
        // {
            // for(int j = 0; j < 9; j++)
            // {
                // if(board[i][j])
                    // cout<<board[i][j];
                // else
                    // cout<<"*";
            // }
            // cout<<endl;
        // }
        // cout<<endl;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        int checkmate = 1;
        for(int i = 0; i < 4 && checkmate; i++)
        {
            int row = R - 1 + dx[i];
            int col = C - 1 + dy[i];
            if(row >= 0 && row <= 2 && col >= 3 && col <= 5)
            {
                string str[4] = {}; 
                
                int temp = 0;
                // cout<<"B at ("<<row<<","<<col<<")"<<endl;
                //checkmate for R/C/G
                for(int L = col - 1; L >= 0; L--)
                {
                    if(board[row][L])
                        str[0].push_back(board[row][L]);
                }
                for(int R = col + 1; R < 9; R++)
                {
                    if(board[row][R])
                        str[1].push_back(board[row][R]);
                }
                for(int U = row - 1; U >= 0; U--)
                {
                    if(board[U][col])
                        str[2].push_back(board[U][col]);
                }
                for(int D = row + 1; D < 10; D++)
                {
                    if(board[D][col])
                        str[3].push_back(board[D][col]);
                }
                for(int j = 0; j < 4 && !temp; j++)
                {
                    // cout<<j<<" "<<str[j]<<endl;
                    if(str[j].size() > 0)
                    {
                        if(str[j][0] == 'R' || str[j][0] == 'G')
                            temp = 1;
                    }
                    
                    if(str[j].size() > 1)
                    {
                        if(str[j][1] == 'C')
                            temp = 1;
                    }
                }

                //checkmate for H
                int hx[] = {-2, 2, -2, 2, -1, 1, -1, 1};
                int hy[] = {1, 1, -1, -1, 2, 2, -2, -2};
                // cout<<row<<" "<<col<<endl;
                for(int j = 0; j < 8 && !temp; j++)
                {
                    int hr = row + hx[j];
                    int hc = col + hy[j];
                    int tr = (j < 4) ? (hx[j]<0?1:-1) : 0;
                    int tc = (j < 4) ? 0 : (hy[j]<0?1:-1);
                    // cout<<hr<<","<<hc<<" "<<(hr+tr)<<","<<(hc+tc)<<endl;
                    if(hr >=0 && hr < 10 && hc >= 0 && hc < 9)
                    {
                        if(board[hr][hc] == 'H' && !board[hr+tr][hc+tc])
                        {
                            temp = 1;
                        }
                    }
                }
                checkmate &= temp;
            }
        }
        
        if(checkmate)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
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
