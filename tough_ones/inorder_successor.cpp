Node * inOrderSuccessor(Node *root, Node *x)
{
    Node *answer = NULL;
    while(root){
        if(root->data > x->data){
            answer = root;
            root = root->left;
        }else if(root->data <= x->data){
            root = root->right;
        }
    }
    return answer;
}
