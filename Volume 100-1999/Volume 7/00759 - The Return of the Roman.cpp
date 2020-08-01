#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

#define LL long long

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	map<string,int> dic;
	dic["I"] = 1;
	dic["V"] = 5;
	dic["X"] = 10;
	dic["L"] = 50;
	dic["C"] = 100;
	dic["D"] = 500;
	dic["M"] = 1000;
	dic["IV"] = 4;
	dic["IX"] = 9;
	dic["XL"] = 40;
	dic["XC"] = 90;
	dic["CD"] = 400;
	dic["CM"] = 900;
	int val[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string sign[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	string input;
	while(getline(cin, input)){
		// input = input.erase(0, input.find_first_not_of(" "));
		// input = input.erase(input.find_last_not_of(" ")+1);
		if(input.empty()){
			cout<<0<<endl;
			continue;
		}

		int sum=0;
		for(int i=0;i<input.length();i++){
			string temp(input.substr(i, 2));
			if(dic.count(temp)>0){
				sum+=dic[temp];
				i+=temp.length()-1;
			}else{
				temp = input.substr(i, 1);
				if(dic.count(temp)>0)
					sum+=dic[temp];
			}
		}
		int answer = sum;
		string output;
		for(int i=12;i>=0;i--){
			int cnt=sum/val[i];
			if(cnt>3)
				continue;
			while(cnt--){
				output+=sign[i];
				sum-=val[i];
			}
		}
		if(!input.compare(output))
			cout<<answer<<endl;
		else
			cout<<"This is not a valid number"<<endl;
	}
	
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif 
	
	return 0;
}
