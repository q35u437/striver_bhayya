#include<bits/stdc++.h>
using namespace std;



class disJointSetUnion {
private:
    vector<int> size;
    vector<int> parent;
public:
    disJointSetUnion(int length) {
        size.resize(length+1, 1);
        parent.resize(length+1);
        for(int node = 0; node <= length; node++) {
            parent[node] = node;
        }
    }

    int findUltParent(int node) {
        if(node == parent[node]) return node;
        return (parent[node] = findUltParent(parent[node]));
    }

    void unionBySize(int node1, int node2) {
        int node1_parent = findUltParent(node1);
        int node2_parent = findUltParent(node2);

        if(size[node1_parent] < size[node2_parent]) {
            parent[node1_parent] = node2_parent;
            size[node2_parent] += size[node1_parent];
        }else {
            parent[node2_parent] = node1_parent;
            size[node1_parent] += size[node2_parent];
        }
    }
};


int main() {
    disJointSetUnion object = disJointSetUnion(7);
    object.unionBySize(1, 2);
    object.unionBySize(2, 3);
    object.unionBySize(4, 5);
    object.unionBySize(6, 7);
    object.unionBySize(5, 6);
    if(object.findUltParent(3) != object.findUltParent(7)) cout<<"Not same"<<endl;
    else cout<<"Same"<<endl;
    object.unionBySize(3, 7);
    if(object.findUltParent(3) != object.findUltParent(7)) cout<<"Not same"<<endl;
    else cout<<"Same"<<endl;
    return 0;
}
