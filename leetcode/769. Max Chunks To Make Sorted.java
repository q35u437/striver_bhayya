class Solution {
    public int maxChunksToSorted(int[] arr) {
        //monotonic stack
        Stack<Integer> st = new Stack<Integer>();
        st.add(-1);
        for(int index = 0; index < arr.length; index++){
            //can create a chunk with this new maximum element
            if(st.peek() < arr[index]){
                st.push(arr[index]);
            }else{
                int maxi = st.peek();
                while(st.size() > 1 && st.peek() > arr[index]){
                    st.pop();
                }
                st.add(maxi);
            }
        }
        return st.size()-1;
    }
}
