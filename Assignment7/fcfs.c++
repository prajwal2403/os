#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

int fcfs(vector<int> &pages, int capacity)
{
    unordered_set<int> s;
    queue<int> index;
    int pageFault=0;
    for(int i=0;i<pages.size();i++)
    {
        if(s.size()<capacity)
        {
            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                index.push(pages[i]);
                pageFault++;

            }
        }
        else
        {
            if(s.find(pages[i])==s.end())
            {
                int var = index.front();
                s.erase(s.find(var));
                index.pop();
                s.insert(pages[i]);
                index.push(pages[i]);
                pageFault++;
            }
        }
    }
    return pageFault;;
}

int main()
{
    int n;
    cout<<"Entre the no of pages of the frame: ";
    cin>> n;
    int capacity;
    cout<<"Entre the capacity of the Main Memory in terms of the Frames: ";
    cin>>capacity;

    vector<int> pages(n);
    cout<<"Entre the page sequence: ";
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }

    int pageFault=fcfs(pages, capacity);
    int hit = n-pageFault;
    cout<<"PageFault: "<<pageFault<<endl;

    cout<<"PageHits: "<<hit<<endl;





    return 0;
}