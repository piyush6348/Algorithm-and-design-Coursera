#include <iostream>
#include <stack>
using namespace std;

bool checkingTheBrackets(string input)
{
    stack<char> stk;

    for(int i=0;i<input.length();i++)
    {
        if(input[i]==')')
        {
            char ch=stk.top();
            stk.pop();
            if(stk.top()=='(')
                return true;
            else
            {
                while(stk.top()!='(')
                        stk.pop();
            }
        }
        else
            stk.push(input[i]);
    }
    return false;
}
int main()
{
    string input;
    cin>>input;

    if(checkingTheBrackets(input))
        cout<<"Duplicates are present\n";
    else
        cout<<"Duplicates are not present\n";
    return 0;
}
