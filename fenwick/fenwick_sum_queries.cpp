#include<bits/stdc++.h>
using namespace std;


struct FenwickTree {
    vector<int> bit; //binary indexed array
    int size;

    FenwickTree(int size) {
        this->size = size;
        this->bit.assign(size, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for(int i = 0; i < this->size; i++) {
            this->bit[i] += a[i];
            int r = i | (i + 1);
            if(r < this->size) this->bit[r] += this->bit[i];
        }
    }

    int query(int index) {
        int answer = 0;
        for(; index >= 0; index = (index & (index+1)) - 1) {
            answer += this->bit[index];
        }
        return answer;
    }

    void update(int index, int value) {
        //NOTE: here the value means how much extra has been added
        //Example: if intially it was 4 and we updated to 6 then extra 2 was added. So, value should
        //be 2 NOT 6.
        for(; index < this->size; index = index | (index + 1)) {
            this->bit[index] += value;
        }
    }

    int sum(int left, int right) {
        return this->query(right) - this->query(left-1);
    }
};
