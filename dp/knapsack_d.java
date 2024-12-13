import java.util.Scanner;


public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        int[][] items = new int[n][2];
        for(int item = 0; item < n; item++){
            items[item][0] = sc.nextInt();
            items[item][1] = sc.nextInt();
        }
        long[][] dp = new long[w+1][n+1];
        for(int item = 1; item <= n; item++){
            for(int weight = 1; weight <= w; weight++){
                dp[weight][item] = dp[weight][item-1];
                if(weight - items[item-1][0] >= 0){
                    dp[weight][item] = Math.max(dp[weight][item], items[item-1][1] + dp[weight-items[item-1][0]][item-1]);
                }
            }
        }
        System.out.println(dp[w][n]);
    }
}
