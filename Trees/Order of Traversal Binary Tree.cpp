/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void preOrder(node *root) {
    if(root== NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root) {
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(node *root) {
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
