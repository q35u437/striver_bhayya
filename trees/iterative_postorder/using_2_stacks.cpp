//basically what we are doing is:
//first let's consider a preorder traversal-root,left,right
//now swap left and right calls then it will be root, right, left
//now just reverse it then: left, right, root
//hoooray!!! we got postorder traversal with the help of two stacks
vector<int> postorderTraversal(TreeNode* root) {
    //using two stacks
    if(!root){
        return {};
    }
    stack<TreeNode*> s1;
    vector<int> answer;
    s1.push(root);
    while(!s1.empty()){
        TreeNode *node = s1.top();
        s1.pop();
        answer.push_back(node->val);
        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
