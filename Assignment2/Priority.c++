#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Priority{
    public:
    int id;
    int at; 
    int bt; 
    int wt; 
    int ct;
    int tat;
    int Priority;

    void insert(int id, int at, int bt, int P)
    {
        this->id = id;
        this->at =at;
        this->bt = bt;
        this->Priority =P;
        this->wt =0 ;
        this->ct =0;
        this->tat=0;
    }
};

int main()
{
    int n;
    cout<<"Entre the no of Process: ";
    cin>>n;
    cout<<"Entre the process details: ";
    cout<<endl;
    vector<Priority> P;
    for(int i=0;i<n;i++)
    {
        int at, bt, p;
        cout <<"Entre the at, bt and for Process P : "<<i+1<<" ";
        cin>>at>>bt>>p;

    }

    vector<Priority> readyQ;
    vector<Priority> completed;
    int currentTime = 0;


    while(completed.size()<n)
    {
        for (auto& p : P) {
            bool inReady = false, isCompleted = false;
        
            for (auto& process : readyQ) {
                if (process.id == p.id) {
                    inReady = true;
                    break;
                }
            }
        
            for (auto& process : completed) {
                if (process.id == p.id) {
                    isCompleted = true;
                    break;
                }
            }
        
            if (p.at <= currentTime && !inReady && !isCompleted) {
                readyQ.push_back(p);
            }
        }
        
        if (readyQ.empty()) {
            currentTime++;
            continue;
        }

        sort(readyQ.begin(), readyQ.end(), [](Priority P, Priority Q){return P.Priority < Q.Priority;});
        Priority highest_priority_job = readyQ.front(); 
        readyQ.erase(readyQ.begin()); 
 
        // Execute process 
        highest_priority_job.ct = currentTime + highest_priority_job.bt; 
        highest_priority_job.tat = highest_priority_job.ct - highest_priority_job.at; 
        highest_priority_job.wt = highest_priority_job.tat - highest_priority_job.bt; 
        currentTime = highest_priority_job.ct; 
 
        // Add to completed processes 
        completed.push_back(highest_priority_job);
 
    }
}