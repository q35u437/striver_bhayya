#include<bits/stdc++.h>
using namespace std;


int main() {
    long long n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> adj(n);

    for(long long city = 0; city < n; city++) adj[city] = {};

    for(long long route = 0; route < m; route++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1, c});
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 0});

    vector<long long> distances(n, LLONG_MAX);
    vector<long long> visited(n, 0);
    distances[0] = 0LL;

    while(!pq.empty()) {
        long long weight = pq.top().first;
        long long node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = 1;
        for(auto it : adj[node]) {
            long long n = it.first;
            long long w = it.second;
            if(distances[n] > weight + w) {
                distances[n] = weight + w;
                pq.push({distances[n], n});
            }
        }
    }

    for(long long distance : distances) {
        cout<<distance<<" ";
    }
    return 0;
}
