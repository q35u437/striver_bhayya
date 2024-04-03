void getInorder(TreeNode *root, vector<int> &inorder){
    if(!root){
        return;
    }

    getInorder(root->left, inorder);
    inorder.push_back(root->val);
    getInorder(root->right, inorder);
}
bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    getInorder(root, inorder);
    int left = 0, right = inorder.size()-1;
    while(left<right){
        if(inorder[left] + inorder[right] > k){
            right--;
        }else if(inorder[left] + inorder[right] < k){
            left++;
        }else{
            return true;
        }
    }
    return false;
}
