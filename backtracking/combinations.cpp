class Solution {
public:
    void getAnswer(int currentelement, int currentsum, int target, vector<int> &candidates, vector<vector<int>> &answer, vector<int> &temp){
        if(currentelement >= candidates.size()){
            if(currentsum == target){
                answer.push_back(temp);
            }
            return;
        }else if(currentsum == target){
            answer.push_back(temp);
            return;
        }else{
            if(currentsum + candidates[currentelement] <= target){
                temp.push_back(candidates[currentelement]);
                getAnswer(currentelement, currentsum + candidates[currentelement], target, candidates, answer, temp);
                temp.pop_back();
            }
                getAnswer(currentelement+1, currentsum, target, candidates, answer, temp);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> temp;
        getAnswer(0, 0, target, candidates, answer, temp);
        return answer;
    }
};
