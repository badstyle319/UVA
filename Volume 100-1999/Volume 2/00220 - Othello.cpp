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

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

char board[8][8];
int B, W;

void print()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

void List(int& isW)
{
    set< pair<int,int> > s;
    char player = isW?'W':'B';
    char apponent = isW?'B':'W';
    
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == player)
            {
                for(int k = 0; k < 8; k++)
                {
                    int flag = 0;
                    for(int r = i + dx[k], c = j + dy[k]; r >= 0 && r < 8 && c >= 0 && c < 8; r += dx[k], c += dy[k])
                    {
                        if(!flag)
                        {
                            if(board[r][c] == apponent)
                                flag = 1;
                            else
                                break;
                        }
                        else if(flag)
                        {
                            if(board[r][c] == player)
                                break;
                            else if(board[r][c] == '-')
                            {
                                s.insert(make_pair(r + 1, c + 1));
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    if(s.size() == 0)
    {
        cout<<"No legal move.";
        isW = !isW;
    }
    else
    {
        bool first = true;
        for(auto it = s.begin(); it != s.end(); it++)
        {
            if(!first)
                cout<<" ";
            cout<<"("<<it->first<<","<<it->second<<")";
            first = false;
        }
    }
    cout<<endl;
}

void Move(int& isW, int i, int j)
{
    char player = isW?'W':'B';
    char apponent = isW?'B':'W';

    // cout<<player<<" move "<<i<<","<<j<<endl;
 
    i--;
    j--;
    board[i][j] = player;
    if(isW)
        W++;
    else
        B++;
    
    for(int k = 0; k < 8; k++)
    {
        vector< pair<int,int> > v;
        int flag = 0;
        for(int r = i + dx[k], c = j + dy[k]; !flag && r >= 0 && r < 8 && c >= 0 && c < 8; r += dx[k], c += dy[k])
        {
            if(board[r][c] == apponent)
                v.push_back(make_pair(r, c));
            else if(board[r][c] == player)
                flag = 1;
            else
                break;
        }
        if(flag)
        {
            for(auto p:v)
            {
                board[p.first][p.second] = player;
            }
            if(isW)
            {
                B -= v.size();
                W += v.size();
            }
            else
            {
                B += v.size();
                W -= v.size();
            }
        }
    }
    cout<<"Black -"<<setw(3)<<B<<" White -"<<setw(3)<<W<<endl;
    
    isW = !isW;
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

	int N;

    cin>>N;
    while(N--)
    {
        int current; //0:black 1:white
        char r, c;
        char ch;
        
        B = W = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                cin>>board[i][j];
                if(board[i][j] == 'B')
                    B++;
                else if(board[i][j] == 'W')
                    W++;
            }
        }
        
        cin>>ch;
        if(ch == 'B')
            current = 0;
        else
            current = 1;

        // print();
        while(cin>>ch)
        {
            if(ch == 'L')
            {
                List(current);
            }
            else if(ch == 'M')
            {
                cin>>r>>c;
                Move(current, r - '0', c - '0');
                // print();
            }
            else
            {
                print();
                break;
            }
        }
        
        if(N)
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
