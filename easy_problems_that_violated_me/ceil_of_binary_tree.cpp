int findCeil(Node* root, int input) {
    int ceil = -1;
    while(root){
        if(root->data > input){
            ceil = root->data;
            root = root->left;
        }else if(root->data < input){
            root = root->right;
        }else{
            ceil = root->data;
            break;
        }
    }
    return ceil;
}
