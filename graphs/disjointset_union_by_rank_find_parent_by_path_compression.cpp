//this is the implementation of disjoin union data structure
//Union by rank
//finding parent by path compression

#include<bits/stdc++.h>
using namespace std;

class disJointUnion {
    vector<int> rank;
    vector<int> parent;
public:
    disJointUnion(int size) {
        rank.resize(size+1, 0);
        parent.resize(size+1, 0);
        for(int node = 0; node <= size; node++) {
            parent[node] = node;
        }
    }

    int findUltParent(int node) {
        if(node == parent[node])
            return node;
        return (parent[node] = findUltParent(parent[node]));
    }

    void Union(int node1, int node2) {
        int node1_parent = findUltParent(node1);
        int node2_parent = findUltParent(node2);

        if(node1_parent == node2_parent) return;

        if(rank[node1_parent] < rank[node2_parent]) {
            parent[node1_parent] = node2_parent;
        }else {
            parent[node2_parent] = parent[node1_parent];
        }
    }
};

int main() {
    disJointUnion object = disJointUnion(7);

    object.Union(1, 2);
    object.Union(2, 3);
    object.Union(4, 5);
    object.Union(6, 7);
    object.Union(5, 6);
    if(object.findUltParent(3) != object.findUltParent(7)) cout<<"Not same"<<endl;
    else cout<<"Same"<<endl;
    object.Union(3, 7);
    if(object.findUltParent(3) != object.findUltParent(7)) cout<<"Not same"<<endl;
    else cout<<"Same"<<endl;
    return 0;
}
