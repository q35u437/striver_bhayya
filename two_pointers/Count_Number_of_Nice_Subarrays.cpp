int numberOfSubarrays(vector<int>& nums, int k) {
    //k, k-1
    int left = 0, right = 0, odds = 0, length = nums.size();
    int totalx = 0;
    while(right < length){
        if(nums[right]%2)
            odds++;
        if(odds > k){
            while(odds > k){
                if(nums[left]%2)
                    odds--;
                left++;
            }
        }
        if(odds <= k)
            totalx += (right-left+1);
        right++;
    }
    left = 0, right = 0, odds = 0;
    int totaly = 0;
    while(right < length){
        if(nums[right]%2)
            odds++;
        if(odds > k-1){
            while(odds > k-1){
                if(nums[left]%2)
                    odds--;
                left++;
            }
        }
        if(odds <= k-1)
            totaly += (right-left+1);
        right++;
    }
    return totalx - totaly;
}
