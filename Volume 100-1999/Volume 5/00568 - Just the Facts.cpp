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

	int arr[10001] = {1, 1};
    int tail = 1; //非2或5尾數
    int n2 = 0, n5 = 0; //2或5個數
    
    for(int i = 2; i < 10001; i++)
    {
        // arr[i] = arr[i - 1] * i;
        // cout << i << "! = " << arr[i] << endl;
        
        int temp = i;
        while(temp % 2 == 0)
        {
            temp /= 2;
            n2++;
        }
        while(temp % 5 == 0)
        {
            temp /= 5;
            n5++;
        }
        // cout << "i=" << i << " temp=" << temp << " n2=" << n2 << " n5=" << n5 << endl;
        int nPair = min(n2, n5);
        n2 -= nPair;
        n5 -= nPair;

        tail *= temp;
        tail %= 10;
        
        // cout << i << " tail=" << tail << " n2=" << n2 << " n5=" << n5 << endl;
        static int o[] = {2, 4, 8, 6};
        arr[i] = tail * (n2?o[(n2-1)%4]:1);
        arr[i] %= 10;
        // cout << arr[i] << endl;
    }
    
    int n;
    while(cin >> n)
    {
        cout.width(5);
        cout << n << " -> " << arr[n] << endl;
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
