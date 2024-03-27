vector <int> bottomView(Node *root) {
    if(!root){
        return {};
    }
    map<int,int> mymap;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            auto it = q.front();
            q.pop();
            mymap[it.second] = it.first->data;
            if(it.first->left){
                q.push({it.first->left,it.second-1});
            }
            if(it.first->right){
                q.push({it.first->right,it.second+1});
            }
        }
    }
    vector<int> answer;
    for(auto it : mymap){
        answer.push_back(it.second);
    }
    return answer;
}
