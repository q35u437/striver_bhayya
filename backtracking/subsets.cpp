class Solution {
public: 
    void getAnswer(int currentelement, int length, vector<vector<int>> &answer, vector<int> temp, vector<int> &nums){
        if(currentelement == length){
            answer.push_back(temp);
            return;
        }else{
            temp.push_back(nums[currentelement]);
            getAnswer(currentelement+1, length, answer, temp, nums);
            temp.pop_back();
            getAnswer(currentelement+1, length, answer, temp, nums);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> temp;
        getAnswer(0, nums.size(), answer, temp, nums);
        return answer;
    }
};
