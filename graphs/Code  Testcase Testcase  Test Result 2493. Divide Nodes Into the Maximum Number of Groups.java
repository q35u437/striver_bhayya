class Solution {
    public ArrayList<Integer> getAllComponents(HashMap<Integer, ArrayList<Integer>> adj, int node){
        Queue<int[]> q = new LinkedList<int[]>();
        HashMap<Integer, Integer> visited = new HashMap<Integer, Integer>();
        q.offer(new int[]{node, 1});
        visited.put(node, 1);
        while(!q.isEmpty()){
            int[] currentNode = q.poll();
            if(!adj.containsKey(currentNode[0])) continue;
            for(int neighbour : adj.get(currentNode[0])){
                if(visited.containsKey(neighbour)){
                    if(Math.abs(currentNode[1] - visited.get(neighbour)) != 1){
                        return null;
                    }
                }else{
                    q.offer(new int[]{neighbour, currentNode[1] + 1});
                    visited.put(neighbour, currentNode[1]+1);
                }
            }
        }
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int key : visited.keySet()){
            arr.add(key);
        }
        return arr;
    }
    public int getMaxGroup(HashMap<Integer, ArrayList<Integer>> adj, int node){
        Queue<Integer> q  = new LinkedList<Integer>();
        Set<Integer> visited = new HashSet<Integer>();
        int level = 0;
        q.offer(node);
        visited.add(node);
        while(!q.isEmpty()){
            int length = q.size();
            for(int i = 0; i < length; i++){
                int currentNode = q.poll();
                if(!adj.containsKey(currentNode)) continue;
                for(int neighbour : adj.get(currentNode)){
                    if(!visited.contains(neighbour)){
                        q.offer(neighbour);
                        visited.add(neighbour);
                    }
                }
            }
            level++;
        }
        return level;
    }
    public int magnificentSets(int n, int[][] edges) {
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<Integer, ArrayList<Integer>>();
        Set<Integer> visited = new HashSet<Integer>();
        for(int[] edge : edges){
            adj.putIfAbsent(edge[0], new ArrayList<Integer>());
            adj.putIfAbsent(edge[1], new ArrayList<Integer>());
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        int answer = 0;
        for(int node = 1; node <= n; node++){
            if(visited.contains(node)) continue;
            ArrayList<Integer> components = getAllComponents(adj, node);
            if(components == null) return -1;
            int maxgroup = -1;
            for(int component : components){
                visited.add(component);
                maxgroup = Math.max(maxgroup, getMaxGroup(adj, component));
            }
            answer += maxgroup;
        }
        return answer;
    }
}
