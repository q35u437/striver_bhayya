/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void doBFS(TreeNode *root, vector<long long> &level_sum){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int length = q.size();
            long long sum = 0;
            for(int i=0;i<length;i++){
                sum += q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            level_sum.push_back(sum);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level_sum;
        doBFS(root, level_sum);
        sort(level_sum.begin(), level_sum.end(), greater<long long>());
        if(k > level_sum.size())
            return -1;
        return level_sum[k-1];
    }
};
