#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;


void fcfs(vector<int> &arr, int head)
{
    int seekTime=0;
    for(int i=0;i<arr.size();i++)
    {
        seekTime+=abs(arr[i]-head);
        head=arr[i];
    }

    cout<<"The seek Time is: "<<seekTime<<endl;
}

void sstf(vector<int> &arr, int head)
{
    vector<bool> visited(arr.size(), false);
    int completed = 0;
    int seekTime=0;
    while(completed < arr.size())
    {
        int min_dist=INT_MAX;
        int index = -1;

        for(int i=0;i<arr.size();i++)
        {
            if(!visited[i])
            {
                int dist = abs(arr[i]-head);
                if(dist < min_dist)
                {
                    min_dist = dist;
                    index=i;
                }
            }
        }

        seekTime += min_dist;
        visited[index] = true;
        head =  arr[index];
        completed++;




    }

    cout<<"The Shortest seek time first result is: "<<seekTime<<endl;

}

int main()
{
    int n;
    cout<<"Enter the no of request: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Entre the requests: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];


    }

    int head;
    cout<<"Entre the head Position: ";
    cin>>head;

    sstf(arr, head);



    return 0;
}