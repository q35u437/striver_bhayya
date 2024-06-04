class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mymap;
        for(char ch : s){
            mymap[ch]++;
        }
        int length = 0,check = 0;
        for(auto it = mymap.begin();it!=mymap.end();it++){
            if(it->second % 2 == 0){
                length += it->second;
            }else{
                length += it->second-1;
                check = 1;
            }
        }
        return length+check;
    }
};
