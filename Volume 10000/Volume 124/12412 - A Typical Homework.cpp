#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define VI vector<int>
#define VS vector<string>

using namespace std;

template<typename T>
void PV(vector<T> &v)
{
    cout<<v.size()<<":";
    for(auto it:v)
        cout<<it<<" ";
    cout<<endl;
};

// static int dx[] = {-1,-1,-1,0,0,1,1,1};
// static int dy[] = {-1,0,1,-1,1,-1,0,1};

typedef struct
{
    int cid;
    string name;
    int scores[5]; //chinese, mathematics, english, programming
}Student;

map<string, Student> mpSID; //SID map to Student

int findRank(string sid)
{
    Student *s = &mpSID[sid];
    int rv = 1;
    
    for(auto kv:mpSID)
    {
        if(kv.first != sid && s->scores[4] < kv.second.scores[4])
            rv++;
    }
    return rv;
}

void query(string input)
{
    Student *s = &mpSID[input];
    double avg = s->scores[4] / 4.0 + 1e-5;

    cout<< findRank(input) <<" ";
    cout<< input <<" "<< s->cid <<" "<< s->name <<" ";
    for(int i = 0; i < 4; i++)
        cout<< s->scores[i] <<" ";
    cout<< s->scores[4] <<" ";
    cout<<fixed<<setprecision(2)<< avg <<endl;
}

void statistics(int cid)
{
    int sum[4] = {}, pass[4] = {}, passTotal[5] = {};
    int studentCounter = 0;
    
    for(auto kv:mpSID)
    {
        if((cid && kv.second.cid == cid) || !cid)
        {
            int passCnt = 0;
            for(int i = 0; i < 4; i++)
            {
                int score = kv.second.scores[i];
                sum[i] += score;
                if(score >= 60)
                {
                    pass[i]++;
                    passCnt++;
                }
            }
            passTotal[passCnt]++;
            studentCounter++;
        }
    }
    
    string subjects[] = {"Chinese", "Mathematics", "English", "Programming"};
    for(int i = 0; i < 4; i++)
    {
        double avg = 0;
        if(studentCounter)
            avg = sum[i] * 1.0 / studentCounter + 1e-5;
        cout<< subjects[i] <<endl;
        cout<<"Average Score: "<<fixed<<setprecision(2)<< avg <<endl;
        cout<<"Number of passed students: "<< pass[i] <<endl;
        cout<<"Number of failed students: "<< (studentCounter - pass[i]) <<endl<<endl;
    }
    
    string strPass[] = {"failed all subjects", "passed 1 or more subjects", "passed 2 or more subjects", "passed 3 or more subjects", "passed all subjects"};
    cout<<"Overall:"<<endl;
    for(int i = 4; i >= 0; i--)
    {
        int total = passTotal[i];
        for(int j = i + 1; i && (j < 5); j++)
            total += passTotal[j];
        cout<<"Number of students who "<<strPass[i];
        cout<<": "<<total<<endl;
    }
    cout<<endl;
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

    //TODO: figure out why WA
    int op;
    string sid, input;
    int removeCounter;
    
    while(1)
    {
        cout<<"Welcome to Student Performance Management System (SPMS)."<<endl<<endl;
        cout<<"1 - Add"<<endl;
        cout<<"2 - Remove"<<endl;
        cout<<"3 - Query"<<endl;
        cout<<"4 - Show ranking"<<endl;
        cout<<"5 - Show Statistics"<<endl;
        cout<<"0 - Exit"<<endl<<endl;
        
        cin>>op;
        if(!op)
            break;
        
        switch(op)
        {
            case 1: //Add
                do
                {
                    cout<<"Please enter the SID, CID, name and four scores. Enter 0 to finish."<<endl;
                    
                    cin>>sid;
                    if(sid == "0")
                        break;
                    
                    Student s = {};
                    
                    cin>>s.cid>>s.name;
                    for(int i = 0; i < 4; i++)
                    {
                        cin>>s.scores[i];
                        s.scores[4] += s.scores[i];
                    }
                    
                    if(mpSID.count(sid)>0)
                        cout<<"Duplicated SID."<<endl;
                    else
                    {
                        mpSID[sid] = s;
                    }
                }while(1);

                break;
            case 2: //Remove
                do
                {
                    cout<<"Please enter SID or name. Enter 0 to finish."<<endl;
                    
                    cin>>input;
                    
                    if(input == "0")
                        break;
                    
                    removeCounter = 0;
                    if(mpSID.count(input) > 0)
                    {
                        mpSID.erase(input);
                        removeCounter++;
                    }
                    else
                    {
                        for(auto it = mpSID.begin(); it != mpSID.end();)
                        {
                            if(it->second.name == input)
                            {
                                it = mpSID.erase(it);
                                removeCounter++;
                            }
                            else
                                it++;
                        }
                    }
                    cout<<removeCounter<<" student(s) removed."<<endl;
                }while(1);
                break;
            case 3: //Query
                do
                {
                    cout<<"Please enter SID or name. Enter 0 to finish."<<endl;
                    
                    cin>>input;
                    
                    if(input == "0")
                        break;
                    
                    if(mpSID.count(input))
                        query(input);
                    else
                    {
                        for(auto kv:mpSID)
                        {
                            if(kv.second.name == input)
                                query(kv.first);
                        }
                    }
                }while(1);
                break;
            case 4: 
                cout<<"Showing the ranklist hurts students' self-esteem. Don't do that."<<endl;
                break;
            case 5:
                cout<<"Please enter class ID, 0 for the whole statistics."<<endl;
                {
                    int cid;
                    cin>>cid;
                    statistics(cid);
                }
                break;
        }
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
