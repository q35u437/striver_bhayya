int majorityElement(vector<int>& nums) {
    int candidate = -1, count = 0;
    for(int i=0;i<nums.size();i++){
        if(count == 0){
            candidate = nums[i];
        }
        if(candidate == nums[i]){
            count++;
        }else{
            count--;
        }
    }
    return candidate;
}
