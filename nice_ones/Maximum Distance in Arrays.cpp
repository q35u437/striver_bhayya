class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi = arrays[0][arrays[0].size()-1];
        int mini = arrays[0][0];
        int res = -1e9;
        for(int i=1;i<arrays.size();i++){
            res = max(res,
                    max(maxi - arrays[i][0],
                        arrays[i][arrays[i].size()-1] - mini
                    )
            );
            maxi = max(maxi, arrays[i][arrays[i].size()-1]);
            mini = min(mini, arrays[i][0]);
        }
        return res;
    }
};
