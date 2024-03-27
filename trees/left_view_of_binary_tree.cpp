void getLeftView(Node *root, int level, vector<int> &answer){
    if(!root){
        return;
    }
    if(level==answer.size())
        answer.push_back(root->data);
    if(root->left)
        getLeftView(root->left,level+1,answer);
    if(root->right)
        getLeftView(root->right,level+1,answer);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> answer;
    getLeftView(root,0,answer);
    return answer;
}
