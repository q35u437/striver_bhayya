class Solution {
    public int minChanges(String s) {
        int changes = 0;
        for(int index = 0; index < s.length(); index+=2){
            if(s.charAt(index) != s.charAt(index+1)){
                changes+=1;
            }
        }
        return changes;
    }
}
