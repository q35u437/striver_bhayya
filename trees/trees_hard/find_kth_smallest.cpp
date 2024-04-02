//if they ask for kth largest it is same as finding n-k+1 smallest
int kthSmallest(TreeNode* root, int k) {
    int answer = -1;
    int counter = 0;
    TreeNode *current = root;
    while(current){
        if(!current->left){
            if(++counter == k){
                answer = current->val;
            }
            current = current->right;
        }else{
            TreeNode* previous = current->left;
            while(previous->right and previous->right != current){
                previous = previous->right;
            }
            if(previous->right==NULL){
                previous->right  = current;
                current = current->left;
            }else{
                previous->right = NULL;
                if(++counter == k){
                    answer = current->val;
                }
                current = current->right;
            }
        }
    }
    return answer;
}
