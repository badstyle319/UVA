#include <stdio.h>
#include <string.h>
#include <bitset>
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
	for(int i=987; i>=987/3; i--)
	{
		if(i%3==0)
		{
			//method 1
			{	
				bitset<10> bs;
				int nums[3] = {i/3, i/3*2, i};
				
				for(int j = 0; j < 3; j++)
				{
					bs.set(nums[j]/100%10);
					bs.set(nums[j]/10%10);
					bs.set(nums[j]%10);
				}
				
				if(bs.flip() == 1)
				{
					printf("%d %d %d\n", nums[0], nums[1], nums[2]);
				}
			}
			
			//method 2
			// {
				// int num[3];
				// int flag[10];
				// int illegal = 0;
				
				// num[0] = i/3;
				// num[1] = num[0]*2;
				// num[2] = i;
				
				// memset(flag, 0, sizeof(flag));
				// for(int j=0; j<3; j++)
				// {
					// flag[num[j]/100%10] = 1;
					// flag[num[j]/10%10] = 1;
					// flag[num[j]%10] = 1;
				// }
				
				// for(int j=1; j<10; j++)
				// {
					// if(flag[j]==0)
					// {
						// illegal = 1;
						// break;
					// }
				// }
				
				// if(!illegal)
					// printf("%d %d %d\n", num[0], num[1], num[2]);
			// }
		}
	}
	
	return 0;
}