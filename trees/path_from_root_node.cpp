bool getPath(TreeNode *root, vector<int> &answer, int value){
	if(!root){
		return false;
	}

	answer.push_back(root->val);
	if(root->val==value){
		return true;
	}
	
	if(getPath(root->left,answer,value) or getPath(root->right,answer,value)){
		return true;
	}

	answer.pop_back();
	return false;
}


vector<int> Solution::solve(TreeNode *A, int B){
	vector<int> arr;
	if(!A){
		return {};
	}
	getPath(A,arr,B);
	return arr;
}
