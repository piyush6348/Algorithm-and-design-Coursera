#include <iostream>
#include <vector>
#include <limits.h>
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
    void print()
    {
        for(int i=0;i<priorityQueue.size();i++)
            cout<<priorityQueue[i]<<" ";
    }
    MaxPQ(){}
    MaxPQ(vector<int> vec)
    {
        priorityQueue=vec;
        for(int i=priorityQueue.size()/2-1;i>=0;i--)
            heapify(i);
    }
};
int main()
{
    MaxPQ priorityQueueObj;
    priorityQueueObj.push(10);
    priorityQueueObj.push(20);
    priorityQueueObj.push(30);
    priorityQueueObj.push(15);
    priorityQueueObj.push(45);
    priorityQueueObj.push(115);
    priorityQueueObj.push(105);
    priorityQueueObj.push(150);
    priorityQueueObj.print();

    cout<<"\n";
    priorityQueueObj.pop();
    priorityQueueObj.print();
    cout<<"\n";
    priorityQueueObj.pop();
    priorityQueueObj.print();
    cout<<"\n";
    priorityQueueObj.pop();
    priorityQueueObj.print();
    cout<<"\n";
    priorityQueueObj.pop();
    priorityQueueObj.print();

    int topValue=priorityQueueObj.top();
    if(topValue!=INT_MIN)
        cout<<topValue<<"\n";
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    MaxPQ obj2(vec);
    obj2.print();
}
