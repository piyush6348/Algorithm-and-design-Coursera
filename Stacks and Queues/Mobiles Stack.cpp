#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n=0,t=0;
    cout<<"No of testcases\n";
    cin>>t;

    for(int test=1; test<=t; test++)
    {
        cout<<"Number of elements\n";
        cin>>n;

        stack<int> stk;
        int temp,ct=1;
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            cin>>temp;
            if(temp==ct)
                ct+=1;
                //stk.push(temp);
            else
            {
                if(stk.empty())
                    stk.push(temp);
                else if(stk.top()>temp)
                {
                    stk.push(temp);
                }
                else
                {
                    ans=1;
                    break;
                }
            }
        }
        if(ans==1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }

    return 0;
}
