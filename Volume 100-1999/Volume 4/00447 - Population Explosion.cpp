#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

#define LL long long
#define ULL unsigned long long

using namespace std;

void go(int x, int y, char map1[20][20], char map2[20][20])
{
    static int dx[] = {-1,-1,-1,0,0,1,1,1};
	static int dy[] = {-1,0,1,-1,1,-1,0,1};
	int n=0;
	for(int i=0;i<8;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx>=0 && tx<20 && ty>=0 && ty<20)
			if(map1[tx][ty]=='O')
				n++;
	}
 
    if (map1[x][y]==' ')
        if (n == 3)                 // 復活
            map2[x][y] = 'O';
        else                        // 仍舊死亡
            map2[x][y] = map1[x][y];
    else
        if (n == 2 || n == 3)       // 存活
            map2[x][y] = 'O';
        else if (n == 0 || n == 1)  // 死於孤單
            map2[x][y] = ' ';
        else if (n >= 4)            // 死於擁擠
            map2[x][y] = ' ';
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string line;
	int caseNum, year, row, col;
	cin>>caseNum;
	getline(cin, line);
	getline(cin, line);
	while(caseNum-->0){
		cin>>year;
		getline(cin, line);

		char arr[2][20][20];
		for(int i=0;i<20;i++)
			for(int j=0;j<20;j++){
				arr[0][i][j]=' ';
			}
		while(1){
			getline(cin, line);
			if(line.empty())
				break;

			stringstream ss(line);
			ss>>row>>col;
			arr[0][row-1][col-1] = 'O';
		}

		for(int i=0;i<20;i++)
			cout<<"*";
		cout<<endl;
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++)
				cout<<arr[0][i][j];
			cout<<endl;
		}
		for(int i=0;i<20;i++)
			cout<<"*";
		cout<<endl;
		for(int y=0;y<(year-1);y++){
			for(int i=0;i<20;i++)
				for(int j=0;j<20;j++)
					go(i, j, arr[y%2], arr[(y+1)%2]);
			
			for(int i=0;i<20;i++){
				for(int j=0;j<20;j++)
					cout<<arr[(y+1)%2][i][j];
				cout<<endl;
			}
			for(int i=0;i<20;i++)
				cout<<"*";
			cout<<endl;
		}
		if(caseNum)
			cout<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
