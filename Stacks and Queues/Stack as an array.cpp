#include <iostream>
using namespace std;

class Stack
{   int*stk;
    int top;
    int n;

    public:
    Stack(int n)
    {
        top=-1;
        this->n=n;
        stk=new int[n];
    }
    void push(int value)
    {
        if(top==n-1)
        {
            cout<<"Stack Overflow\n";
            return;
        }
        top+=1;
        stk[top]=value;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack undeflow\n";
            return;
        }
        top-=1;
    }
    int getTop()
    {
        if(top==-1)
        {
         cout<<"Empty Stack\n";
         return (0);
        }
        return stk[top];
    }
    int sizeOfStack()
    {
        return top+1;
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
            cout<<stk.getTop()<<"\n";
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
