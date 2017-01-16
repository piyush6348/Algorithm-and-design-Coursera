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
    long numVertices=0,weight=0;
    cin>>numVertices;

    vector<long> vec(numVertices+1,0);
    vector<long> result(numVertices+1,0);
    vec.push_back(0);
    for(long i=1;i<=numVertices;i++)
    {
        cin>>weight;
        vec[i]=weight;
    }
    result[1]=vec[1];

    for(long i=2;i<=numVertices;i++)
    {
        result[i]=maximum(result[i-1],result[i-2]+vec[i]);
    }

    /*for(long i=1;i<=numVertices;i++)
        cout<<result[i]<<" ";
        cout<<"\n";*/
    long i=numVertices;
    while(i>=1)
    {
        if(result[i-1]>=result[i-2]+vec[i])
            i-=1;
        else
        {   // For sake of submission of assignment uncomment the line below
            //if(i==1 || i==2 || i==3 || i==4 || i==17 || i==117 || i==517 || i==997 )
            cout<<i<<"\n";
            i-=2;
        }
    }
    return 0;
}
