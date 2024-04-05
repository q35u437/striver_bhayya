void getRightSmaller(vector<int> &heights, vector<int> &rightsmall){
    stack<int> s;
    s.push(heights.size()-1);
    for(int i=heights.size()-2;i>=0;i--){
        while(!s.empty() and heights[s.top()] >= heights[i]){
            s.pop();
        }
        if(s.size() == 0){
            rightsmall.push_back(heights.size()-1);
        }else{
            rightsmall.push_back(s.top()-1);
        }
        s.push(i);
    }
    reverse(rightsmall.begin(), rightsmall.end());
}

void getLeftSmaller(vector<int> &heights, vector<int> &leftsmall){
    stack<int> s;
    s.push(0);
    for(int i=1;i<heights.size();i++){
        while(!s.empty() and heights[s.top()] >= heights[i]){
            s.pop();
        }
        if(s.size() == 0){
            leftsmall.push_back(0);
        }else{
            leftsmall.push_back(s.top()+1);
        }
        s.push(i);
    }
}
int largestRectangleArea(vector<int>& heights) {
    vector<int> leftsmall,rightsmall;
    int length = heights.size();
    leftsmall.push_back(0);
    getLeftSmaller(heights, leftsmall);
    rightsmall.push_back(length-1);
    getRightSmaller(heights, rightsmall);
    int maxi = INT_MIN;
    for(int i=0;i<length;i++)
        maxi = max(maxi, (rightsmall[i]-leftsmall[i]+1)*heights[i]);
    return maxi;
}
