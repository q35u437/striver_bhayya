class Solution {
    public int getOrientation(int[] p, int[] q, int[] r){
        return (r[1] - q[1]) * (q[0] - p[0]) - ((q[1] - p[1]) * (r[0] - q[0]));
    }

    public int[][] outerTrees(int[][] trees) {

        //sort by x but if x is same then sort by y
        Arrays.sort(trees, (p, q) -> {
            return (p[0] == q[0]) ? p[1] - q[1] : p[0] - q[0];
        });

        Stack<int[]> lower = new Stack<>();
        Stack<int[]> upper = new Stack<>();

        for(int i = 0; i < trees.length; i++){
            while(lower.size() >= 2 && this.getOrientation(lower.get(lower.size()-2), lower.get(lower.size()-1),trees[i]) > 0){
                lower.pop();
            }
            while(upper.size() >= 2 && this.getOrientation(upper.get(upper.size()-2), upper.get(upper.size()-1), trees[i]) < 0){
                upper.pop();
            }
            lower.add(trees[i]);
            upper.add(trees[i]);
        }
        Set<int[]> answer = new HashSet<>(lower);
        answer.addAll(upper);
        return answer.toArray(new int[answer.size()][]);
    }
}
