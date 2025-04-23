#include<iostream>
#include<vector>
using namespace std;

void worstfit(vector<int> block, vector<int> Process)
{
    vector<int> temp = block;
    for(int i=0;i<Process.size();i++)
    {
        int worst=-1;
        for(int j=0;j<temp.size();j++)
        {
            if(Process[i]<=temp[j])
            {
                if(worst==-1 || temp[j]>temp[worst])
                {
                    worst = j;
                }
            }
        }

        if(worst != -1)
        {
            cout<<"Process: "<<i+1<<" Block: "<<worst+1<<" (Memory: "<<temp[worst]<<" Remainning: "<<temp[worst]-Process[i]<<endl;
            temp[worst]-=Process[i];

        }
        else
        {
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

    worstfit(block, Process);
    return 0;
}