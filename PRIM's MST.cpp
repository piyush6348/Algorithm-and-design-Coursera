#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
int main()
{
    long numVer=0,numEdg=0;
    cin>>numVer>>numEdg;

    typedef pair<long,long> elem;
    typedef vector<elem> vi;
    vector<vi> graph(numVer+1);

    long startV=0,endV=0,weightV=0,inp=0;

    while(inp<numEdg)
    {
        cin>>startV>>endV>>weightV;
        graph[startV].push_back(make_pair(endV,weightV));
        inp+=1;
    }

     vector<bool> isPresnet(numVer+1,false);
     vector<long> key(numVer+1,+32767);
     vector<long> parent(numVer+1,-1);

     priority_queue<elem, vector<elem>,greater<elem>> priorityQ;

        long src=1;
        priorityQ.push(make_pair(0,src));
        key[src]=0;
        //isPresnet[src-1]=true;

        long sum=0;
        while(!priorityQ.empty())
        {
            long ver=priorityQ.top().second;
            priorityQ.pop();

            isPresnet[ver]=true;

            //cout<<"ver "<<ver<<"\n";
            //cout<<graph[ver].size()<<"\n";
            for(long j=0;j<graph[ver].size();j++)
            {
                long v=graph[ver][j].first;
                long wt=graph[ver][j].second;

                //cout<<ver<<" -> "<<v<<" "<<wt<<"\n";
                if(isPresnet[v]==false && key[v]>wt)
                {
                    key[v]=wt;
                    priorityQ.push(make_pair(key[v],v));
                    parent[v]=ver;
                    //sum+=wt;
                }
            }
        }

        for(long i=1+1;i<=numVer;i++)
        {
            /*
            if(graph[parent[i]][i-1].second!=0)
            sum+=graph[parent[i]][i-1].second;

            else
            sum+=graph[i-1][parent[i]].second;
            */
            sum+=key[i];
               //cout<<parent[i]<<" -> "<<i<<"\n";
        }
         //   cout<<parent[i]<<" -> "<<i<<"\n";

        cout<<"\n"<<sum;
    return 0;
}
