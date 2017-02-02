#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void floydWarshal(vector<vector<long long>> & vec,long long numVer)
{
    for(long long k=0;k<numVer;k++)
    {
        for(long long i=0;i<numVer;i++)
        {
            for(long long j=0;j<numVer;j++)
            {
                if(vec[i][j] >vec[i][k]+vec[k][j] && vec[i][k]!=LONG_LONG_MAX && vec[k][j]!=LONG_LONG_MAX)
                    vec[i][j]=vec[i][k]+vec[k][j];
            }
        }
    }
}
int main()
{
    long long numVer,numEdge;
    cin>>numVer>>numEdge;

    vector<vector<long long>> vec(numVer,vector<long long>(numVer,LONG_LONG_MAX));

    long long a,b,c;
    for(long long i=0;i<numEdge;i++)
    {
        cin>>a>>b>>c;
        vec[a-1][b-1]=c;
        //vec[b-1][a-1]=c;
    }

    for(long long i=0;i<numVer;i++)
    {
        vec[i][i]=0;
    }
/*
    for(long long i=0;i<numVer;i++)
    {
        for(long long j=0;j<numVer;j++)
            cout<<vec[i][j]<<" ";
        cout<<"\n";
    }
*/
    floydWarshal(vec,numVer);
/*
    for(long long i=0;i<numVer;i++)
    {
        for(long long j=0;j<numVer;j++)
            cout<<vec[i][j]<<" ";
        cout<<"\n";
    }*/

    for(long long i=0;i<numVer;i++)
    {
        if(vec[i][i]<0)
        {
            cout<<"Negative Cycle\n";
            break;
        }
    }
    long long mini=LONG_LONG_MAX;
    for(long long i=0;i<numVer;i++)
    {
        for(long long j=0;j<numVer;j++)
        {
            if(vec[i][j]<mini)
                mini=vec[i][j];
        }
    }
    cout<<mini<<"\n";
    return 0;
}
