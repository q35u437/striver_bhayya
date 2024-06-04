class Solution {
public:
    int appendCharacters(string s, string t) {
        int tindex = 0, sindex = 0;
        for(;tindex < t.size(); tindex++){
            while(s[sindex] != t[tindex] and sindex < s.size())
                sindex++;
            if(sindex == s.size()){
                return t.size() - tindex;
            }
            sindex++;
        }
        return t.size() - tindex;
    }
};
