#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>

#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	
	string s, t;
	while(cin>>s>>t)
    {
		if(s == t)
        {
			cout<<"Yes"<<endl;
			continue;
		}
		
		if(s.size() > t.size())
        {
			cout<<"No"<<endl;
			continue;
		}
		
		int legal = 0, len = s.size();
		for(int i = 0, j = 0; i < len, j < t.size(); )
        {
			if(s[i] == t[j])
            {
				if(i == len-1)
                {
					legal = 1;
					break;
				}
				i++;
			}
			j++;
		}
		if(legal)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
	// fclose(stdout);
#endif 
	
	return 0;
}
