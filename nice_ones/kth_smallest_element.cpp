//using hoares partition

int hoarePartition(vector<int> &nums, int low, int high){
    int pivot = nums[(low+high)/2];
    while(1){
        while(low <= high and nums[low] < pivot){
            low++;
        }
        while(low <= high and nums[high] > pivot){
            high--;
        }
        if(low >= high){
            return high;
        }
        swap(nums[low], nums[high]);
        low++;
        high--;
    }
}
void doQuickSortPartially(vector<int> &nums, int low, int high, int k){
    if(low < high){
        int pindex = hoarePartition(nums, low, high);
        if(pindex < k){
            doQuickSortPartially(nums, pindex+1, high, k);
        }else{
            doQuickSortPartially(nums, low, pindex, k);
        }
    }
}
int findKthLargest(vector<int>& nums, int k) {
    k = nums.size() - k;
    doQuickSortPartially(nums, 0, nums.size()-1, k);
    return nums[k];
}
