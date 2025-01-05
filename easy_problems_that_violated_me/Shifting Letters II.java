class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        StringBuilder sb = new StringBuilder(s);
        int[] prefix_array = new int[s.length()+1];
        for(int[] shift : shifts){
            int left = shift[0];
            int right = shift[1];
            int direction = shift[2];
            prefix_array[right+1] += (direction == 1) ? 1 : -1;
            prefix_array[left] += (direction == 1) ? -1 : 1;
        }
        int total = 0;
        for(int i = s.length(); i >= 1; i--){
            total += prefix_array[i];
            sb.setCharAt(i-1,(char)('a' + (((((sb.charAt(i - 1) - 'a') + total) % 26) + 26) % 26)));
        }
        return sb.toString();
    }
}
