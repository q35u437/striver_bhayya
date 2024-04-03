class Information{
    public:
        int leftMaxNode, rightMinNode, size;
        Information(int l1, int l2, int s){
            this->leftMaxNode = l1;
            this->rightMinNode = l2;
            this->size = s;
        }
};

class Solution{
    public:
    Information getAnswer(Node *root){
        if(!root){
            return Information(INT_MIN, INT_MAX, 0);
        }
        
        auto leftans = getAnswer(root->left);
        auto rightans = getAnswer(root->right);
        if(leftans.leftMaxNode < root->data and rightans.rightMinNode > root->data){
            return Information(max(rightans.leftMaxNode, root->data),min(leftans.rightMinNode, root->data),leftans.size+rightans.size+1);
        }
        return Information(INT_MAX, INT_MIN, max(leftans.size, rightans.size));
    }
    int largestBst(Node *root)
    {
        return getAnswer(root).size;
    }
};
