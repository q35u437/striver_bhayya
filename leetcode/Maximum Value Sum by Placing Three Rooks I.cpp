class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        vector<pair<int, pair<int, int>>> vec;

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                vec.push_back({board[r][c], {r, c}});
            }
        }

        sort(vec.begin(), vec.end(), greater<>());

        long long answer = LLONG_MIN;

        int length = vec.size();

        vector<pair<long long, pair<int, int>>> combos;

        vector<int> cc(board.size(), 0);

        for(int index = 0; index < length; index++){
            auto it = vec[index];
            int board_value = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(cc[r] < 3){
                combos.push_back({board_value, {r, c}});
                cc[r]++;
            }
        }
        for(int i = 0; i < combos.size(); i++){
            pair<int, int> elephant1 = combos[i].second;
            for(int j = i + 1; j < combos.size(); j++){ 
                pair<int, int> elephant2 = combos[j].second;
                if(elephant1.first == elephant2.first or elephant1.second == elephant2.second){
                    continue;
                }
                for(int k = j + 1; k < combos.size(); k++){
                    pair<int, int> elephant3 = combos[k].second;                    
                    if(elephant1.first == elephant3.first or elephant1.second == elephant3.second or elephant2.first == elephant3.first or elephant2.second == elephant3.second){
                        continue;
                    }
                    answer = max(answer, combos[i].first + combos[j].first + combos[k].first);
                }
            }
        }
        return answer;
    }
};
