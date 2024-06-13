class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, current = 0, blue = nums.size()-1;
        while(current <= blue){
            if(nums[current] == 0){ //encountered a red so swap with it
                swap(nums[red], nums[current]);
                current += 1;
                red += 1;
            }else if(nums[current] == 2){
                swap(nums[blue], nums[current]);
                blue-=1;
            }else{
                current+=1;
            }
        }
    }
};
