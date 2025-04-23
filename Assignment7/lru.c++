#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<climits>


using namespace std;

int lru(vector<int> &pages, int capacity)
{
    unordered_set<int> s;
    unordered_map<int,int> index;
    int pageFault =0;
    for(int i=0;i<pages.size();i++)
    {
        if(s.size()<capacity)
        {
            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                pageFault++;
             

            }
            index[pages[i]]=i;
        }
        else
        {
            if(s.find(pages[i])==s.end())
            {
                int lru = INT_MAX;
                int val = 0;
                for(auto it:s)
                {
                    if(index[it]<lru)
                    {
                        lru = index[it];
                        val = it;
                        
                    }
                }

                s.erase(val);
                s.insert(pages[i]);
                pageFault++;
                
            }
            index[pages[i]]=i;
     
        }
    }
    return pageFault;
}

int main()
{
    int n;
    cout<<"Entre the no of pages: ";
    cin>>n;

    int capacity;
    cout<<"Entre the  capacity of frames in Main Memory: ";
    cin>>capacity;

    vector<int> pages(n);

    cout<<"Entre the page sequence: ";
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }

    int pageFault = lru(pages, capacity);

    cout<<"PageFault: "<<pageFault<<endl;
    return 0;
}