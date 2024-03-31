int numSubarraysWithSum(vector<int>& nums, int k) {
    int left = 0, right = 0, length = nums.size(), tx = 0;
    int sum = 0;
    while(right < length){
        sum += nums[right];
        if(sum > k){
            while(sum > k){
                sum -= nums[left];
                left++;
            }
        }
        if(sum <= k){
            tx += (right-left+1);
        }
        right++;
    }
    if(k == 0)
        return tx;
    sum = 0,left = 0, right = 0;
    int ty = 0;
    while(right < length){
        sum += nums[right];
        if(sum > k-1){
            while(sum > k-1){
                sum -= nums[left];
                left++;
            }
        }
        if(sum <= k-1){
            ty += (right-left+1);
        }
        right++;
    }
    return tx-ty;
}
