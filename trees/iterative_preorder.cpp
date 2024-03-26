vector<int> preorderTraversal(TreeNode* root) {
    //iterative approach
    //first take the root value and then put the right child into stack and then put left child into stack
    //why right child first because since stack is LIFO if put (right, left) then we will end up accessing left first
    if(!root){
        return {};
    }
    vector<int> answer;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* noed = s.top();
        s.pop();
        answer.push_back(noed->val);
        if(noed->right)
            s.push(noed->right);
        if(noed->left)
            s.push(noed->left);
    }
    return answer;
}
