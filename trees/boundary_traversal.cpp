//submission to this problem is made preimum in leetcode. so it is better to submit it in GFG

bool isLeaf(Node *node){
    if(!node->left and !node->right){
        return true;
    }
    return false;
}
void addLeftBoundary(Node *node, vector<int> &answer){
    if(!node){
        return;
    }
    if(!isLeaf(node)){
        answer.push_back(node->data);
        if(node->left)
            addLeftBoundary(node->left, answer);
        else
            addLeftBoundary(node->right, answer);
    }else{
        return;
    }
}
void addLeafs(Node *node, vector<int> &answer){
    if(!node){
        return;
    }
    addLeafs(node->left, answer);
    if(isLeaf(node))
        answer.push_back(node->data);
    addLeafs(node->right, answer);
}
void addRightBoundary(Node *node, vector<int> &answer){
    if(!node){
        return;
    }
    if(!isLeaf(node)){
        answer.push_back(node->data);
        if(node->right){
            addRightBoundary(node->right, answer);
        }else{
            addRightBoundary(node->left, answer);
        }
    }else{
        return;
    }
}
vector <int> boundary(Node *root){
    if(!root){
        return {};
    }
    vector<int> answer,temp;
    if(!isLeaf(root)){
        answer.push_back(root->data); //edge case
    }  
    addLeftBoundary(root->left,answer);
    addLeafs(root,answer);
    addRightBoundary(root->right,temp);
    for(int i=temp.size()-1;i>=0;i--)
        answer.push_back(temp[i]);
    return answer;
}
