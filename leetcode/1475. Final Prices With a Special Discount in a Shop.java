class Solution {
    public int[] finalPrices(int[] prices) {
        Stack<Integer> st = new Stack<Integer>();
        st.push(0);
        for(int i = 0; i < prices.length; i++){
            if(prices[st.peek()] < prices[i]){
                st.push(i);
            }else{
                while(st.size() > 1 && prices[st.peek()] >= prices[i]){
                    prices[st.pop()] -= prices[i];
                }
                st.push(i);
            }
        }
        return prices;
    }
}
