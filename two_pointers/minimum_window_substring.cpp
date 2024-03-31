string minWindow(string s, string t) {
    int left = 0, right = 0, length = s.size(), leftind = -1, rightind = -1, minlength = INT_MAX,count = 0;
    map<char, int> mymap;
    for(char i : t)
        mymap[i]++;
    while(right < length){
        if(mymap[s[right]] > 0){
            count++;
        }
        mymap[s[right]]--;
        while(count == t.size()){
            if(minlength > right-left+1){
                minlength = right-left+1;
                leftind = left;
                rightind = right;
            }
            mymap[s[left]]++;
            if(mymap[s[left]] > 0) count--;
            left++;
        }
        right++;
    }
    if(leftind == -1 and rightind ==-1)
        return "";
    return s.substr(leftind, rightind-leftind+1);
}
