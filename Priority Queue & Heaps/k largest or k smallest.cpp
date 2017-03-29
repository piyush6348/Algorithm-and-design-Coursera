#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class MaxPQ{
    vector<int> priorityQueue;
public:
    void heapify(int location)
    {
        int largestIndex=0;
        if(2*location+1>=priorityQueue.size())
            return;
        if(2*location+2>=priorityQueue.size())
            largestIndex=largestOfTwo(location,2*location+1);
        else
            largestIndex=largestOfThree(location,2*location+1,2*location+2);
        if(largestIndex==location)
            return;
        else
        {
            swapIndexValues(location,largestIndex);
            heapify(largestIndex);
        }
    }
    int largestOfTwo(int ind1,int ind2)
    {
        if(priorityQueue[ind1]>priorityQueue[ind2])
            return ind1;
        return ind2;
    }
    int largestOfThree(int ind1,int ind2,int ind3)
    {
        if(priorityQueue[ind1]>priorityQueue[ind2])
        {
            if(priorityQueue[ind1]>priorityQueue[ind3])
                return ind1;
            else
                return ind3;
        }
        else
        {
            if(priorityQueue[ind2]>priorityQueue[ind3])
                return ind2;
            else
                return ind3;
        }
    }
    void swapIndexValues(int ind1,int ind2)
    {
        int temp=priorityQueue[ind1];
        priorityQueue[ind1]=priorityQueue[ind2];
        priorityQueue[ind2]=temp;
    }
    void valueUpdatedOrAdded(int location)
    {
        if(priorityQueue[(location-1)/2]<priorityQueue[location])
        {
            swapIndexValues((location-1)/2,location);
            valueUpdatedOrAdded((location-1)/2);
        }
        else
            return;
    }
    void push(int value)
    {
        priorityQueue.push_back(value);
        if(priorityQueue.size()==1)
            return;
        valueUpdatedOrAdded(priorityQueue.size()-1);
    }
    int pop()
    {
        swapIndexValues(0,priorityQueue.size()-1);
        priorityQueue.pop_back();
        heapify(0);
    }
    int top()
    {
        if(priorityQueue.size()==0)
        {
            cout<<"Please add elements to max priority queue\n";
            return INT_MIN;
        }
        return priorityQueue[0];
    }
    void buildMaxHeap()
    {
        for(int i=priorityQueue.size()/2-1;i>=0;i--)
            heapify(i);
    }
    vector<int> kLargestElements(vector<int> elems,int k)
    {
        priorityQueue=elems;
        buildMaxHeap();
        vector<int> maxElems;

        for(int i=1;i<=k;i++)
        {
            maxElems.push_back(top());
            pop();
        }
        for(int i=0;i<maxElems.size();i++)
            push(maxElems[i]);
        return maxElems;
    }
    vector<int> kSmallestElements(vector<int> elems,int k)
    {
        priorityQueue=elems;
        buildMaxHeap();
        vector<int> minElems,temp;

        int tempSize=priorityQueue.size();
        for(int i=1;i<=tempSize-k;i++)
        {
            temp.push_back(top());
            pop();
        }
        while(!priorityQueue.size()==0)
        {
            minElems.push_back(top());
            pop();
        }
        reverse(minElems.begin(),minElems.end());
        for(int i=0;i<minElems.size();i++)
            push(minElems[i]);
        for(int i=0;i<temp.size();i++)
            push(temp[i]);
        return minElems;
    }
    void print()
    {
        for(int i=0;i<priorityQueue.size();i++)
            cout<<priorityQueue[i]<<" ";
    }
    MaxPQ(){}
};
int main()
{
    int choice=0,k=0;
    MaxPQ priorityQueueObj;
    cout<<"1.) k largest\n";
    cout<<"2.) k smallest\n";
    cin>>choice;

    cout<<"Enter k\n";
    cin>>k;
    vector<int> vec,ans;
    vec.push_back(10);
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(40);

    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<"\n";
    if(choice==1)
    {
        ans=priorityQueueObj.kLargestElements(vec,k);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    else
        {
        ans=priorityQueueObj.kSmallestElements(vec,k);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
}
