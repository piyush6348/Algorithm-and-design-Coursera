#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;
    int n;

public:
    Queue(int n)
    {
        this->n=n;
    }
    void push(int value)
    {
        if(s1.size()+s2.size()==n)
        {
            cout<<"Queue Overflow\n";
            return;
        }
        s1.push(value);
    }
    void pop()
    {
        if(s1.empty() && s2.empty())
        {
            cout<<"Queue Underflow\n";
        }
        else if(s2.empty())
        {
            while(!s1.empty())
            {
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
            cout<<s2.top()<<"\n";
            s2.pop();
        }
        else
        {
            cout<<s2.top()<<"\n";
            s2.pop();
        }
    }
    int getTop()
    {
        if(s1.empty() && s2.empty())
        {
            cout<<"Please enter some elements in Queue\n";
            return 0;
        }
        else if(s2.empty())
        {
            while(!s1.empty())
            {
                int temp=s1.top();
                s1.pop();
                s2.push(temp);
            }
            return s2.top();
        }
        else
            return s2.top();
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
        cout<<"1)Enqueue\n";
        cout<<"2)Dequeue\n";
        cout<<"3)Front\n";
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
            //cout<<que.getTop()<<"\n";
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
