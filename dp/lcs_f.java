import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t =  sc.nextLine();
        int[][] dp = new int[t.length()+1][s.length()+1];
        for(int i = 0; i <= t.length(); i++){
            for(int j = 0; j <= s.length(); j++){
                dp[i][j] = 0;
            }
        }

        for(int i = 1; i <= t.length(); i++){
            for(int j = 1; j <= s.length(); j++) {
                if (s.charAt(j-1) == t.charAt(i-1)){
                    dp[i][j]= dp[i-1][j-1] + 1;
                }else {
                        dp[i][j] = (Math.max(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        StringBuilder answer = new StringBuilder();
        for(int i = s.length(), j = t.length(); i > 0 && j > 0;){
            if(s.charAt(i-1) == t.charAt(j-1)){
                answer.append(s.charAt(i-1));
                i--;
                j--;
            }else if(dp[j-1][i] >= dp[j][i-1]){
                j--;
            }else{
                i--;
            }
        }
        System.out.println(answer.reverse());
    }
}
