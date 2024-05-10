class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if(l1%2 == 0 and l2%2 == 0){
            return 0;
        }else{
            int la = 0;
            for(int value : nums1){
                la ^= value;
            }
            int lb = 0;
            for(int value : nums2){
                lb ^= value;
            }
            if(l1%2 and l2%2 == 0){
                return lb;
            }else if(l1%2 == 0 and l2%2){
                return la;
            }else{
                return la^lb;
            }
        }
    }
};
