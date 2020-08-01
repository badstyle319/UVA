#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	int num[100][100];
	int cnt=1, x, y;
	
	scanf("%d", &n);
	memset(num, 0, sizeof(num));
	x = 0;
	y = n-1;
	num[x][y] = 1;
	while(cnt<n*n)
	{
		while(x+1<n && !num[x+1][y]) num[++x][y] = ++cnt;
		while(y>=1 && !num[x][y-1]) num[x][--y] = ++cnt;
		while(x>=1 && !num[x-1][y]) num[--x][y] = ++cnt;
		while(y+1<n && !num[x][y+1]) num[x][++y] = ++cnt;
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			printf("%3d ", num[i][j]);
		}
		printf("%3d\n", num[i][n-1]);
	}
	
	return 0;
}