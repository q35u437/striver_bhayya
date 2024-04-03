//this BSTIterator is very important AF
//moreover this can be easily done by getting inorder and applying two pointer method also
class BSTIterator{
    private:
        stack<TreeNode *> s;
        bool reverse = true;

    public:
        BSTIterator(TreeNode *root, bool reverse){
            this->reverse = reverse;
            this->pushAll(root);
        }
        void pushAll(TreeNode *root){
            while(root){
                if(reverse){
                    s.push(root);
                    root = root->right;
                }else{
                    s.push(root);
                    root = root->left;
                }
            }
        }

        int next(){
            TreeNode *node = s.top();
            s.pop();
            if(this->reverse){
                this->pushAll(node->left);
            }else{
                this->pushAll(node->right);
            }
            return node->val;
        }

        int hasNext(){
            return !s.empty();
        }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
