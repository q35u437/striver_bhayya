class Solution {
public:
    set<vector<int>> answer;
    void getAnswer(int cele, int csum, int size, int target, vector<int> &candidates, vector<int> &temp){
        if(cele >= size){
            if(csum == target){
                answer.insert(temp);
            }
            return;
        }else if(csum == target){
            answer.insert(temp);
            return;
        }else{
            if(csum + candidates[cele] <= target){
                temp.push_back(candidates[cele]);
                getAnswer(cele+1, csum + candidates[cele], size, target, candidates, temp);
                temp.pop_back();
            }
            while(cele < size-1 and candidates[cele] == candidates[cele+1]) cele++;
            getAnswer(cele+1, csum, size, target, candidates, temp); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        getAnswer(0, 0, candidates.size(), target, candidates, temp);
        vector<vector<int>> a(answer.begin(), answer.end());
        return a;   
    }
};
