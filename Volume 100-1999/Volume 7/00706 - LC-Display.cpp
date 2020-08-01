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

using namespace std;

void drawNum(char **arr, int row, int col, int width, int num){
	for(int i=0;i<width;i++){
		switch(num){
			case 0:
				arr[row][col+1+i] = '-';
				arr[row+i+1][col] = '|';
				arr[row+i+1][col+width+1] = '|';
				arr[row+i+2+width][col] = '|';
				arr[row+i+2+width][col+width+1] = '|';
				arr[row+2+2*width][col+1+i] = '-';
				break;
			case 1:
				arr[row+i+1][col+width+1] = '|';
				arr[row+i+2+width][col+width+1] = '|';
				break;
			case 2:
				arr[row][col+1+i] = '-';
				arr[row+i+1][col+width+1] = '|';
				arr[row+width+1][col+1+i]='-';
				arr[row+i+2+width][col] = '|';
				arr[row+2+2*width][col+1+i] = '-';
				break;
			case 3:
				arr[row][col+1+i] = '-';
				arr[row+i+1][col+width+1] = '|';
				arr[row+width+1][col+1+i]='-';
				arr[row+i+2+width][col+width+1] = '|';
				arr[row+2+2*width][col+1+i] = '-';
				break;
			case 4:
				arr[row+i+1][col] = '|';
				arr[row+i+1][col+width+1] = '|';
				arr[row+width+1][col+1+i]='-';
				arr[row+i+2+width][col+width+1] = '|';
				break;
			case 5:
				arr[row][col+1+i] = '-';
				arr[row+i+1][col] = '|';
				arr[row+width+1][col+1+i]='-';
				arr[row+i+2+width][col+width+1] = '|';
				arr[row+2+2*width][col+1+i] = '-';
				break;
			case 6:
				arr[row][col+1+i] = '-';
				arr[row+i+1][col] = '|';
				arr[row+width+1][col+1+i]='-';
				arr[row+i+2+width][col] = '|';
				arr[row+i+2+width][col+width+1] = '|';
				arr[row+2+2*width][col+1+i] = '-';
				break;
			case 7:
			arr[row][col+1+i] = '-';
			arr[row+i+1][col+width+1] = '|';
			arr[row+i+2+width][col+width+1] = '|';
				break;
			case 8:
				arr[row][col+1+i] = '-';
				arr[row+i+1][col] = '|';
				arr[row+i+1][col+width+1] = '|';
				arr[row+width+1][col+1+i]='-';
				arr[row+i+2+width][col] = '|';
				arr[row+i+2+width][col+width+1] = '|';
				arr[row+2+2*width][col+1+i] = '-';
				break;
			case 9:
				arr[row][col+1+i] = '-';
				arr[row+i+1][col] = '|';
				arr[row+i+1][col+width+1] = '|';
				arr[row+width+1][col+1+i]='-';
				arr[row+i+2+width][col+width+1] = '|';
				arr[row+2+2*width][col+1+i] = '-';
				break;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int s;
	string n;
	while(1){
		cin>>s>>n;
		if(s==0 && n=="0")
			break;
		int row = 2*s+3;
		int col = (s+3)*n.length()-1;
		char **arr = new char*[row];
		for(int i=0;i<row;i++){
			arr[i] = new char[col];
			memset(arr[i], ' ', col);
		}

		for(int i=0;i<n.length();i++)
			drawNum(arr, 0, (s+2)*i+i*1, s, n[i]-'0');

		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
		cout<<endl;

		for(int i=0;i<row;i++)
			delete [] arr[i];
		delete [] arr;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
