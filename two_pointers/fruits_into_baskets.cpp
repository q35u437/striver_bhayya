int totalFruit(vector<int>& fruits) {
    int left = 0, right = 0, length = fruits.size(), maxlength = 0;
    map<int, int> frequency;
    while(right < length){
        frequency[fruits[right]]++;
        if(frequency.size() > 2){
            while(frequency.size() > 2){
                frequency[fruits[left]]--;
                if(frequency[fruits[left]] == 0)
                    frequency.erase(fruits[left]);
                left++;
            }
        }
        maxlength = max(maxlength, right-left+1);
        right++;
    }
    return maxlength;
}
