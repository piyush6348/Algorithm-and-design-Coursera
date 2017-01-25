#include <iostream>
using namespace std;

class Stack
{
    struct node{
    int value;
    node *next;
    };

    node* start;
    public:
    Stack()
    {
        start=new node();
        start->next=NULL;
    }
    void push(int val)
    {
        node*temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        node*x=new node;
        x->value=val;
        x->next=NULL;
        temp->next=x;
    }
    void pop()
    {
        node*temp=start,*parent;;
        if(temp->next==NULL)
        {
            cout<<"Stack Underflow\n";
            return;
        }
        while(temp->next!=NULL)
        {
            parent=temp;
            temp=temp->next;
        }
        parent->next=NULL;
        delete (temp);

    }
    int getTop()
    {
        node*temp=start;
        if(temp->next==NULL)
        {
         cout<<"Empty Stack\n";
         return (0);
        }
        while(temp->next!=NULL)
            temp=temp->next;
        return temp->value;
    }
    int sizeOfStack()
    {
        int ct=0;
        node*temp=start;
        while(temp->next!=NULL)
        {
            ct+=1;
            temp=temp->next;
        }
        return ct;
    }
};
int main()
{
    Stack stk;
    int choice;

    while(true)
    {
        cout<<"1)Push\n";
        cout<<"2)Pop\n";
        cout<<"3)Top\n";
        cout<<"4)Exit\n";
        cin>>choice;

        if(choice==1)
        {
            int val;
            cin>>val;
            stk.push(val);
        }
        if(choice==2)
        {
            cout<<stk.getTop()<<"\n";
            stk.pop();
        }
        if(choice==3)
        {
            cout<<stk.getTop()<<"\n";
        }
        if(choice==4)
        {
            break;
        }
    }
    return 0;
}
