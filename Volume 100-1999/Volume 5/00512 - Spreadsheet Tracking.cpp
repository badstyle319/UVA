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

enum OP
{
    DR,
    DC,
    IC,
    IR,
    EX
};

typedef struct
{
    OP op;
    VI data;
}CMD;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    
	// clock_t begin = clock();
#endif

    int r, c, case_no = 1;
    string line;
	
	while(cin>>r>>c)
    {
        if(!r && !c)
            break;
        
        if(case_no>1)
            cout<<endl;
        
        cout<<"Spreadsheet #"<< case_no++<<endl;
        
        vector< CMD > cmds;
        int n;
        
        cin>>n;
        getline(cin, line);
        while(n--)
        {
            string s;
            int d;
            CMD cmd;
            
            cin>>s>>d;
            if(s == "DR")
                cmd.op = DR;
            else if(s == "DC")
                cmd.op = DC;
            else if(s == "IC")
                cmd.op = IC;
            else if(s == "IR")
                cmd.op = IR;
            else
                cmd.op = EX;
            if(cmd.op == EX)
            {
                cmd.data.resize(4, 0);
                cmd.data[0] = d;
                for(int i = 1; i < 4; i++)
                    cin>>cmd.data[i];
            }
            else
            {
                cmd.data.resize(d, 0);
                for(int i = 0; i < d; i++)
                    cin>>cmd.data[i];
            }

            cmds.push_back(cmd);
        }
        // for(auto cmd:cmds)
        // {
            // cout<<cmd.op<<":";
            // for(auto d:cmd.data)
                // cout<<d<<" ";
            // cout<<endl;
        // }

        cin>>n;
        while(n--)
        {
            int sx, sy, dx, dy;
            int nCnt;
            
            cin>>sx>>sy;
            dx = sx;
            dy = sy;
            for(auto cmd:cmds)
            {
                // cout<<cmd.op<<":"<<dx<<","<<dy<<" to "; 
                switch(cmd.op)
                {
                    case DC:
                        if(find(cmd.data.begin(), cmd.data.end(), dy) != cmd.data.end())
                            dy = -1;
                        else
                        {
                            nCnt = 0;
                            for(auto d:cmd.data)
                            {
                                if(d < dy)
                                    nCnt++;
                            }
                            dy -= nCnt;
                        }
                        break;
                    case DR:
                        if(find(cmd.data.begin(), cmd.data.end(), dx) != cmd.data.end())
                            dx = -1;
                        else
                        {
                            nCnt = 0;
                            for(auto d:cmd.data)
                            {
                                if(d < dx)
                                    nCnt++;
                            }
                            dx -= nCnt;
                        }
                        break;
                    case IC:
                        nCnt = 0;
                        for(auto d:cmd.data)
                        {
                            if(d <= dy)
                                nCnt++;
                        }
                        dy += nCnt;
                        break;
                    case IR:
                        nCnt = 0;
                        for(auto d:cmd.data)
                        {
                            if(d <= dx)
                                nCnt++;
                        }
                        dx += nCnt;
                        break;
                    case EX:
                        if(cmd.data[0] == dx && cmd.data[1] == dy)
                        {
                            dx = cmd.data[2];
                            dy = cmd.data[3];
                        }
                        else if(cmd.data[2] == dx && cmd.data[3] == dy)
                        {
                            dx = cmd.data[0];
                            dy = cmd.data[1];
                        }
                        break;
                }
                // cout<<dx<<","<<dy<<endl;
            }
            cout<<"Cell data in ("<<sx<<","<<sy<<") ";
            if(dx == -1 || dy == -1)
                cout<<"GONE";
            else
                cout<<"moved to ("<<dx<<","<<dy<<")";
            cout<<endl;
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
