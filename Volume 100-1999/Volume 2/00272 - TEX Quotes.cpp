#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int flag = 1;
	string temp;
	
	while(getline(cin, temp))
	{
		for(int i = 0; i < temp.size(); i++)
		{
			if(temp[i] == '"')
			{
				if(flag)
					cout<<"``";
				else
					cout<<"''";
				flag = !flag;
			}
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
