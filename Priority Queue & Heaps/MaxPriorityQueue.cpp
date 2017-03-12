#include <iostream>
#include <vector>
using namespace std;

class MaxPQ{
    vector<int> priorityQueue;
public:
    void heapify(int location)
    {

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
    void print()
    {
        for(int i=0;i<priorityQueue.size();i++)
            cout<<priorityQueue[i]<<" ";
    }
};
int main()
{
    MaxPQ priorityQueueObj;
    priorityQueueObj.push(10);
    priorityQueueObj.push(20);
    priorityQueueObj.push(30);
    priorityQueueObj.push(15);
    priorityQueueObj.print();
}
