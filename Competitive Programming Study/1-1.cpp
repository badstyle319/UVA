#include <stdio.h>

#define NUM_LEN 3

int main()
{
	int nums[NUM_LEN];
	double avg = 0;
	
	for(int i = 0; i < NUM_LEN; i++)
	{
		scanf("%d", &nums[i]);
		avg += nums[i];
	}
	printf("%.3lf\n", avg/3.0);
	
	return 0;
}