import java.util.Scanner;

public class Main {
    public static int getAnswer(int[] heights, int n, int[] dp, int currentposition){
        if(currentposition >= n-1){
            return 0;
        }else if(dp[currentposition] != -1) {
            return dp[currentposition];
        }else{
            int ans1=Integer.MAX_VALUE;
            if(currentposition <= n-2){
                ans1 = Math.abs(heights[currentposition]-heights[currentposition+1]) + getAnswer(heights, n, dp,currentposition+1);
            }
            if(currentposition <= n-3){
                ans1 = Math.min(ans1, Math.abs(heights[currentposition]-heights[currentposition+2]) + getAnswer(heights, n, dp, currentposition+2));
            }
            dp[currentposition] = ans1;
            return dp[currentposition];
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = new int[n];
        int[] dp = new int[n];
        for(int i = 0;i < n; i++){
            heights[i] = sc.nextInt();
            dp[i] = -1;
        }
        System.out.println(Main.getAnswer(heights,n,dp,0));
    }
}
