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
        4: �S��3�i�f4({1,4} {2,4}) + ��3���i�f4({1,3})
        5: �S��4�i�f5({1,3,5},{2,5}) + ��4���i�f5({1,4},{2,4})
        6: �S��5�i�f6({1,4,6},{2,4,6},{1,3,6}) + ��5���i�f6({1,3,5},{2,4,5})
        7: �S��6�i�f7({1,3,5,7},{2,5,7},{1,4,7},{2,4,7}) + ��6���i�f7({1,4,6},{2,4,6},{1,3,6})
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
