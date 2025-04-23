#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;


void scan(vector<int> &arr, int head, int dirr, int max_val)
{
    vector<int> left;
    vector<int> right;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<head) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }

    if(dirr == 0) left.push_back(0);
    else right.push_back(max_val-1);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    

    int seekTime = 0;

    if(dirr == 1)
    {
        for(int i=0;i<right.size();i++)
        {
            int dist = abs(right[i]-head);
            seekTime+=dist;
            head=right[i];
        }

        for(int i=0;i<left.size();i++)
        {
            int dist = abs(left[i]-head);
            seekTime+=dist;
            head=left[i];
        }
    }

    else
    {
        for(int i=0;i<left.size();i++)
        {
            int dist = abs(left[i]-head);
            seekTime+=dist;
            head=left[i];
        }
        for(int i=0;i<right.size();i++)
        {
            int dist = abs(right[i]-head);
            seekTime+=dist;
            head=right[i];
        }

    }

    cout<<"SeekTime: "<<seekTime<<endl;
}

int main()
{
    int n;
    cout<<"Entre the no of sequence: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Entre the sequence in disk: ";
    for(int i=0;i<n;i++)
    {
        cin>> arr[i];
    }

    int head;
    cout<<"Entre the initial value of read/write head: ";
    cin>>head;
    
    int max_val;
    cout<<"Entre the max avlue of the disk: ";
    cin>>max_val;

    int dirr;
    cout<<"Entre the direction : ";
    cin>>dirr;

    scan(arr, head, dirr, max_val);
    return 0;
}