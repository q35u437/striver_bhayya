#include<bits/stdc++.h>
using namespace std;

struct FenwickTree {
private:
        int size;
        vector<vector<int>> bit;
public:
        FenwickTree(int size) {
                this->size = size;
                bit.assign(size, vector<int>(26, 0));
        }

        FenwickTree(string const &a) : FenwickTree(a.size()) {
                for(int index = 0; index < this->size; index++) {
                        bit[index][a[index] - 'a']++;
                        int r = index | index+1;
                        if(r < this->size) {
                                for(int i = 0; i < 26; i++)
                                        bit[r][i]+=bit[index][i];
                        };
                }
        }

        vector<int> frequency(int index) {
                vector<int> freq(26, 0);
                for(; index >= 0; index = (index & (index+1))-1) {
                        for(int i = 0; i < 26; i++)
                                freq[i] += this->bit[index][i];
                }
                return freq;
        }

        int query(int left, int right) {
                int answer = 0;
                vector<int> lanswer = this->frequency(left-1);
                vector<int> ranswer = this->frequency(right);

                for(int i=0;i < 26; i++) {
                        answer ^= abs(lanswer[i] - ranswer[i]);
                }
                return answer;
        }

        void update(int index, char new_value, char prev_value) {
                for(; index < this->size; index = index | (index + 1)) {
                        this->bit[index][prev_value-'a']--;
                        this->bit[index][new_value-'a']++;
                }
        }
};


int main() {
        string str;
        cin>>str;

        FenwickTree ft = FenwickTree(str);

        int q;
        cin>>q;

        while(q--) {
                int type;
                cin>>type;

                if(type==1) {
                        int left, right;
                        cin>>left>>right;
                        left-=1;
                        right-=1;
                        cout<<ft.query(left, right)<<endl;
                }else {
                        int x, y;
                        cin>>x>>y;
                        char value = ('a'+ (y-1));
                        ft.update(x-1,value,str[x-1]);
                        str[x-1] = value;
                }
        }
        return 0;
}
