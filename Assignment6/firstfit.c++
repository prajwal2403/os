#include<iostream>
#include<vector>
using namespace std;


void firstfit(vector<int> &blocks, vector<int> &Process)
{
    vector<int> temp=blocks;

    for(int i=0;i<Process.size();i++)
    {
        bool allocated = false;
        for(int j=0;i<temp.size();j++)
        {
            if(temp[i]>=Process[j])
            {
                cout<< "Process " << i + 1 << " allocated in block " << j + 1 << " (Size: " << 
                blocks[j] << ", Remaining: " << blocks[j] - Process[i] << ")\n"; 
                blocks[j] -= Process[i]; 
                allocated = true; 
                break; 
            }
        }
        if (!allocated) { 
            cout << "Process " << i + 1 << " not allocated\n"; 
        }
    }
}
int main()
{
    int p;
    cout<<"Entre the nummmber of Process Blocks: ";
    cin>>p;

    vector<int> blocks(p);
    cout<<"Entre the size of each process block: ";
    for(int i=0;i<p;i++)
    {
        cin>>blocks[i];
    }

    int n;
    cout<<"Entre the no of process: ";
    cin>>n;

    vector<int> Process(n);

    for(int i=0;i<n;i++)
    {
        cin>>Process[i];
    }

    firstfit(blocks, Process);

    return 0;
}