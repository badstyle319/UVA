#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>

#define LL long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	string input;
	int n;
	int negFlag = 0;
	while(cin>>input>>n){
		vector<int> nums;
		stack<char> operators;
		stack<int> operands;
		for(int i=0;i<input.length();i++){
			if(isdigit(input[i])){
				int len=0;
				while(isdigit(input[i+len]))
					len++;
				if(negFlag){
					negFlag = 0;
					operands.push(-1*atoi(input.substr(i, len).c_str()));	
				}else{
					operands.push(atoi(input.substr(i, len).c_str()));
				}
				i+=len-1;
			}else{
				if(input[i]==']'){
					int num = operands.top();
					operands.pop();
					if(nums.size()==0){
						//pop up '['
						operators.pop();
						for(int j=0;j<n;j++)
							nums.push_back(num);
					}else{
						char op = operators.top();
						operators.pop();
						//pop up '['
						operators.pop();
						if(op=='+'){
							nums.insert(nums.begin(), num);
							nums.erase(nums.end()-1);
							for(int j=1;j<n;j++)
								nums[j]+=nums[j-1];
						}else{
							nums[0]*=num;
							for(int j=1;j<n;j++){
								nums[j] *= nums[j-1];
							}
						}
					}
					// for(int i=0;i<n;i++){
						// if(i)
							// cout<<' ';
						// cout<<nums[i];
					// }
					// cout<<endl;
				}else if(input[i]=='-')
					negFlag = 1;
				else
					operators.push(input[i]);
			}
		}
		for(int i=0;i<n;i++){
			if(i)
				cout<<' ';
			cout<<nums[i];
		}
		cout<<endl;
	}
	
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
