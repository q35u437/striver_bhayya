int getMaxArea(vector<int> &heights){
  stack<int> s;
  int maxArea = INT_MIN, n = heights.size();
  for(int i=0;i<=n;i++){
      while(!s.empty() and (i==n or heights[s.top()] > heights[i])){
          int height = heights[s.top()];
          s.pop();
          int width;
          if(s.empty()) width = i;
          else width = i - s.top() - 1;
          maxArea = max(maxArea, height * width);
      }
      s.push(i);
  }
  return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
  vector<int> heights(matrix[0].size(), 0);
  int answer = INT_MIN;
  for(int i=0;i<matrix.size();i++){
      for(int j=0;j<matrix[0].size();j++){
          if(matrix[i][j] == '1') heights[j]++;
          else heights[j] = 0;
      }
      answer = max(answer, getMaxArea(heights));
  }
  return answer;
}
