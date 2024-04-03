TreeNode* getPredecessor(TreeNode *root, TreeNode *node){
	TreeNode *current = NULL;
	while(root){
		if(root->val >= node->val){
			root = root->left;
		}else if(root->val < node->val){
			current = root;
			root = root->right;
		}
	}
	return current;
}
