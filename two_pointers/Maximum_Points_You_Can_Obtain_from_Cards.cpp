int maxScore(vector<int>& nums, int k) {
    int left = k-1,right = nums.size();
    int sum = 0;
    for(int i=0;i<=left;i++)
        sum+=nums[i];
    int answer = sum;
    while(left >= 0){
        sum -= nums[left];
        left-=1;
        right-=1;
        sum += nums[right];
        answer = max(answer, sum);
    }
    return answer;
}
