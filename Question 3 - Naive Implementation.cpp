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

     isPresnet[1]=true;
     int presentCount=1;
     int sum=0;
     while(presentCount<numVer)
     {
         int mini=32767,pos=-1;
         for(int i=1;i<isPresnet.size();i++)
         {
             if(isPresnet[i])
             {
                 for(int j=1;j<isPresnet.size();j++)
                 {
                     if(!isPresnet[j])
                     {
                         for(int k=0;k<graph[i].size();k++)
                         {
                             if(graph[i][k].first==j)
                             {
                                if(graph[i][k].second<mini)
                                {
                                    mini=graph[i][k].second;
                                    pos=j;
                                   // cout<<"present "<<presentCount<<" parent "<<i<<" -> "<<pos<<" mini "<<mini<<"\n";
                                }
                                break;
                             }
                         }

                         for(int k=0;k<graph[j].size();k++)
                         {
                             if(graph[j][k].first==i)
                             {
                                 if(graph[j][k].second<mini)
                                 {
                                     mini=graph[j][k].second;
                                     pos=j;
                                     //cout<<"present "<<presentCount<<" parent "<<i<<" -> "<<pos<<" mini "<<mini<<"\n";
                                 }
                                 break;
                             }
                         }
                     }
                 }
             }
         }
         sum+=mini;
         isPresnet[pos]=true;
         presentCount+=1;


         //cout<<"present "<<presentCount<<" mini "<<mini<<"\n";
     }
      cout<<" sum "<<sum;
    return 0;
}
