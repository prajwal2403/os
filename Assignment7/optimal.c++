#include<iostream>
#include<unordered_set>
#include<vector>
#include<climits>

using namespace std;


int optimal(vector<int> &pages, int capacity)
{
    unordered_set<int> s;
    int pageFault=0;

    for(int i=0;i<pages.size();i++)
    {
        if(s.size()<capacity)
        {
            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                pageFault++;

            }

        }
        else
        {
            if(s.find(pages[i])==s.end())
            {
                int max=-1;
                int val;
                for(auto it:s)
                {
                    int next_val =  INT_MAX;

                    for(int j=i+1;j<pages.size();j++)
                    {
                        
                        if(pages[j]==it)
                        {
                            next_val = j;
                            break;
                        }
                    }
                    if(next_val>max)
                    {
                        max = next_val;
                        val = it;
                    }
                }

                s.erase(val);
                s.insert(pages[i]);
                pageFault++;

            }
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
    cout<<"Entre the no of frames: ";
    cin>>capacity;
    vector<int> pages(n);
    cout<<"Enter the pages values: ";
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }
    int pageFault = optimal(pages, capacity);

    cout<<"PageFault: "<<pageFault<<endl;

    return 0;
}