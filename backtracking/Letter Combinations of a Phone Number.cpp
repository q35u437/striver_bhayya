class Solution {
public:
    map<char, vector<char>> mymap = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    void getAnswer(int cele, int length, string &digits, vector<string> &answer, string ans){
        if(cele == length){
            if(ans.size())
                answer.push_back(ans);
            return;
        }

        for(auto it : mymap[digits[cele]]){
            getAnswer(cele+1, length, digits, answer, ans + it);
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        getAnswer(0, digits.size(), digits, answer, "");        
        return answer;
    }
};
