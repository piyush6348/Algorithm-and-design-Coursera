#include <iostream>
using namespace std;

class Queue
{
    int*que;
    int frontIndex;
    int rearIndex;
    int n;

public:
    Queue(int n)
    {
        frontIndex=-1;
        rearIndex=-1;
        this->n=n;
        que=new int[n];
    }
    void push(int value)
    {
        if(rearIndex==n-1)
        {
            if(frontIndex==0)
            {
                cout<<"Queue Overflow\n";
                return;
            }
            else
            {
                rearIndex=0;
            }
        }
        if(frontIndex==-1)
        {
         frontIndex=0;
         rearIndex=0;
        }
        else if(frontIndex-1==rearIndex)
        {
            cout<<"Queue Overflow\n";
            return;
        }
        else
            rearIndex+=1;
        que[rearIndex]=value;
    }
    void pop()
    {
        if(frontIndex==-1)
        {
            cout<<"Queue underflow\n";
            return;
        }
        if(frontIndex==rearIndex)
        {
            frontIndex=-1;
            rearIndex=-1;
            cout<<"Queue Underflow\n";
            return;
        }
        else if(frontIndex==n-1)
            frontIndex=0;
        else
            frontIndex+=1;
    }
    int getTop()
    {
        /*
        if((frontIndex==-1))
        {
            cout<<"Empty Queue\n";
            return (0);
        }

        if(frontIndex==rearIndex)
        {
            int t=frontIndex;
            frontIndex=-1;
            rearIndex=0;
            return que[t];
        }*/
        if(frontIndex==-1)
            return que[frontIndex+1];
        return que[frontIndex];
    }
    int sizeOfQueue()
    {
        return rearIndex;
    }
};
int main()
{
    int n=0;
    cout<<"Size of Queue\n";
    cin>>n;

    Queue que(n);
    int choice;

    while(true)
    {
        cout<<"1)Push\n";
        cout<<"2)Pop\n";
        cout<<"3)Top\n";
        cout<<"4)Exit\n";
        cin>>choice;

        if(choice==1)
        {
            int val;
            cin>>val;
            que.push(val);
        }
        if(choice==2)
        {
            cout<<que.getTop()<<"\n";
            que.pop();
        }
        if(choice==3)
        {
            cout<<que.getTop()<<"\n";
        }
        if(choice==4)
        {
            break;
        }
    }
    return 0;
}
