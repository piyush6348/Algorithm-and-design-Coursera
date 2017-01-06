#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <bitset>
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

    int numNodes=0,numBits;
    cin>>numNodes>>numBits;

    int vertex1=0,vertex2=0,weight=0;

    vector<string> input;
    string s;
    input.push_back("0th elem");

    for(int i=1;i<=numNodes;i++)
    {
        cin>>s;
        input.push_back(s);
    }

    vector<int> sizeArr(numNodes+1,1);
    vector<int> Arr(numNodes+1);

    for(int i=1;i<=numNodes;i++)
        Arr[i]=i;

    int setCounts=numNodes;

    for(int i=1;i<=numNodes;i++)
    {
        long decimal = bitset<24>(input[i]).to_ulong();
        for(int j=i+1;j<=numNodes;j++)
        {
            long decimal2 = bitset<24>(input[j]).to_ulong();
            if(decimal2==decimal+1 || decimal2==decimal || decimal2==decimal+2)
            {
                UNION(Arr,sizeArr,i,j,numNodes);
               // setCounts-=1;
               //Arr[j]=Arr[i];
            }
        }
    }

    vector<int> tempo;
    for(int i=1;i<=Arr.size();i++)
    {
        if(tempo.size()==0)
            tempo.push_back(Arr[i]);
        else
        {
            int found=0;
            for(int j=0;j<tempo.size();j++)
            {
                if(Arr[i]==tempo[j])
                {
                    found=1;
                    break;
                }
            }
            if(found==0)
                tempo.push_back(Arr[i]);
        }
    }

    //cout<<setCounts<<"\n";
    cout<<setCounts-tempo.size();
    return 0;
}
