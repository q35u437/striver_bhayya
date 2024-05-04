class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0, right = people.size()-1;
        int total = 0;
        sort(people.begin(), people.end());
        while(left <= right){
            if(people[left] + people[right] <= limit){
                total++;
                left++;
                right--;
            }else{
                total++;
                right--;
            }
        }
        return total;
    }
};
