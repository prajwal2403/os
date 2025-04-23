#include<iostream>
#include<vector>
using namespace std;

void next(vector<int> block, vector<int> Process)
{
    vector<int> Temp = block;
    int last =0 ;
    for(int i=0;i<Process.size();i++)
    {
        int count = 0;
        int j = last;
        bool allocated = false;

        while(count< Temp.size())
        {
            if(Process[i]<=Temp[j])
            {
                cout<<"Process: "<<i+1<<" Block: "<<j+1<<" (Memory: "<<Temp[j]<<" Remainning: "<<Temp[j]-Process[i]<<endl;
                Temp[j]-=Process[i];
                last = j;
                allocated = true;
                break;
            }
            j = (j+1)%Temp.size();
            count++;
        }


        if (!allocated) { 
            cout << "Process " << i + 1 << " not allocated\n"; 
        }

    }
}


int main()
{
    int n;
    cout<<"Entre the no of Memory Blocks: ";
    cin>>n;

    vector<int> block(n);
    for(int i=0;i<n;i++)
    {
        cin>>block[i];
    }
    int a;
    cout<<"Entre the no process Block: ";
    cin>>a;
    vector<int> Process(a);
    for(int i=0;i<a;i++)
    {
        cin>>Process[i];
    }

    next(block, Process);
    return 0;
}