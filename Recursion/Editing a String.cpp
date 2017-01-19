#include <iostream>
#include <time.h>
using namespace std;

void replacePI(string& str,int strIterator,string&newString,int newStringIterator)
{
    if(strIterator>str.length()-1)
        return;
    else if(str[strIterator]=='p' && str[strIterator+1]=='i')
    {
        newString.insert(newStringIterator,1,'3');
        newString.insert(newStringIterator+1,1,'.');
        newString.insert(newStringIterator+2,1,'1');
        newString.insert(newStringIterator+3,1,'4');
        replacePI(str,strIterator+2,newString,newStringIterator+4);
    }
    else
    {
        newString.insert(newStringIterator,1,str[strIterator]);
        replacePI(str,strIterator+1,newString,newStringIterator+1);
    }
}
int main()
{
    clock_t start=clock();
    string s,newString="";
    cin>>s;
    replacePI(s,0,newString,0);
    cout<<newString<<"\n";
    cout<<"Time taken is "<<((double)clock()-start)/(CLOCKS_PER_SEC);
    return 0;
}
