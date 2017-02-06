#include<queue>
#include <iostream>
using namespace std;
/* you only have to complete the function given below.
Node is defined as
*/
struct node
{
    int data;
    node* left;
    node* right;
};
class Tree
{
    node* root;
public:
    void insertInBinaryTree(int value)
    {
        if(root==NULL)
        {
            root=new node();
            root->data=value;
            root->left=NULL;
            root->right=NULL;
        }
        else
        {
            node *temp=new node();
            temp->data=value;
            temp->left=NULL;
            temp->right=NULL;

            queue<node*> Queue;
            Queue.push(root);

            while(!Queue.empty())
            {
                node* traverse=Queue.front();
                Queue.pop();
                if(traverse->left!=NULL)
                    Queue.push(traverse->left);
                else
                {
                    traverse->left=temp;
                    return;
                }
                if(traverse->right!=NULL)
                    Queue.push(traverse->right);
                else
                {
                    traverse->right=temp;
                    return;
                }
            }
        }
    }

    void printTree()
    {
        if(root==NULL)
            return;
        queue<node*> Queue;
        Queue.push(root);
        Queue.push(NULL);
        while(!Queue.empty())
        {
            node* temp=Queue.front();
            Queue.pop();

            if(temp==NULL)
            {
                if(!Queue.empty())
                {
                    Queue.push(NULL);
                    cout<<"\n";
                }
            }
            else
            {
                cout<<temp->data<<" ";
                if(temp->left!=NULL)
                    Queue.push(temp->left);
                if(temp->right!=NULL)
                    Queue.push(temp->right);
            }
        }
    }
    void deleteAllLeafNodes()
    {
        node*x=NULL;
        typedef pair<node*,node*> elem;
        queue<elem> Queue;
        Queue.push(make_pair(root,x));

        while(!Queue.empty())
        {
            node* temp=Queue.front().first;
            node* parent=Queue.front().second;
            Queue.pop();

            if(temp->left!=NULL)
                Queue.push(make_pair(temp->left,temp));
            if(temp->right!=NULL)
                Queue.push(make_pair(temp->right,temp));
            if(temp->left == NULL && temp->right == NULL)
            {
                if(parent->left == temp)
                    parent->left=NULL;
                else if(parent->right == temp)
                    parent->right=NULL;
                delete temp;
            }
        }
    }

    void deleteHalfNodes()
    {
        node*x=NULL;
        typedef pair<node*,node*> elem;
        queue<elem> Queue;
        Queue.push(make_pair(root,x));

        while(!Queue.empty())
        {
            node* temp=Queue.front().first;
            node* parent=Queue.front().second;
            Queue.pop();

            if(temp->left!=NULL)
                Queue.push(make_pair(temp->left,temp));
            if(temp->right!=NULL)
                Queue.push(make_pair(temp->right,temp));
            if((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL))
            {
                if(parent->left == temp)
                {
                    if(temp->left!=NULL)
                        parent->left=temp->left;
                    else if(temp->right!=NULL)
                        parent->left=temp->right;
                }
                else if(parent->right == temp)
                {
                    if(temp->left!=NULL)
                        parent->right=temp->left;
                    else if(temp->right!=NULL)
                        parent->right=temp->right;
                }
                delete temp;
            }
        }
    }
    bool structurallyIdentically(Tree obj)
    {

    }
    Tree()
    {
        root=NULL;
    }
};

int main()
{
    Tree tree;
    int choice=0,value=0;
    while(true)
    {
        cout<<"1.) Enter an Element\n";
        cout<<"2.) Delete Leaf Nodes\n";
        cout<<"3.) Print Tree\n";
        cout<<"4.) Exit\n";
        cout<<"5.) Delete Half Nodes\n";
        cin>> choice;
        switch(choice)
        {
        case 1:
            cin>>value;
            tree.insertInBinaryTree(value);
            //tree.printTree();
            break;
        case 2:
            tree.deleteAllLeafNodes();
            break;
        case 3:
            tree.printTree();
            break;
        case 4:
            return 0;
            break;
        case 5:
            tree.deleteHalfNodes();
            break;
        }
    }
    return 0;
}
