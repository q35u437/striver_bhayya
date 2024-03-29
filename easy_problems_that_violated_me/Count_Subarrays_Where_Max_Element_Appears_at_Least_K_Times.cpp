long long countSubarrays(vector<int>& nums, int k) {
    //two pointers is kinda tough :(
        long long total=0,occurences = 0,left=0,right=0,length=nums.size(),maximum = *max_element(nums.begin(), nums.end());
        while(left < length){
            if(nums[left] == maximum)
                occurences++;
            while(occurences == k){
                if(nums[right] == maximum)
                    occurences--;
                right++;
            }
            total += right;
            left++;
        }
        return total;
}
