int lengthOfLongestSubstring(string s) {
    int left = 0,right = 0, maxlength = 0, length = s.size();
    set<char> st;
    while(right < length){
        if(st.count(s[right])){
            st.erase(s[left]);
            left++;
        }
        if(st.count(s[right]))
            continue;
        st.insert(s[right]);
        maxlength = max(maxlength, right-left+1);
        right++;
    }
    return maxlength;
}
