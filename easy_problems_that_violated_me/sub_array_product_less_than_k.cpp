int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int total=0,left = 0,right = 0,s = 1,length = nums.size();
    while(left <= right and left < length and right < length){
        s *= nums[right];
        if(s < k){
            total += (right - left + 1);
        }else{
            while(s>=k and left <= right and left < length){
                s = s /  nums[left];
                left++;
            }
            if(s < k)
                total += (right-left+1);
        }
        right++;
    }
    return total;
}
