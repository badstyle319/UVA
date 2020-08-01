#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	string str = "`1234567890-=" \
		"QWERTYUIOP[]\\" \
		"ASDFGHJKL;'" \
		"ZXCVBNM,./";
	
	string temp;
	while(getline(cin, temp))
	{
		for(int i = 0; i < (int)temp.length(); i++)
		{
			int idx;
			
			for(idx = 1; str[idx] && str[idx] != temp[i]; idx++);
			if(str[idx])
				cout<<str[idx-1];
			else
				cout<<temp[i];
		}
		cout<<endl;
	}
	
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif 
	
	return 0;
}
