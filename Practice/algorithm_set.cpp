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

// static int dx[] = {-1,-1,-1,0,0,1,1,1};
// static int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
    
	clock_t begin = clock();
#endif

    int first[] = {5,10,15,20,25};
    int second[] = {50,40,30,20,10,0};
    string s1[] = {"a","abc","def"};
    string s2[] = {"xyz","aaa","abc","123"};
    
    //important
    sort(first, first+5);
    sort(second, second+6);
    sort(s1, s1+3);
    sort(s2, s2+4);
    
    cout<<"=====set_union test====="<<endl;
    VI v1(11);
    VI::iterator it;
    it = set_union(first, first+5, second, second+6, v1.begin());
    cout<<"v1: ";
    // PV(v1);
    v1.resize(it-v1.begin());
    PV(v1);
    
    VI v2;
    set_union(first, first+5, second, second+6, inserter(v2, v2.begin()));
    cout<<"v2: ";
    PV(v2);
    
    cout<<"union of first and second: ";
    set_union(first, first+5, second, second+6, ostream_iterator<int>(cout, " "));
    cout<<endl;
    
    cout<<"union of s1 and s2: ";
    set_union(s1, s1+3, s2, s2+4, ostream_iterator<string>(cout, " "));
    cout<<endl;

    cout<<"=====set_intersection test====="<<endl;
    cout<<"intersection of first and second: ";
    set_intersection(first, first+5, second, second+6, ostream_iterator<int>(cout, " "));
    cout<<endl;
    
    cout<<"intersection of s1 and s2: ";
    set_intersection(s1, s1+3, s2, s2+4, ostream_iterator<string>(cout, " "));
    cout<<endl;
	
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	double elapsed_secs = double(end-begin) / CLOCKS_PER_SEC;
    
    cout<<fixed<<setprecision(3)<<"elapsed: "<<elapsed_secs<<" sec."<<endl;
    
	fclose(stdin);
	// fclose(stdout);
#endif 

	return 0;
}
