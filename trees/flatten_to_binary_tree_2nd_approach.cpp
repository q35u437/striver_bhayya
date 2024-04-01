void flatten(TreeNode* root) {
    if(!root){
        return;
    }
    stack<TreeNode *> st;
    st.push(root);
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        if(node->right){
            st.push(node->right);
        }

        if(node->left){
            st.push(node->left);
        }

        if(!st.empty()){
            node->right = st.top();
        }
        node->left = NULL;
    }
}
