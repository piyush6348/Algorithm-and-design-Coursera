#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

bool FIND(vector<int> &a,int v1,int v2)
{
    if(a[v1]==a[v2])
        return true;
    else
        return false;
}

void UNION(vector<int> &arr,vector<int> &siz,int v1,int v2,int numNodes)
{
    if(siz[v1]>=siz[v2])
    {
        int temp=arr[v2];
        for(int i=1;i<=numNodes;i++)
        {
            if(arr[i]==temp)
                arr[i]=arr[v1];
        }
        siz[v1]+=siz[v2];
    }
    else
    {
        int temp=arr[v1];
        for(int i=1;i<=numNodes;i++)
        {
            if(arr[i]==temp)
                arr[i]=arr[v2];
        }
        siz[v2]+=siz[v1];
    }
}
int main()
{
    typedef pair<int,int> wtV1;
    typedef pair<wtV1,int> wtV1V2;
    vector<wtV1V2> edges;

    priority_queue<wtV1V2, vector<wtV1V2>,greater<wtV1V2>> priorityQ;

    int numNodes=0;
    cin>>numNodes;

    int vertex1=0,vertex2=0,weight=0;
    while(true)
    {
        cin>>vertex1>>vertex2>>weight;
        if(vertex1!=-1)
        {
            priorityQ.push(make_pair(make_pair(weight,vertex1),vertex2));
        }
        else
            break;
    }

    vector<int> sizeArr(numNodes+1,1);
    vector<int> Arr(numNodes+1);

    for(int i=1;i<=numNodes;i++)
        Arr[i]=i;
    int k=4,setCounts=numNodes;

    int maxSpace=0;
    while(setCounts>=k)
    {
        int miniWeight=priorityQ.top().first.first;
        int miniVertex1=priorityQ.top().first.second;
        int miniVertex2=priorityQ.top().second;
        priorityQ.pop();
        if(!FIND(Arr,miniVertex1,miniVertex2))
        {
            maxSpace=miniWeight;
            UNION(Arr,sizeArr,miniVertex1,miniVertex2,numNodes);
            setCounts-=1;
        }
    }
    cout<<maxSpace<<"\n";
    return 0;
}
