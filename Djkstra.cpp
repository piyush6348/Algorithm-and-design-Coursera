#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;

vector<pair<int,int>> djkstra(vector<vector<pair<int,int>>> graph,int source)
{
    vector<pair<int,int>> ans;
    vector<int> score(graph.size()+1,INT_MAX);

    score[source]=0;
    set<pair<int,int>> mp;
    mp.insert(make_pair(0,source));

    for(int i=source+1;i<=graph.size();i++)
        mp.insert(make_pair(INT_MAX,i));

    cout<<mp.size()<<" ";
    while(!mp.empty())
    {
        int miniNode=mp.begin()->second;
        int miniDist=mp.begin()->first;

        cout<<miniNode<<" ";
        for(int j=0;j<graph[miniNode].size();j++)
        {
            int dist=graph[miniNode][j].first;
            int node=graph[miniNode][j].second;

            cout<<node<<" ";
            if(score[node]> miniDist+dist)
            {
                mp.erase(make_pair(score[node],node));
                score[node]=miniDist+dist;
                mp.insert(make_pair(miniDist+dist,node));
             //mp[dist]= miniDist+dist;
            }
        }
        cout<<"\n";
        ans.push_back(make_pair(miniDist,miniNode));
        mp.erase(mp.begin());
    }
    return ans;
}
int main()
{
    vector<vector<pair<int,int>>> graph;

    vector<pair<int,int>> temp;
    int numVertices=0,numEdges=0;

    cin>>numVertices>>numEdges;
    int source=0,dest=0,wt=0;
    graph.resize(numVertices+1);

    for(int i=1;i<=numEdges;i++)
    {
        cin>>source>>dest>>wt;
        graph[source].push_back(make_pair(wt,dest));
        graph[dest].push_back(make_pair(wt,source));
    }

    vector<pair<int,int>> res=djkstra(graph,1);
    /*
    for(int i=1;i<=res.size();i++)
        cout<<res[i].first<<" ";*/
    return 0;
}
