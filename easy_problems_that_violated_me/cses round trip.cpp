#include<bits/stdc++.h>
using namespace std;

class RoundTrip {
private:
    int n, m;
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> parent;
    bool cycle;
public:
    RoundTrip(int n, int m) {
        this->n = n;
        this->m = m;
        adj.resize(n);
        visited.assign(n, 0);
        parent.assign(n, -1);
        cycle = false;
    }
    void getInput() {
        for(int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    void solve() {
        for(int i=0;i<n;i++) {
            if(visited[i]) continue;
            if(dfs(i, -1)) return;
        }
        cout<<"IMPOSSIBLE"<<endl;
    }

    void printCycle(vector<int> &cycle) {
        cout<<cycle.size()<<endl;
        for(int i : cycle)
            cout<<i+1<<" ";
    }

    bool dfs(int node, int papa) {
        visited[node] = 1;
        parent[node] = papa;

        for(int neighbour : adj[node]) {
            if(neighbour == papa) continue;

            if(visited[neighbour]) {
                vector<int> cycle;
                int curr = node;
                while(curr != neighbour) {
                    cycle.push_back(curr);
                    curr = parent[curr];
                }
                cycle.push_back(neighbour);
                cycle.push_back(node);
                printCycle(cycle);
                return true;
            }
            if(dfs(neighbour, node)) return true;
        }
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    RoundTrip rt = RoundTrip(n, m);
    rt.getInput();
    rt.solve();
    return 0;
}
