#include <iostream>
#include <vector>
using namespace std;

long maximum(long a,long b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    long numItems=0,capacity=0;
    cin>>capacity>>numItems;

    vector<long> vec(capacity+1,0);
    vector<vec> result(numItems+1,0);

    vector<long> wt(numItems+1,0);
    vector<long> val(numItems+1,0);

    long weight=0,value=0;
    for(long i=1;i<=numItems;i++)
    {
        cin>>value>>weight;
        wt[i]=weight;
        val[i]=value;
    }
    for(long i=1;i<=numItems;i++)
    {
        for(long j=0;j<=capacity;j++)
        {
            if(wt[i]>j)
                result[i][j]=result[i-1][j];
            else
                result[i][j]=maximum(result[i-1][j-wt[i]]+val[i],result[i-1][j]);
        }
    }
    cout<<result[numItems][capacity];
    return 0;
}
