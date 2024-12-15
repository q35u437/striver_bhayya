import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<Integer, ArrayList<Integer>>();
        int[] indegrees = new int[n];
        for(int i = 0; i < m; i++){
            int u = sc.nextInt()-1;
            int v = sc.nextInt()-1;
            adj.putIfAbsent(u, new ArrayList<Integer>());
            adj.get(u).add(v);
            indegrees[v]++;
        }
        Queue<Integer> q = new LinkedList<Integer>();
        int[] dp = new int[n];
        for(int i = 0; i < n; i++){
            if(indegrees[i] == 0){
                q.offer(i);
                dp[i] = 0;
            }
        }

        while(!q.isEmpty()){
            int node = q.poll();
            if(!adj.containsKey(node)) continue;
            for(int neighbour : adj.get(node)){
                dp[neighbour] = Math.max(dp[neighbour], 1+dp[node]);
                indegrees[neighbour]--;
                if(indegrees[neighbour] == 0) q.offer(neighbour);
            }
        }
        System.out.println(Arrays.stream(dp).max().getAsInt());
    }
}
