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

	vector<string> arr;
    string line;
    int case_no = 1;

    arr.resize(5, "");
    do
    {
        int row, col;
        
        getline(cin, line);
        if(line == "Z")
            break;
        else
            arr[0] = line;
        for(int c = 0; c < line.length(); c++)
        {
            if(line[c] == ' ')
            {
                row = 0;
                col = c;
                break;
            }
        }
        for(int r = 1; r < 5; r++)
        {
            getline(cin, line);
            arr[r] = line;
           for(int c = 0; c < 5; c++)
           {
               if(arr[r][c] == ' ')
               {
                   row = r;
                   col = c;
                   break;
               }
           }
        }

        bool illegal = 0;
        do{
            getline(cin, line);
            for(int i = 0; i < line.length(); i++)
            {
                int dr = 0, dc = 0;
                switch(line[i])
                {
                    case 'A':
                        dr = -1;
                        break;
                    case 'B':
                        dr = 1;
                        break;
                    case 'L':
                        dc = -1;
                        break;
                    case 'R':
                        dc = 1;
                        break;
                }
                if( row + dr < 5 && row + dr >= 0 && col + dc < 5 && col + dc >= 0)
                {
                    swap(arr[row][col], arr[row+dr][col+dc]);
                    row += dr;
                    col += dc;
                }
                else
                {
                    illegal = 1;
                    break;
                }
            }
            
            if(line.back() == '0')
                break;
        }while(1);
        
        if(case_no != 1)
            cout<<endl;
        
        cout<<"Puzzle #"<<case_no<<":"<<endl;
        if(illegal)
            cout<<"This puzzle has no final configuration."<<endl;
        else
        {
            for(int i = 0; i < 5; i++)
            {
                cout<<arr[i][0];
                for(int j = 1; j < 5; j++)
                    cout<<" "<<arr[i][j];
                cout<<endl;
            }
        }
        
        case_no++;
    }while(1);
    
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    
    cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
    
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
