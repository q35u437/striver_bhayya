int characterReplacement(string s, int k) {
    int left = 0, right = 0, length = s.size(), maxlength = 0, maxfreq = 0;
    vector<int> frequenc(26, 0);
    while(right < length){
        frequenc[s[right]-'A']++;
        maxfreq = max(maxfreq, frequenc[s[right]-'A']);
        if((right-left+1)-maxfreq > k){
            frequenc[s[left]-'A']--;
            maxfreq = *max_element(frequenc.begin(), frequenc.end());
            left++;
        }

        if((right-left+1)-maxfreq <= k)
            maxlength = max(maxlength, right-left+1);
        right++;
    }
    return maxlength;
}
