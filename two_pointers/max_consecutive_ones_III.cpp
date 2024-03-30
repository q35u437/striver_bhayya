int longestOnes(vector<int>& nums, int k) {
    int left = 0,right = 0, length = nums.size(), maxlength = 0, total = 0;
    while(right < length){
        total+=(nums[right] == 0) ? 1 : 0;
        if(total > k){
            total += (nums[left]==0) ? -1 : 0;
            left++;
        }
        if(total <= k){
            maxlength = max(maxlength, right-left+1);
        }
        right++;
    }
    return maxlength;
}
