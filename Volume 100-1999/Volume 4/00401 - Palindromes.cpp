#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	string str;
	const char* result[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
	map<char, char> mir;
	
	mir['A'] = 'A';
	mir['E'] = '3';
	mir['H'] = 'H';
	mir['I'] = 'I';
	mir['J'] = 'L';
	mir['L'] = 'J';
	mir['M'] = 'M';
	mir['O'] = 'O';
	mir['S'] = '2';
	mir['T'] = 'T';
	mir['U'] = 'U';
	mir['V'] = 'V';
	mir['W'] = 'W';
	mir['X'] = 'X';
	mir['Y'] = 'Y';
	mir['Z'] = '5';
	mir['1'] = '1';
	mir['2'] = 'S';
	mir['3'] = 'E';
	mir['5'] = 'Z';
	mir['8'] = '8';
	
	while(getline(cin, str))
	{
		int i, j;
		int isPal = 1, isMir = 1;
		int len = (int)str.size();
		
		for(i=0, j = len-1; i <= j; i++, j--)
		{
			if(str[i] != str[j])
				isPal = 0;
			if( (mir.count(str[i]) && mir[str[i]] != str[j])
				|| !mir.count(str[i]))
					isMir = 0;
		}
		
		cout<<str<<" -- is ";
		cout<<result[isMir*2+isPal];
		cout<<"."<<endl<<endl;
	}
	
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif 
	
	return 0;
}
