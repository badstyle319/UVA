#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	// clock_t begin = clock();
#endif

    int n;
    while(cin >> n)
    {
        vector<int> v{0, 1, 2, 2};
        
        /***
        1: {1}
        2: {1} {2}
        3: {1,3} {2}
        4: 沒有3可搭4({1,4} {2,4}) + 有3不可搭4({1,3})
        5: 沒有4可搭5({1,3,5},{2,5}) + 有4不可搭5({1,4},{2,4})
        6: 沒有5可搭6({1,4,6},{2,4,6},{1,3,6}) + 有5不可搭6({1,3,5},{2,4,5})
        7: 沒有6可搭7({1,3,5,7},{2,5,7},{1,4,7},{2,4,7}) + 有6不可搭7({1,4,6},{2,4,6},{1,3,6})
        ***/
        for(int i = 4; i <= n; i++)
            v.push_back(v[i-2] + v[i-3]);
        
        cout << v[n] << endl;
    }
	
	
#ifndef ONLINE_JUDGE
	// clock_t end = clock();
	// double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    // cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
