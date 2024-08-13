class Solution {
public:
    vector<vector<int>> answer;
    void getAnswer(int currentelement, int length, vector<int> &nums, vector<int> temp){
        if(currentelement == length){
            answer.push_back(temp);
            return;
        }else{
            temp.push_back(nums[currentelement]);
            getAnswer(currentelement+1, nums.size(), nums, temp);
            temp.pop_back();
            while(currentelement < length-1 and nums[currentelement] == nums[currentelement+1]) currentelement++;
            getAnswer(currentelement+1, nums.size(), nums, temp);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        getAnswer(0, nums.size(), nums, temp);
        return answer;
    }
};
