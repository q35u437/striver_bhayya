void getRightSideView(TreeNode *root,int level,vector<int> &answer){
    if(!root){
        return;
    }
    if(level==answer.size())
        answer.push_back(root->val);
    if(root->right)
        getRightSideView(root->right,level+1,answer);
    if(root->left)
        getRightSideView(root->left,level+1,answer);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> answer;
    getRightSideView(root,0,answer);
    return answer;  
}
