class Solution {
    public long countBadPairs(int[] nums) {
        HashMap<Integer, Long> counter = new HashMap<Integer, Long>();
        for(int index = 0; index < nums.length; index++){
            counter.put(nums[index] - index, counter.getOrDefault(nums[index]-index, 0L)+1L);
        }
        Long badPairs = (((long)nums.length) * (nums.length-1))/2;
        for(HashMap.Entry<Integer, Long> entry : counter.entrySet()){
            if(entry.getValue() >= 2){
                badPairs-=((entry.getValue() * (entry.getValue()-1))/2);
            }
        }
        return badPairs;
    }
}
