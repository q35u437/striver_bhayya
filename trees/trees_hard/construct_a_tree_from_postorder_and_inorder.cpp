TreeNode* getTree(vector<int> &inorder, vector<int> &postorder, map<int, int> &mymap, int instart, int inend, int poststart, int postend){
    if(instart > inend or poststart > postend){
        return NULL;
    }
    TreeNode* node = new TreeNode(postorder[postend]);
    int numsleft = mymap[node->val] - instart;
    int numsright = inend - mymap[node->val];
    node->left = getTree(inorder, postorder, mymap, instart, mymap[node->val]-1, poststart, poststart+numsleft-1);
    node->right = getTree(inorder, postorder, mymap, mymap[node->val]+1, inend, postend - numsright ,postend-1);
    return node;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> indeces;
    int length = inorder.size();
    for(int i=0;i<length;i++)
        indeces[inorder[i]] = i;
    return getTree(inorder,postorder,indeces,0,length-1,0,length-1);
}
