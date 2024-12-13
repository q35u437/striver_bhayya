import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        int[][] items = new int[n][2];
        int sum = 0;
        for(int i=0;i<n;i++){
            items[i][0] = sc.nextInt();
            items[i][1] = sc.nextInt();
            sum += items[i][1];
        }
        long[][] dp = new long[sum+1][n+1];
        for(int value = 0; value <= sum; value++){
            for(int item = 0; item <= n; item++)
                dp[value][item] = Long.MAX_VALUE;
        }
        for(int item=0;item<=n;item++){
            dp[0][item] = 0L;
        }
        for(int item = 1; item <= n; item++){
            for(int value = 1; value <= sum; value++){
                dp[value][item] = dp[value][item-1];
                if(value - items[item-1][1] >= 0 && dp[value - items[item-1][1]][item-1] != Long.MAX_VALUE){
                    dp[value][item] = Math.min(dp[value][item], items[item-1][0] + dp[value - items[item-1][1]][item-1]);
                }
            }
        }
        for(int value = sum; value >= 0; value--){
            if(dp[value][n] <= w) {
                System.out.println(value);
                break;
            }
        }
    }
}
