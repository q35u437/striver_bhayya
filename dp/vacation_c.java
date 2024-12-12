import java.util.Scanner;


public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] info = new int[n][3];
        for(int i = 0; i < n; i++){
            info[i][0] = sc.nextInt();
            info[i][1] = sc.nextInt();
            info[i][2] = sc.nextInt();
        }
        int[][] dp = new int[n][3];
        dp[0][0] = info[0][0];
        dp[0][1] = info[0][1];
        dp[0][2] = info[0][2];

        for(int i=1;i<n;i++){
            dp[i][0] = info[i][0] + Math.max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = info[i][1] + Math.max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = info[i][2] + Math.max(dp[i-1][0], dp[i-1][1]);
        }
        System.out.println(Math.max(dp[n-1][0], Math.max(dp[n-1][1], dp[n-1][2])));
    }
}
