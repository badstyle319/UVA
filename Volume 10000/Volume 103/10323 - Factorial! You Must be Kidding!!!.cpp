#include <bits/stdc++.h>

#define LL long long

using namespace std;

string strMultiply(string str, int n){
	int carry = 0;
	for(int i=str.length()-1;i>=0;i--){
		int temp = (str[i]-'0')*n+carry;
		str[i] = temp%10+'0';
		carry = temp/10;
	}
	while(carry){
		str.insert(0, 1, carry%10+'0');
		carry/=10;
	}
	return str;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	// clock_t begin = clock();
#endif
	
    // method 1
    // int n;
	// while(cin>>n)
    // {
		// string ans = "1";
		// if(n >= 0)
        // {
			// for(int i=2;i<=n;i++){
				// ans = strMultiply(ans, i);
				// if( (ans.length()==10 && ans.compare(string("6227020800"))>0) || ans.length()>10){
					// ans = "Overflow!";
					// break;
				// }
			// }
		// }
        // else
        // {
			// n = 0-n;
			// if(n%2)
				// ans = "Overflow!";
		// }
		// if(ans!="Overflow!"){
			// if(ans.length()<5)
				// ans = "Underflow!";
		// }
		// cout<<ans<<endl;
	// }
    
    // method 2
    LL arr[20] = {1, 1};
    int underflowLimit = 0, overflowLimit = 0;
    
    for(int i = 2; i < 20; i++)
    {
        arr[i] = arr[i - 1] * i;
        // cout << i << " " << arr[i] << endl;
        if(arr[i] < 10000)
            underflowLimit = i;
        else if(arr[i] <= (LL)6227020800)
            overflowLimit = i;
    }
    overflowLimit++;
    // cout << underflowLimit << " " << overflowLimit << endl;

    int n;
    
    while(cin >> n)
    {
        bool overflow = false;
        bool underflow = false;
        
        if(n >= 0)
        {
            if(n <= underflowLimit)
                underflow = true;
            else if(n >= overflowLimit)
                overflow = true;
        }
        else
        {
            if(abs(n) % 2)
                overflow = true;
            else
                underflow = true;
        }
        
        if(overflow)
            cout << "Overflow!";
        else if(underflow)
            cout << "Underflow!";
        else
            cout << arr[n];
        
        cout << endl;
    }
	
#ifndef ONLINE_JUDGE
	// clock_t end = clock();
	// double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	// printf("elapsed: %.3lf seconds\n", elapsed_secs);
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
