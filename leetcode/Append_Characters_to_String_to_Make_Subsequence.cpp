class Solution {
public:
    int appendCharacters(string s, string t) {
        int sindex = 0, tindex = 0;
        while(sindex < s.size() and tindex < t.size()){
            if(s[sindex] == t[tindex]){
                tindex+=1;
            }
            sindex+=1;
        }
        return t.size() - tindex;
    }
};
