#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define PI 3.14159265

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int solve(string s1, string s2)
{
	int flag[101], ans = 1;
	memset(flag, -1, sizeof(flag));
	for(int i=0; i<s1.length(); i++)
	{
		for(int j=0; j<s2.length(); j++)
		{
			if(s1[i]==s2[j] && flag[j]==-1)
			{
				flag[j] = i;
				break;
			}
		}
	}
	for(int i=0; i<s2.length()-1; i++)
		if(flag[i]!=-1 && flag[i+1]!=-1 && (flag[i]-flag[i+1])<0)
			ans++;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	clock_t begin = clock();
#endif
	
	string s1, s2;
	int caseNo = 1;
	do{
		getline(cin, s1);
		if(s1[0]=='#')
			break;
		getline(cin, s2);
		cout<<"Case #"<<caseNo<<": you can visit at most "<<max(solve(s1, s2),solve(s2, s1))<<" cities."<<endl;
		caseNo++;
	}while(1);
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	cout<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
