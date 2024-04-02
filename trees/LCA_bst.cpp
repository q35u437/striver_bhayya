TreeNode* getAnswer(TreeNode* root, TreeNode *p, TreeNode *q){
    if(not root){
        return NULL;
    }

    if((root->val >= p->val and root->val <= q->val) or (root->val <= p->val and root->val >= q->val)){
        return root;
    }
    if(p->val < root->val and q->val < root->val){
        return getAnswer(root->left, p, q);
    }else{
        return getAnswer(root->right,p, q);
    }
}
