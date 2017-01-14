#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<long,long> elem;
map<elem,long> result;

long maximum(long a,long b)
{
    if(a>=b)
        return a;
    else
        return b;
}

long func(long i, long j, vector<long> &wt,vector<long> &val)
{
    if(i==1)
        return (0);
    else
    {
        map<elem,long>::iterator it=result.find(make_pair(i,j));
        if(it!=result.end())
            return it->second;
        else if(wt[i]>j)
        {
            long temp=func(i-1,j,wt,val);
            result[make_pair(i,j)]=temp;
            return temp;
        }
        else
        {
            long temp=maximum(func(i-1,j-wt[i],wt,val)+val[i],func(i-1,j,wt,val));
            result[make_pair(i,j)]=temp;
            return (temp);
        }
    }
}
int main()
{
    long numItems=0,capacity=0;
    cin>>capacity>>numItems;

    vector<long> wt(numItems+1,0);
    vector<long> val(numItems+1,0);

    long weight=0,value=0;
    for(long i=1;i<=numItems;i++)
    {
        cin>>value>>weight;
        wt[i]=weight;
        val[i]=value;
    }

    cout<<func(numItems,capacity,wt,val);

    return 0;
}
