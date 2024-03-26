vector<int> inorderTraversal(TreeNode* root) {
    if(!root){
        return {};
    }
    stack<TreeNode*> s;
    vector<int> answer;
    TreeNode *node = root;
    while(!s.empty() or node){
        if(node!=NULL){
            s.push(node);
            node = node->left;
        }else{
            TreeNode *n = s.top();
            s.pop();
            answer.push_back(n->val);
            node = n->right;
        }
    }
    return answer;
}
