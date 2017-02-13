#include <iostream>
#include <stack>
using namespace std;

class Stack
{
    stack<int> stk;
    int n;
public:
    Stack(int n)
    {
        this->n=n;
    }
    void stock(int*value)
    {
        int k=1;
        for(int i=0; i<n; i++)
        {
            if(i==0)
                stk.push(k);
            else
            {
                if(value[i]<value[i-1])
                    stk.push(k);
                else
                {
                    stk.push(stk.top()+1);
                }
            }

            cout<<stk.top()<<" ";
        }
    }
};
int main()
{
    int n=0;
    cout<<"Number of Stocks\n";
    cin>>n;

    Stack stk(n);
    int choice;
    int*a=new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    stk.stock(a);
    return 0;
}
