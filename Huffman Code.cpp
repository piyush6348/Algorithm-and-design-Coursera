#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<long,char> elem;
struct node{
    elem value;
    node*left;
    node*right;

  /*  bool operator<(const node& a) {
        return value.first > a.value.first;
}*/
};

struct compare
{
    bool operator()(node* l, node* r)
    {
        return (l->value.first > r->value.first);
    }
};

int len=0;
vector<string> codes;
void printCodes( node* root, string str)
{
    if (root->left==NULL && root->right==NULL)
    {
       // cout << root->value.first << ": " << str << "\n";
        codes.push_back(str);
    }

/*
    if (root->value.second != '$')
    {
        cout << root->value.first << ": " << str << "\n";
        codes.push_back(str);
    }*/

     if(root->left!=NULL)
        printCodes(root->left, str + "0");

     if(root->right!=NULL)
        printCodes(root->right, str + "1");
}

int main()
{
    priority_queue<node*,vector<node*>,compare> priorityQ;

    long numSymbols=0,wt;

    cin>>numSymbols;
    for(long i=1;i<=numSymbols;i++)
    {
        cin>>wt;

        node *temp=new node();

        temp->value=make_pair(wt,'A');
        temp->left=NULL;
        temp->right=NULL;

        priorityQ.push(temp);
    }

  /*  while(priorityQ.size()>=1)
    {
        cout<<priorityQ.top()->value.first<<"\n";
        priorityQ.pop();
    }
*/
    while(priorityQ.size()>1)
    {
        node* min1=priorityQ.top();
        priorityQ.pop();

        node* mini2=priorityQ.top();
        priorityQ.pop();

        node *temp=new node();
        temp->left=min1;
        temp->right=mini2;
        temp->value=make_pair(min1->value.first+mini2->value.first,'$');

       // cout<<"popped "<<min1->value.first<<" "<<mini2->value.first<<" "<<temp->value.first<<"\n";
        priorityQ.push(temp);
    }


    node* temp=priorityQ.top();



    printCodes(temp,"");
    vector<int> codelen;

    for(long i=0;i<codes.size();i++)
        codelen.push_back(codes[i].length());


    sort(codelen.begin(),codelen.end());
    cout<<codelen[0]<<"  "<<codelen[codelen.size()-1];


    return 0;
}
