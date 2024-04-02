int answer;
void getKthSmallest(TreeNode *root, int k, int &counter){
    if(!root){
        return;
    }

    if(root->left){
        getKthSmallest(root->left, k, counter);
    }
    if(++counter == k){
        answer = root->val;
    }
    if(root->right){
        getKthSmallest(root->right, k, counter);
    }
}
int kthSmallest(TreeNode* root, int k) {
    int counter = 0;
    getKthSmallest(root, k, counter);
    return answer;
}
