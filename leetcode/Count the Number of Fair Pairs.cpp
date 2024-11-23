class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long answer = 0;

        for(int index = 0; index < nums.size(); index++){
            int minimum = lower - nums[index];
            int maximum = upper - nums[index];

            int lindex = lower_bound(nums.begin()+index+1, nums.end(), minimum) - nums.begin();

            int rindex = upper_bound(nums.begin()+index+1, nums.end(), maximum) - nums.begin();

            rindex-=1;

            if(lindex >= 0 and rindex >= 0)
                answer += (rindex - lindex + 1);
        }


        return answer;
    }
};
