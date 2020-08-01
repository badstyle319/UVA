#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long

using namespace std;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	clock_t begin = clock();
#endif

	int N, case_no = 1;
    
	while(scanf("%d", &N)==1 && N)
	{
        int target[1005];
        int nums[1005];
        map<int, int> mpTarget, mpNums;
        
		for(int i = 0; i < N; i++)
        {
			scanf("%d", &target[i]);
            mpTarget[target[i]] += 1;
        }
        
        printf("Game %d:\n", case_no++);
		do
		{
			bool bEnd = true;
            int A = 0, B = 0;
            
            mpNums.clear();
			for(int i = 0; i < N; i++)
			{
				scanf("%d", &nums[i]);
                if(nums[i] == target[i])
                    A++;
                mpNums[nums[i]] += 1;
                
				if(nums[i])
					bEnd = false;
			}
			if(bEnd)
                break;
            
            for(int i = 1; i <= 9; i++)
                B += min(mpTarget[i], mpNums[i]);
            B -= A;
            
            printf("%*c(%d,%d)\n", 4, ' ', A, B);
		}while(1);
	}
	
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin)/CLOCKS_PER_SEC;
	printf("elapsed: %.3lf seconds\n", elapsed_secs);
	fclose(stdin);
	fclose(stdout);
#endif 

	return 0;
}
