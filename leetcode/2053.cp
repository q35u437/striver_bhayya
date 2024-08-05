class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mymap;
        for(string value : arr){
            mymap[value]++;
        }

        for(string value : arr){
            if(mymap[value] == 1){
                k--;
                if(not k){
                    return value;
                }
            }
        }
        return "";
    }
};
