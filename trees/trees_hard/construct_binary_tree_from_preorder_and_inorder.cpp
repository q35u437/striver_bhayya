TreeNode* getTree(vector<int> &inorder, vector<int> &preorder, map<int, int> &mymap, int instart, int inend, int prestart, int preend){
    if(instart > inend or prestart > preend){
        return NULL;
    }
    TreeNode *node = new TreeNode(preorder[prestart]);
    int numsleft = mymap[node->val] - instart;
    node->left = getTree(inorder, preorder, mymap, instart, mymap[node->val]-1,prestart+1, prestart+numsleft);
    node->right = getTree(inorder, preorder, mymap, mymap[node->val]+1, inend, prestart + numsleft + 1,preend);
    return node;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> mymap;
    int length = preorder.size();
    for(int i=0;i<length;i++){
        mymap[inorder[i]] = i;
    }
    return getTree(inorder, preorder, mymap, 0, length-1, 0, length-1);
}
