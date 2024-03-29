int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0, array[256], length = s.size(), maxlength=0;
    fill(array, array + 256, -1);
    while(right < length){
        if(array[s[right]] != -1){
            if(array[s[right]] >= left){
                left = array[s[right]] + 1;
            }
        }
        maxlength = max(maxlength, right-left+1);
        array[s[right]] = right;
        right++;
    }
    return maxlength;
}
