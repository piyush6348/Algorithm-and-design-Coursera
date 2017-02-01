#include <iostream>
#include <stack>
using namespace std;

class Stack
{   stack<int> stk;
    stack<int> minStk;
    int n;

    public:
    Stack(int n)
    {
        this->n=n;
    }
    void push(int value)
    {
        if(stk.size()==n)
        {
            cout<<"Stack Overflow\n";
            return;
        }
        if(minStk.empty())
        {
            stk.push(value);
            minStk.push(value);
        }
        else
        {
            if(minStk.top()>=value)
                minStk.push(value);
            else
                minStk.push(minStk.top());
            stk.push(value);
        }
    }
    void pop()
    {
        if(stk.empty())
        {
            cout<<"Stack Underflow\n";
            return;
        }
        else
        {
            cout<<"Popped element is "<<stk.top()<<"\n";
            stk.pop();
            minStk.pop();
        }
    }
    int getMinimum()
    {
        if(minStk.empty())
        {
            cout<<"Enter elements in Stack\n";
            return 0;
        }
        return minStk.top();
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
        cout<<"3)Minimum\n";
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
            cout<<stk.getMinimum()<<"\n";
        }
        if(choice==4)
        {
            break;
        }
    }
    return 0;
}
