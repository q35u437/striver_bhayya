class Solution {
public:
    int find(int index, vector<int> &parent) {
        if (parent[index] != index) {
            parent[index] = find(parent[index], parent); // Path compression
        }
        return parent[index];
    }

    void onion(int a, int b, vector<int> &parent) {
        int rootA = find(a, parent);  // Find root of node a
        int rootB = find(b, parent);  // Find root of node b

        if (rootA != rootB) {
            parent[rootA] = rootB;  // Union: set root of component containing a to root of component containing b
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int length = s.size();
        vector<int> parent(length, 0);
        for(int node = 0; node < length; node++){
            parent[node] = node;
        }
        for(auto it : pairs){
            onion(it[0], it[1], parent);
        }

        vector<int> roots(length);
        for(int index = 0; index < length; index++){
            roots[index] = find(index, parent);
        }
        // after getting all the connected components now we have to sort these
        unordered_map<int, vector<int>> mymap;
        for(int index = 0; index < length; index++){
            if(mymap.count(roots[index])){
                mymap[roots[index]].push_back(index);
            }else{
                mymap[roots[index]] = {index};
            }
        }

        for(auto it = mymap.begin(); it != mymap.end(); it++){
            string result = "";
            for(int index : it->second){
                result += s[index];
            }
            sort(result.begin(), result.end());
            int counter = 0;
            for(int index : it->second){
                s[index] = result[counter];
                counter++;
            } 
        }
        return s;
        
        return "ads";
    }
};
