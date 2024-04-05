int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxi = INT_MIN, n = heights.size();
    for(int i=0;i<=n;i++){
        while(!st.empty() and (i==n or heights[st.top()] > heights[i])){
            int height = heights[st.top()];
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;
            maxi = max(maxi, height*width);
        }
        st.push(i);
    }
    return maxi;
}
