#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


class Round{
    public:
    int id;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int rb;

    //user input
    void input(int id, int at, int bt)
    {
        this->id = id;
        this->at = at;
        this->bt = bt;
        this->rb = bt;
        this->ct = 0;
        this->wt = 0;
        this->tat = 0;

    }


    //diplay table
    void display()
    {
    cout<<"P"<<this->id<<"          "<<this->at<<"           "<<this->bt<<"             "<<this->ct<<"              "<<this->wt<<"              "<<this->tat<<endl;

    }
};

int main()
{
    int n;
    cout<<"Entre the no of Processess: ";
    cin>>n;
 
    vector<Round> Process(n);
 //take the details of each and every vector
     for(int i=0;i<n;i++)
     {
         int at, bt;
         cout<<"Entre the Arrival Time and Burst Time of Process P"<<i<<":";
         cin>>at>>bt;
         Process[i].input(i, at, bt);
     }
 
     sort(Process.begin(), Process.end(), [](Round A, Round B){
         return A.at<B.at;
 
     });

     int TimeQuantum= 2;

     queue<int> readyQ;
     vector<bool> inq(n, false);

     int complete  =0;
     int currentTime = 0;

     while(complete< n)
     {
        for(int i=0;i<n;i++)
        {
            if(Process[i].at <= currentTime && Process[i].rb > TimeQuantum && !inq[i])
            {
                readyQ.push(i);
                inq[i] = true;
            }
        }

        if(!readyQ.empty())
        {
            int idx = readyQ.front();
            readyQ.pop();

            currentTime = min(Process[idx].bt, TimeQuantum);
            

        }
     }





}