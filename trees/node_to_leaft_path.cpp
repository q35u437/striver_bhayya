vector<string> answer;
void traversal(TreeNode* node, string str){
    if(!node){
        return;
    }
    if(!node->left and !node->right){
        str = str + to_string(node->val);
        answer.push_back(str);
        return;
    }
    str = str + to_string(node->val) +"->";
    if(node->left){
        traversal(node->left,str);
    }
    if(node->right){
        traversal(node->right,str);
    }
}
vector<string> binaryTreePaths(TreeNode* root) {
    traversal(root,"");
    return answer;
}
