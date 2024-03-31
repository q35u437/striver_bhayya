int maxArea(vector<int>& nums) {
    int left = 0, right = nums.size()-1,maxarea = INT_MIN;
    while(left < right){
        maxarea = max(maxarea, (right-left)*min(nums[left],nums[right]));
        if(nums[left] < nums[right])
            left++;
        else if(nums[right] < nums[left])
            right--;
        else
            right--;
    }
    return maxarea;
}
