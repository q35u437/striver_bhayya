class Solution {
    public int takeCharacters(String s, int k) {
        Map<Character,Integer> map = new HashMap<>();
        for(int index = 0; index < s.length(); index++){
            map.put(s.charAt(index), map.getOrDefault(s.charAt(index), 0)+1);
        }
        if(s.length() < k || map.getOrDefault('a', 0) < k || map.getOrDefault('b', 0) < k || map.getOrDefault('c', 0) < k){
            return -1;
        }

        int left = 0, right = 0;
        int maxwindow = 0;
        while(right < s.length()){
            map.put(s.charAt(right), map.get(s.charAt(right))-1);
            while(map.get(s.charAt(right)) < k){
                map.put(s.charAt(left), map.getOrDefault(s.charAt(left), 0)+1);
                left+=1;
            }
            maxwindow = Math.max(maxwindow, right-left+1);
            right+=1;
        }
        return s.length()-maxwindow;        
    }
}
