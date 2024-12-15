import java.util.Scanner;


public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] p = new double[n];
        for(int i = 0; i < n; i++){
            p[i] = sc.nextDouble();
        }
        double[][] dp = new double[n+1][n];
        dp[0][0] = 1-p[0];
        dp[1][0] = p[0];
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1] * (1-p[i]);
        }

        for(int i = 1;i < n; i++){
            for(int j = 1; j <= n; j++){
                dp[j][i] = p[i]*dp[j-1][i-1] + (1-p[i]) * dp[j][i-1];
            }
        }

        double answer = 0.0;
        for(int index = n/2 + 1; index <= n; index++){
            answer += dp[index][n-1];
        }
        System.out.println(answer);
    }
}
