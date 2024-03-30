int kDistinctChars(int k, string &str)
{
    int left = 0, right = 0, maxlength = 0, length = str.size();
    map<char, int> mymap;
    while(right < length){
        mymap[str[right]]++;
        if(mymap.size() > k){
                mymap[str[left]]--;
                if(mymap[str[left]] == 0)
                    mymap.erase(str[left]);
                left++;
        }
        maxlength = max(maxlength, right-left+1);
        right++;
    }
    return maxlength;
}
