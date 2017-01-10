#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int,string> vocab;
int n=0,ct=0;
vector<string> seq;

bool func1(int startIndex,int*a)
{
    string ch;
    int number=a[startIndex];
    map<int,string>::iterator it;
    it=vocab.find(number);
    if(it!=vocab.end())
    {
        ch=it->second;
        seq.push_back(ch);
        return true;
    }
    else
    {
     ch='$';
     return false;
    }
}
bool func2(int startIndex,int endIndex,int*a)
{
    string ch;
    int number=a[startIndex];
    number=number*10;
    number+=a[endIndex];

    map<int,string>::iterator it;
    it=vocab.find(number);
    if(it!=vocab.end())
    {
        ch=it->second;
        seq.push_back(ch);
        return true;
    }
    else
    {
        ch='$';
        return false;
    }
}


void obtainString(int startIndex,int endIndex,int*a)
{
    if(endIndex==n-1)
    {
        bool insertOrNot;
        if(startIndex==endIndex)
            insertOrNot=func1(startIndex,a);
        else if(endIndex==startIndex+1)
            insertOrNot=func2(startIndex,endIndex,a);

        if(insertOrNot)
        {
            for(int i=0; i<seq.size(); i++)
            cout<<seq[i];
            cout<<"\n";
        }
        ct+=1;
        return;
    }
    else if(endIndex>n-1)
    {
        if(startIndex==endIndex)
            func1(startIndex,a);
        else if(endIndex==startIndex+1)
            func2(startIndex,endIndex,a);
        return;
    }
    else if(startIndex==endIndex)
    {
        func1(startIndex,a);
        obtainString(startIndex+1,startIndex+1,a);
        seq.erase(seq.begin()+seq.size()-1);
        obtainString(startIndex+1,startIndex+1+1,a);
    }
    else if(endIndex==startIndex+1)
    {
        func2(startIndex,endIndex,a);
        obtainString(endIndex+1,endIndex+1,a);
        seq.erase(seq.begin()+seq.size()-1);
        obtainString(endIndex+1,endIndex+1+1,a);
    }
    else
    {
        obtainString(startIndex,startIndex,a);
        //seq.erase(seq.begin()+seq.size()-1);
        seq.clear();
        obtainString(startIndex,startIndex+1,a);
    }
}

int main()
{
    vocab[1]="A";
    vocab[2]="B";
    vocab[3]="C";
    vocab[4]="D";
    vocab[5]="E";
    vocab[6]="F";
    vocab[7]="G";
    vocab[8]="H";
    vocab[9]="I";
    vocab[10]="J";
    vocab[11]="K";
    vocab[12]="L";
    vocab[13]="M";
    vocab[14]="N";
    vocab[15]="O";
    vocab[16]="P";
    vocab[17]="Q";
    vocab[18]="R";
    vocab[19]="S";
    vocab[20]="T";
    vocab[21]="U";
    vocab[22]="V";
    vocab[23]="W";
    vocab[24]="X";
    vocab[25]="Y";
    vocab[26]="Z";

    cout<<"Input a number(should be atleast 4 digit number)";
    cin>>n;

    vector<int> v;
    while(n>0)
    {
        int x=n%10;
        n=n/10;
        v.push_back(x);
    }
    reverse(v.begin(),v.end());
    n=v.size();
    int* a=new int[n];
    for(int i=0; i<n; i++)
        a[i]=v[i];
    obtainString(0,n-2,a);
    cout<<ct;
    return 0;
}
