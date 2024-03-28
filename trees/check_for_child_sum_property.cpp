bool check(Node *node){
    if(!node){
        return true;
    }
    int l = 0,r = 0;
    if(!node->left and !node->right){
        l = node->data;
    }
    if(node->left)
        l = node->left->data;
    if(node->right)
        r = node->right->data;
    return (node->data == (l+r)) and check(node->left) and check(node->right);
}
int isSumProperty(Node *root)
{
    return check(root);
}
