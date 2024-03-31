int subarraySum(vector<int>& nums, int k) {
    int index = 0, prefixsum = 0, total = 0;
    map<int, int> mymap;
    mymap[prefixsum] = 1;
    while(index < nums.size()){
        prefixsum += nums[index];
        total += mymap[prefixsum-k];
        mymap[prefixsum]++;
        index++;
    }
    return total;
}
