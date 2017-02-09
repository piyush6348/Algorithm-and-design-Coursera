#include<queue>
#include <iostream>
#include <stack>
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
    //node* root;
public:
    node* root;
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
        bool ans=true;
        stack<node*> stk1,stk2;
        while(true)
        {
            while(root!=NULL || obj.root!=NULL)
            {
                if(root!=NULL)
                    stk1.push(root);
                else
                    stk1.push(NULL);

                if(obj.root!=NULL)
                    stk2.push(obj.root);
                else
                    stk2.push(NULL);

                if(root!=NULL)
                    root=root->left;
                if(obj.root!=NULL)
                    obj.root=obj.root->left;
            }
            if(stk1.empty() || stk2.empty())
                break;
            root=stk1.top();
            stk1.pop();

            obj.root=stk2.top();
            stk2.pop();

            if(root== NULL && obj.root==NULL)
                ans=ans && true;
            else if((root!=NULL && obj.root==NULL) || (root==NULL && obj.root!=NULL))
                ans=ans && false;
            else if(root->data == obj.root->data)
                ans=ans && true;
            else if(root->data != obj.root->data)
                ans=ans && false;
            if(root!=NULL)
                root=root->right;
            if(obj.root!=NULL)
                obj.root=obj.root->right;
        }
        return ans;
    }

    void convertMirror()
    {
        node* xx=root;
        stack<node*> stk;
        node* previous=NULL;
        do
        {
            while(root!=NULL)
            {
                stk.push(root);
                root=root->left;
            }
            while(root==NULL && !stk.empty())
            {
                root=stk.top();
                if(root->right==NULL || root->right==previous)
                {
                    stk.pop();
                    previous=root;

                    node* temp=root->left;
                    root->left=root->right;
                    root->right=temp;
                    root=NULL;
                }
                else
                    root=root->right;
            }
        }
        while(!stk.empty());
        root=xx;
    }
    void printAllNodesWithoutSiblings()
    {
        node* xx=root;
        stack<node*> stk;
        node* previous=NULL;
        do
        {
            while(root!=NULL)
            {
                stk.push(root);
                root=root->left;
            }
            while(root==NULL && !stk.empty())
            {
                root=stk.top();
                if(root->right==NULL || root->right==previous)
                {

                    if((root->left==NULL && root->right!=NULL))
                        cout<<root->right->data<<"\n";
                    if ((root->left!=NULL && root->right==NULL))
                        cout<<root->left->data<<"\n";
                    stk.pop();
                    previous=root;
                    root=NULL;
                }
                else
                    root=root->right;
            }
        }
        while(!stk.empty());
        root=xx;
    }
    bool checkIfAllLeafNodesAreAtSameLevel()
    {
        if(root==NULL)
            return false;
        queue<node*> Queue;
        Queue.push(root);
        Queue.push(NULL);
        int maximumLeafNodes=0,totalLeafNodes=0,ct=0;
        while(!Queue.empty())
        {
            node* temp=Queue.front();
            Queue.pop();

            if(temp==NULL)
            {
                if(!Queue.empty())
                {
                    Queue.push(NULL);
                }
                if(ct>maximumLeafNodes)
                    maximumLeafNodes=ct;
                ct=0;
            }
            else
            {
                if(temp->left!=NULL)
                    Queue.push(temp->left);
                if(temp->right!=NULL)
                    Queue.push(temp->right);

                if(temp->left==NULL && temp->right==NULL)
                {
                    totalLeafNodes+=1;
                    ct+=1;
                }
            }
        }

        if(maximumLeafNodes==totalLeafNodes)
            return true;
        else
            return false;
    }
    void maxRootToLeafPath(node *temp,int currentSum,int &maximumSum,vector<int> vec,vector<int> &ans)
    {
        if(temp==NULL)
        {
            if(currentSum>maximumSum)
            {
                ans.clear();
                for(int i=0; i<vec.size(); i++)
                    ans.push_back(vec[i]);
                maximumSum=currentSum;
            }
            return;
        }
        vec.push_back(temp->data);
        maxRootToLeafPath(temp->left,currentSum+temp->data,maximumSum,vec,ans);
        maxRootToLeafPath(temp->right,currentSum+temp->data,maximumSum,vec,ans);
    }
    bool isThereAPathSum(node *temp,int currentSum,int requiredSum,vector<int> vec)
    {
        if(temp==NULL || currentSum==requiredSum)
        {
            if(currentSum==requiredSum)
            {
                for(int i=0; i<vec.size(); i++)
                    cout<<vec[i]<<" ";
                cout<<"\n";
                return true;
            }
            return false;
        }
        vec.push_back(temp->data);
        return (isThereAPathSum(temp->left,currentSum+temp->data,requiredSum,vec) ||
                isThereAPathSum(temp->right,currentSum+temp->data,requiredSum,vec));
    }

    bool checkIfTwoNodesWithSum(int sum)
    {
        node *temp=root;
        queue<node*> Queue1;

        Queue1.push(root);
        while(!Queue1.empty())
        {
            node* first=Queue1.front();
            Queue1.pop();

            if(first->left!=NULL)
                Queue1.push(first->left);
            if(first->right!=NULL)
                Queue1.push(first->right);

            int elementToBeSearched=sum-first->data;
            queue<node*> Queue2;
            Queue2.push(root);
            while(!Queue2.empty())
            {
                node* second=Queue2.front();
                Queue2.pop();

                if(second->left!=NULL)
                    Queue2.push(second->left);
                if(second->right!=NULL)
                    Queue2.push(second->right);

                if(second->data == elementToBeSearched && first!=second)
                    return true;
            }
        }
        return false;
    }
    Tree()
    {
        root=NULL;
    }
};

int main()
{
    vector<int> vec,ans;
    int maximumSum=0;
    Tree tree,tree2;
    int choice=0,value=0;

    tree2.insertInBinaryTree(10);
    tree2.insertInBinaryTree(20);
    tree2.insertInBinaryTree(30);
    tree2.insertInBinaryTree(40);
    tree2.insertInBinaryTree(50);
    tree2.printTree();
    while(true)
    {
        cout<<"1.) Enter an Element\n";
        cout<<"2.) Delete Leaf Nodes\n";
        cout<<"3.) Print Tree\n";
        cout<<"4.) Exit\n";
        cout<<"5.) Delete Half Nodes\n";
        cout<<"6.) structurallyIdentically\n";
        cout<<"7.) Convert Mirror\n";
        cout<<"8.) All Nodes without Siblings (root neglected)\n";
        cout<<"9.) checkIfAllLeafNodesAreAtSameLevel\n";
        cout<<"10.) maxRootToLeafPath\n";
        cout<<"11.) isThereAPathSum\n";
        cout<<"12.) checkIfTwoNodesWithSum\n";
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
        case 6:
            cout<<"\n"<<tree.structurallyIdentically(tree2)<<"\n";
            break;
        case 7:
            tree.convertMirror();
            //tree.printTree();
            break;
        case 8:
            tree.printAllNodesWithoutSiblings();
            break;
        case 9:
            cout<<tree.checkIfAllLeafNodesAreAtSameLevel()<<"\n";
            break;
        case 10:
            tree.maxRootToLeafPath(tree.root,0,maximumSum,vec,ans);
            for(int i=0; i<ans.size(); i++)
                cout<<ans[i]<<" ";
            break;
        case 11:
            cout<<tree.isThereAPathSum(tree.root,0,300,vec)<<"\n";
            break;
        case 12:
            cout<<tree.checkIfTwoNodesWithSum(20)<<"\n";
            break;
        }
    }
    return 0;
}
