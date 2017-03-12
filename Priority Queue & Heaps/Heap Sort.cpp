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
    void print()
    {
        for(int i=0;i<priorityQueue.size();i++)
            cout<<priorityQueue[i]<<" ";
    }

    void buildMaxHeap()
    {
        for(int i=priorityQueue.size()/2-1;i>=0;i--)
            heapify(i);
    }
    void heapSort(vector<int> vec)
    {
        vector<int> sortedHeap;
        priorityQueue=vec;
        buildMaxHeap();
        print();
        cout<<"\n";
        while(!priorityQueue.size()==0)
        {
            int maximum=priorityQueue[0];
            swapIndexValues(0,priorityQueue.size()-1);
            priorityQueue.pop_back();
            heapify(0);
            sortedHeap.push_back(maximum);
        }
        reverse(sortedHeap.begin(),sortedHeap.end());
        priorityQueue=sortedHeap;
        print();
    }
    MaxPQ(){}
};
int main()
{
    MaxPQ priorityQueueObj;
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(40);
    priorityQueueObj.heapSort(vec);
}
