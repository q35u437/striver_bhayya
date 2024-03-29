int maxSubarrayLength(vector<int>& nums, int k) {
    int length = nums.size();
    map<int, int> mymap;
    int index = 0, previndex = 0,answer=0;
    while(index < length){
        mymap[nums[index]]++;
        while(mymap[nums[index]] > k){
            mymap[nums[previndex]]--;
            previndex+=1;
        }
        answer = max(answer, index-previndex+1);
        index++;
    }       
    return answer;
}
