#include <iostream>
#include <queue>
using namespace std;

class Stack
{   queue<int> q1;
    queue<int> q2;
    int top;
    int n;

    public:
    Stack(int n)
    {
        this->n=n;
    }
    void push(int value)
    {
        if(q1.size()==n || q2.size()==n)
        {
            cout<<"Stack Overflow\n";
            return;
        }
        if(q1.empty())
            q2.push(value);
        else
            q1.push(value);
    }
    void pop()
    {
        if(q1.empty() && !q2.empty())
        {
            while(q2.size()>1)
            {
                int temp=q2.front();
                q2.pop();
                q1.push(temp);
            }
            cout<<q2.front()<<"\n";
            q2.pop();
        }
        else if(!q1.empty() && q2.empty())
        {
            while(q1.size()>1)
            {
                int temp=q1.front();
                q1.pop();
                q2.push(temp);
            }
            cout<<q1.front()<<"\n";
            q1.pop();
        }
        else
            cout<<"Stack Underflow\n";
    }
    int getTop(){
        if(q1.empty() && !q2.empty())
            return q2.front();
        else if(!q1.empty() && q2.empty())
            return q1.front();
        else
        {
            cout<<"Please insert elements in Stack\n";
            return 0;
        }
    }
};
int main()
{
    int n=0;
    cout<<"Size of Stack\n";
    cin>>n;

    Stack stk(n);
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
            stk.push(val);
        }
        if(choice==2)
        {
            //cout<<stk.getTop()<<"\n";
            stk.pop();
        }
        if(choice==3)
        {
            cout<<stk.getTop()<<"\n";
        }
        if(choice==4)
        {
            break;
        }
    }
    return 0;
}
