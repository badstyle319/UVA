#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef struct data{
	float val;
	float len;
	// data(float v, float l){
		// val = v;
		// len = l;
	// }
}data;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int lines;
	while(cin>>lines){
		vector<data> f, g;
		float result = 1e9;
		
		for(int i=0;i<lines;i++){
			data d;
			cin>>d.val>>d.len;
			if(i)
				d.len+=f[i-1].len;
			f.push_back(d);
		}

		cin>>lines;
		for(int i=0;i<lines;i++){
			data d;
			cin>>d.val>>d.len;
			if(i)
				d.len+=g[i-1].len;
			g.push_back(d);
		}

		int i=0, j=0;
		for(;i<f.size() && j<g.size();){
			result = min(result, max(f[i].val, g[j].val));
			if(f[i].len<g[j].len)
				i++;
			else if(f[i].len>g[j].len)
				j++;
			else{
				i++;
				j++;
			}
		}
		
		while(i<f.size())
			result = min(result, max(f[i++].val, g[j-1].val));
		
		while(j<g.size())
			result = min(result, max(f[i-1].val, g[j++].val));
		
		cout.setf(ios::fixed);
		cout.precision(3);
		cout<<result<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
