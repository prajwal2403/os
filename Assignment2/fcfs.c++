#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class FCFS{
    public:
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    void input(int id, int at, int bt){
        this->id = id;
        this->at = at;
        this->bt = bt;
        this->ct = 0;
        this->tat = 0;
        this->wt = 0;
    }


    void display()
    {
    
        cout<<"P"<<this->id<<"          "<<this->at<<"         "<<this->bt<<"          "<<this->ct<<"          "<<this->tat<<"           "<<this->wt<<endl;
    }


};
int main()
 {
    int procc;
    cout<<"Entre the no of processes: ";
    cin>>procc;
    

    vector<FCFS> P(procc);
    for(int i=0;i<procc;i++)
    {
        int at,bt;
        cout<<"Entre the Arrival Time and completion time for Process P"<<i<<" :";
        cin>>at>>bt;
        int id = i;
        P[i].input(id, at, bt);

    }

    // sorting basedd on the arrival time


    sort(P.begin(), P.end(),[](FCFS P1, FCFS P2){return P1.at < P2.at;});

    // for Process P0 all thiings are done manually

    P[0].ct = P[0].at + P[0].bt;
    P[0].wt = 0;
    P[0].tat = P[0].ct - P[0].at;


    for(int i=1; i< procc; i++)
    {
        if(P[i].at < P[i-1].ct)
        {
            P[i].ct = P[i-1].ct + P[i].bt;
            P[i].wt = P[i-1].ct - P[i].at;
            P[i].tat =  P[i].ct - P[i].at;


        }

        else
        {
            P[i].ct = P[i].at+P[i].bt;
            P[i].wt = 0;
            P[i].tat = P[i].ct - P[i].at;;

        }
    }





    cout<<"id          at         bt          ct          tat           wt"<<endl;
    for(int i=0; i<procc; i++)
    {
        P[i].display();
    }




    cout<<"Hello World";
    return 0;
 }
