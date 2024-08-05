class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int occurences = count(nums.begin(), nums.end(), 1);
        int left = 0, right = occurences-1;
        int length = nums.size();
        for(int index = 0; index < length; index++){
            nums.push_back(nums[index]);
        }
        int maybe = 0;
        for(int index = left; index <= right;index++){
            maybe += (nums[index]==0);
        }

        int answer = INT_MAX;
        while(left < length){
            while(right - left + 1 < occurences){
                right = right + 1;
                maybe += (nums[right]==0);
            }
            answer = min(answer, maybe);
            maybe -= (nums[left]==0);
            left++;
        }
        return answer;
    }
};
