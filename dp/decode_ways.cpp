class Solution {
public:
    int getNumberOfWays(int currentelement, int length, string s, vector<int> &dp){
        if(s[currentelement] == '0'){
            dp[currentelement]  = 0;
            return dp[currentelement];
        }else if(currentelement >= length-1){
            dp[length-1] = 1;
            return dp[length-1];
        }else if(dp[currentelement] != -1){
            return dp[currentelement];
        }else{
            int tways = 0;
            if(s[currentelement] == '1'){
                if(s[currentelement+1] == '0'){
                    tways =  getNumberOfWays(currentelement+2, length, s, dp);
                }
                tways = getNumberOfWays(currentelement+1, length, s, dp) + getNumberOfWays(currentelement+2, length, s, dp); 
            }else if(s[currentelement] == '2'){
                if(s[currentelement+1] == '0'){
                    tways = getNumberOfWays(currentelement+2, length, s, dp);
                }
                else if(s[currentelement+1] >= '1' and s[currentelement+1] <= '6'){
                    tways =  getNumberOfWays(currentelement+1, length, s, dp) + getNumberOfWays(currentelement+2, length, s, dp);             
                }else{
                    tways = getNumberOfWays(currentelement+1, length, s, dp);
                }
            }else{
                tways = getNumberOfWays(currentelement+1, length, s, dp);
            }
            dp[currentelement] = tways;
            return dp[currentelement];
        }
    }
    int numDecodings(string s) {
        int length = s.size();
        vector<int> dp(length, -1);
        return getNumberOfWays(0, length, s, dp);
    }
};
