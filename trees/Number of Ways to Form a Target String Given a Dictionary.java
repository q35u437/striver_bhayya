class Solution {
    public int numWays(String[] words, String target) {
        int r = target.length();
        int c = words[0].length();
        int[][] dp = new int[r][c];
        int[][] col_freq = new int[c][26];

        for(int column = 0; column < c; column++){
            for(int row = 0; row < words.length; row++){
                col_freq[column][words[row].charAt(column)-'a']++;
            }
        }
        dp[0][0] = col_freq[0][target.charAt(0)-'a'];
        for(int col = 1; col < c; col++){
            dp[0][col] = (dp[0][col-1] + col_freq[col][target.charAt(0)-'a']);
        }
        for(int i = 1; i < c; i++){
            for(int j = 1; j < r; j++){
                long answer = (dp[j][i-1]);
                answer += (dp[j-1][i-1] * (long)col_freq[i][target.charAt(j)-'a']);
                dp[j][i] = (int)(answer % 1000000007L);
            }
        }        
        return dp[r-1][c-1];
    }
}
