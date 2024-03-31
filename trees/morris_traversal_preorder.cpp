vector<int> preorderTraversal(TreeNode* root) {
    //root left right
    vector<int> answer;
    TreeNode *current = root;
    while(current){
        if(current->left){
            TreeNode *alter = current->left;
            while(alter->right and alter->right != current){
                alter = alter->right;
            }
            if(alter->right==NULL){
                alter->right = current;
                answer.push_back(current->val); //before going left take the root value
                current = current->left; //now move to the left
            }else{
                alter->right = NULL; //remove the thread
                current = current->right; //now go to the right subtree
            }
        }else{
            answer.push_back(current->val);
            current = current->right;
        }
    }
    return answer;
}
