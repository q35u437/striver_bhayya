/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int findSwaps(ArrayList<Integer> array){
        ArrayList<Integer> sorted = new ArrayList<Integer>(array);
        Collections.sort(sorted);
        HashMap<Integer, Integer> cycle = new HashMap<>();
        for(int i = 0; i < array.size(); i++){
            if(array.get(i) != sorted.get(i)){
                cycle.put(array.get(i), sorted.get(i));
            }
        }
        int answer = 0;
        for(int element : array){
            if(cycle.containsKey(element)){
                int head = element;
                int cycle_length = 0;
                while(cycle_length == 0 || head != element){
                    int previous = head;
                    head = cycle.get(head);
                    cycle.remove(previous);
                    cycle_length++; 
                }
                answer += cycle_length-1;
            }
        }
        return answer;
    }
    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        int counter = 0;
        while(!q.isEmpty()){
            int length = q.size();
            ArrayList<Integer> array = new ArrayList<Integer>();
            for(int i = 0; i < length; i++){
                TreeNode node = q.poll();
                array.add(node.val);
                if(node.left != null){
                    q.offer(node.left);
                }
                if(node.right != null){
                    q.offer(node.right);
                }
            }
            counter += findSwaps(array);
        }
        return counter;


    }
}
