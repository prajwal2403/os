#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;


void sstf(vector<int> &arr, int head)
{
    vector<bool> visited(arr.size(), false);
    int seekTime=0;
    int completed =0;
    cout<<"The safe sequence is: ";
    while(completed<arr.size())
    {
        int min_dist = INT_MAX;
        int index = -1;

        for(int i=0;i<arr.size();i++)
        {
            if(!visited[i])
            {
                int dist = abs(arr[i]-head);
                if(dist<min_dist)
                {
                    min_dist=dist;
                    index=i;
                }
            }
        }

        seekTime+=min_dist;
        visited[index]=true;
        completed++;
        cout<<seekTime<<endl;
        head=arr[index];



    }
    cout<<"The seek time using the sst algorithm is: "<<seekTime<<endl;
}
int main()
{
    int n;
    cout<<"Entre the no of the disk request: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Entre the disk Sequence: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int head;
    cout<<"Entre the value of initial value of read/write head: ";
    cin>>head;

    int max_size;
    cout<<"Entre the max size of the culindricla disk: ";
    cin>>max_size;




    sstf(arr, head);




    return 0;

}
