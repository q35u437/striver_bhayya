int widthOfBinaryTree(TreeNode* root) {
    int width = INT_MIN;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    while(!q.empty()){
        int length = q.size();
        int first,last;
        for(int i=0;i<length;i++){
            if(i==0) first = q.front().second;
            if(i==length-1) last = q.front().second;
            auto it = q.front();
            q.pop();
            if(it.first->left)
                q.push({it.first->left, 2*(it.second-first)+1});
            if(it.first->right)
                q.push({it.first->right, 2*(it.second-first)+2});
        }
        width = max(width,last-first+1);
    }
    return width;
}
