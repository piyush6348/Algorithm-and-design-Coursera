#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class DequeDS
{
    queue<int> Deque;
    int n;

public:
    DequeDS(int n)
    {
        this->n=n;
    }
    void push(int value)
    {
        if(Deque.size()==n)
        {
            cout<<"Deque Overflow\n";
            return;
        }

        queue<int> tempo;
        while(!Deque.empty())
        {
            int temp=Deque.front();
            Deque.pop();
            tempo.push(temp);
        }
        Deque.push(value);
        while(!tempo.empty())
        {
            int temp=tempo.front();
            tempo.pop();
            Deque.push(temp);
        }
    }
    int pop()
    {
        if(Deque.empty())
        {
            cout<<"Deque underflow\n";
            return 0;
        }
        int temp=Deque.front();
        Deque.pop();
        return temp;
    }

    void inject(int value)
    {
        if(Deque.size()==n)
        {
            cout<<"Deque Overflow\n";
            return;
        }
        Deque.push(value);
    }
    int eject()
    {
        if(Deque.empty())
        {
            cout<<"Deque underflow\n";
            return 0;
        }
        queue<int> tempo;
        while(Deque.size()>1)
        {
            int temp=Deque.front();
            Deque.pop();
            tempo.push(temp);
        }
        int k=Deque.front();
        Deque.pop();
        while(!tempo.empty())
        {
            int temp=tempo.front();
            tempo.pop();
            Deque.push(temp);
        }

        return k;
    }
};
int main()
{
    int n=0;
    cout<<"Size of DequeDS\n";
    cin>>n;

    DequeDS stk(n);
    int choice;

    while(true)
    {
        cout<<"1)Push\n";
        cout<<"2)Pop\n";
        cout<<"3)Inject\n";
        cout<<"4)Eject\n";
        cout<<"5)Exit\n";
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
            cout<<stk.pop()<<"\n";
        }
        if(choice==4)
        {
            cout<<stk.eject()<<"\n";
        }
        if(choice==3)
        {
            int val;
            cin>>val;
            stk.inject(val);
        }
        if(choice==5)
        {
            break;
        }
    }
    return 0;
}
