import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        sc.nextLine();
        String[] grid = new String[h];
        for(int i = 0; i < h; i++){
            grid[i] = sc.nextLine();
        }
        long[][] dp = new long[h][w];
        dp[0][0] = 0;
        for(int i = 1; i < w; i++){
            if(grid[0].charAt(i) == '#') break; dp[0][i] = 1;
        }
        for(int i = 1; i < h; i++){
            if(grid[i].charAt(0) == '#') break; dp[i][0] = 1;
        }

        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++){
                if(grid[i-1].charAt(j) == '.')
                    dp[i][j] = dp[i-1][j] % 1000000007L;
                if(grid[i].charAt(j-1) == '.')
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007L;
            }
        }

        System.out.println(dp[h-1][w-1]);
    }
}
