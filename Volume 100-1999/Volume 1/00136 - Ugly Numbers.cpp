#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>

using namespace std;

template<typename T>
void PV(vector<T> &v)
{
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl;
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	
	// int nums[1500] = {1};
    
	// for(int i = 1; i < 1500; i++)
    // {
		// int val = 1e9;
		// for(int j = 0; j < i; j++)
        // {
			// if(nums[j]*2 > nums[i-1])
				// val = min(val, nums[j]*2);
			// if(nums[j]*3 > nums[i-1])
				// val = min(val, nums[j]*3);
			// if(nums[j]*5 > nums[i-1])
				// val = min(val, nums[j]*5);
		// }
		// nums[i] = val;
	// }
	
	// cout<<"The 1500'th ugly number is "<<nums[1499]<<"."<<endl;

    priority_queue<LL, vector<LL>, greater<LL> > pq;
    unordered_map<LL, bool> ugly;
    int factor[3] = {2, 3, 5};
    
    pq.push(1);
    ugly[1] = true;
    for(int i = 1; ; i++)
    {
        LL x1 = pq.top(); pq.pop();
        
        if(i == 1500)
        {
            cout<<"The 1500'th ugly number is "<<x1<<"."<<endl;
            break;
        }
        
        for(int j = 0; j < 3; j++)
        {
            LL x2 = x1 * factor[j];
            if(!ugly.count(x2))
            {
                ugly[x2] = true;
                pq.push(x2);
            }
        }
    }
    
    
#ifndef ONLINE_JUDGE
	fclose(stdin);
	// fclose(stdout);
#endif 
	
	return 0;
}
