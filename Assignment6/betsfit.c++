#include<iostream>
#include<vector>

using namespace std;

void bestfit(vector<int> blocks, vector<int> Process)
{
    vector<int> temp = blocks; 
    
    for(int i=0;i<Process.size();i++)
    {
        int a =-1;
        for(int j=0;j<temp.size();j++)
        {
            if(temp[j]>=Process[i])
            {
                if( a==-1 || temp[j]<temp[a])
                {
                    a=j;
                }
            }
        }

        if(a!=-1)
        {
            cout<<"Process: "<<i+1<<" Assigned to Memory Block: "<<a+1<<" size: "<<temp[a]<<"Remaining size: "<<temp[a]-Process[i]<<endl;
            temp[a]-=Process[i];
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
    cout<<"Entre the no of Process: ";
    cin>>n;

    vector<int> blocks(n);
    cout<<"Entre the address of the memory block: ";
    for(int i=0;i<n;i++)
    {
        cin>>blocks[i];
    }

    int a;
    cout<<"Entre the no of Procees: ";
    cin>>a;
    vector<int> Process(a);

    cout<<"Entre  the size of the Process block: ";
    for(int i=0;i<a;i++)
    {
        cin>>Process[i];
    }

    bestfit(blocks, Process);

    return 0;
}