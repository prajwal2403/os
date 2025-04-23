#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Scheduling{
    public:
    int id;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;

    //user input
    void input(int id, int at, int bt)
    {
        this->id = id;
        this->at = at;
        this->bt = bt;
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

   vector<Scheduling> P(n);
//take the details of each and every vector
    for(int i=0;i<n;i++)
    {
        int at, bt;
        cout<<"Entre the Arrival Time and Burst Time of Process P"<<i<<":";
        cin>>at>>bt;
        P[i].input(i, at, bt);
    }

    sort(P.begin(), P.end(), [](Scheduling A, Scheduling B){
        return A.at<B.at;

    });


    vector<Scheduling> readyQ;
    vector<Scheduling> completed;
    int currentTime=0;
    int avgWT=0;
    int avgTAT=0;

    while(completed.size()<n)
    {
      
        for(auto& p: P)
        {
            bool inReady=false;
            bool isCompleted = false;
            for(auto& process:readyQ)
            {
                if(process.id == p.id)
                {
                    inReady=true;
                    break;
                }
            }

            for(auto& process: completed)
            {
                if(process.id == p.id)
                {
                    isCompleted = true;
                    break;
                }
            }

            if(p.at<=currentTime && !inReady && !isCompleted)
            {
                readyQ.push_back(p);
            }

        }

        if (readyQ.empty()) {
            currentTime++;
            continue;
        }


        //sortinng on the basis of the burst time
        sort(readyQ.begin(), readyQ.end(), [](Scheduling P1, Scheduling P2){return P1.bt<P2.bt;});

        Scheduling P1 = readyQ.front();

        readyQ.erase(readyQ.begin());

        P1.ct = currentTime + P1.bt;
        P1.tat = P1.ct - P1.at;
        P1.wt = P1.tat - P1.bt;
        currentTime = P1.ct;
        avgWT +=  P1.wt;
        avgTAT += P1.tat;
        
        completed.push_back(P1);

    }
    cout<<"id               At              BT              Ct              TAT             Wt"<<endl;
    for(int i=0; i<n;i++)
    {
        completed[i].display();
    }

    cout<<"Avg waiting Time: "<<avgWT/3<<endl;
    cout<<"Avg TurnAround Time: "<<avgTAT/3<<endl;
    return 0;
}