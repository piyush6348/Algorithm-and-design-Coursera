#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <functional>
#include <time.h>
using namespace std;

priority_queue<string,vector<string>,greater<string>> priorityQ;
void insertInQueue(int i,int n)
{
    if(i<=n)
    {
        string temp=to_string(i);
        priorityQ.push(temp);
        insertInQueue(i+1,n);
    }
}
void show()
{
    while(!priorityQ.empty())
    {
        string temp=priorityQ.top();
        cout<<temp<<"\n";
        priorityQ.pop();
    }
}
int main()
{
    clock_t start=clock();
    int n=0;
    cin>>n;
    insertInQueue(1,n);
    show();
    cout<<((double)(clock()-start))/(CLOCKS_PER_SEC);
    return 0;
}
