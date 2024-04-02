int floor(Node* root, int x) {
    int floor = -1;
    while(root){
        if(root->data < x){
            floor = root->data;
            root = root->right;
        }else if(root->data > x){
            root = root->left;
        }else{
            floor = root->data;
            break;
        }
    }
    return floor;
}
