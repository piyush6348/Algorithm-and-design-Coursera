#include <iostream>
#include <stack>
using namespace std;

bool checkingTheBrackets(string input)
{
    stack<char> stk;

    for(int i=0;i<input.length();i++)
    {
        if(input[i]=='(' || input[i]=='[' || input[i]=='{')
            stk.push(input[i]);

        else if(input[i]==')' || input[i]==']' || input[i]=='}')
        {
            if(stk.empty())
                return false;
            char ch=stk.top();
            stk.pop();

            if(!((input[i]==')' && ch=='(') || (input[i]==']' && ch=='[') || (input[i]=='}' && ch=='{')))
                return false;
        }
    }
    if(stk.empty())
    return true;
    
    return false;
}
int main()
{
    string input;
    cin>>input;

    if(checkingTheBrackets(input))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}
