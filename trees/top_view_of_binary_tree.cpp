//somehow GFG has the best binary trees questions than leetcode

vector<int> topView(Node *root)
{
    if(!root){
        return {};
    }
    map<int,int> mymap;
    queue<pair<int,Node*>> q;
    q.push({0, root});
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            auto it = q.front();
            q.pop();
            if(mymap.count(it.first)==0){
                mymap[it.first] = it.second->data;
            }
            if(it.second->left){
                q.push({it.first-1,it.second->left});
            }
            
            if(it.second->right){
                q.push({it.first+1,it.second->right});
            }
        }
    }
    vector<int> answer;
    for(auto it=mymap.begin();it!=mymap.end();it++){
        answer.push_back(it->second);
    }
    return answer;
}
