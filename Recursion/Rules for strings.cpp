#include <iostream>
using namespace std;
bool stringChecker(string str,int index)
{
    if(index== str.length())
        return true;
    if(index ==0 && str[index]!='a')
        return false;
    else
    {
        if(index==str.length()-1)
        {
            if(str[index]=='a')
            {
                return true;
            }
            else
                return false;
        }
        else
        {
            if(str[index]=='a')
            {
                if(str[index+1]=='a')
                    return stringChecker(str,index+1);
                else if(str[index+1]=='b' && str[index+2]=='b')
                    return stringChecker(str,index+3);
                else
                    return false;
            }
            else
                return false;
        }
    }

}
int main()
{
    string str;
    cin>>str;
    bool result=stringChecker(str,0);
    if(result)
        cout<<"True\n";
    else
        cout<<"False\n";
    return 0;
}
