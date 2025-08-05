class SegmentTree{
    public:
        vector<int> tree;
        int length;

        public:
            SegmentTree(const vector<int> &array){
                length = array.size();
                tree.resize(4*length);
            }

            void build(int left, int right, int index, const vector<int> &arr){
                if(left == right){
                    tree[index] = arr[left];
                    return;
                }
                int middle = (left + right) / 2;
                build(left, middle, 2 * index + 1, arr);
                build(middle + 1, right, 2 * index + 2, arr);
                tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
            }

            int query(int low, int high, int fruit_value, int index){
                if(tree[index] < fruit_value) return -1;
                if(low == high) return low;
                int middle = (low + high) / 2;
                int left = query(low, middle, fruit_value, 2 * index + 1);
                if(left != -1) return left;
                return query(middle + 1, high, fruit_value, 2 * index + 2);
            }

            void update(int low, int high, int position_to_update, int index){
                if(low == high){
                    tree[index] = -1;
                    return;
                }
                int middle = (low + high) / 2;
                if(position_to_update > middle){
                    update(middle+1, high, position_to_update, 2 * index + 2);
                }else{
                    update(low, middle, position_to_update, 2 * index + 1);  
                }
                tree[index] = max(tree[2*index+1], tree[2*index+2]);
            }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree st(baskets);
        st.build(0, baskets.size()-1, 0, baskets);
        int answer = 0;
        for(int fruit : fruits){
            int index = st.query(0, baskets.size()-1, fruit, 0);
            cout<<index<<endl;
            if(index == -1){
                answer++;
            }else{
                st.update(0, baskets.size()-1, index, 0);
            }
        }
        return answer;
    }
};
