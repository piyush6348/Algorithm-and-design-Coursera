#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Without using another ddata structure
void reverseQueue(queue<long>& que)
{
    if(que.empty())
        return;
    long x=que.front();
    que.pop();
    reverseQueue(que);
    que.push(x);
}
int main()
{
    stack<long> stk;
    queue<long> que;

    que.push(7);
    que.push(77);
    que.push(777);
    que.push(7777);
    que.push(77777);
    que.push(777777);

    // Using Stack
    /*
    while(!que.empty())
    {
        long temp=que.front();
        que.pop();
        stk.push(temp);
    }
    while(!stk.empty())
    {
        long temp=stk.top();
        stk.pop();
        que.push(temp);
    }
    */
    reverseQueue(que);
    while(!que.empty())
    {
        long temp=que.front();
        que.pop();
        cout<<temp<<"\n";
    }
    return 0;
}
