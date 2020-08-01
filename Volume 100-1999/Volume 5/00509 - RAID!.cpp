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

	int d, s, b, p, case_no = 1;
    char ch;
    string line;
    
    while(cin>>d)
    {
        if(!d)
            break;
        
        cin>>s>>b>>ch;
        getline(cin, line);
        p = (ch == 'E')?0:1;

        VS v;
        v.resize(b, "");
        for(int i = 0; i < d; i++)
        {
            getline(cin, line);
            for(int j = 0, k = 0; j < b; j++, k += s)
            {
                v[j].append(line.substr(k, s));
            }
        }
        
        int invalid = 0;
        for(int i = 0; i < b; i++)
        {
            for(int j = 0; j < s; j++)
            {
                VI pos;
                bool first = true;
                int check;
                for(int k = 0; k < v[i].length(); k += s)
                {
                    if(v[i][k+j] == 'x')
                    {
                        pos.push_back(k+j);
                    }
                    else
                    {
                        if(first)
                        {
                            first = false;
                            check = v[i][k+j] - '0';
                        }
                        else
                            check ^= v[i][k+j] - '0';
                    }
                }
                switch((int)pos.size())
                {
                    case 0:
                        if(check != p)
                            invalid = 1;
                        break;
                    case 1:
                        v[i][pos[0]] = (check ^ p) + '0';
                        break;
                    default:
                        invalid = 1;
                        break;
                }
                
                
            }
        }
        
        string str;
        for(int i = 0, k = 0; i < b; i++)
        {
            for(int j = 0; j < v[i].length(); j += s)
            {
                if(i % d != j / s)
                    str.append(v[i].substr(j, s));
                // cout<<v[i].substr(j, s)<<" ";
            }
            // cout<<endl;
        }
        // cout<<endl;
        // cout<<str<<endl;

        cout<<"Disk set "<< case_no++ <<" is ";
        if(!invalid)
        {
            cout<<"valid, contents are: ";
            int len = str.length();
            if(len % 4)
                str.append(4 - len % 4, '0');
            for(int i = 0; i < str.length(); i += 4)
            {
                bitset<4> bs(str.substr(i, 4));
                char buf[2];
                sprintf(buf, "%X", bs.to_ulong());
                cout<<buf;
                //important: not support
                // cout<<hex<<uppercase<<bs.to_ulong();
            }
        }
        else
        {
            cout<<"invalid.";
        }
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
