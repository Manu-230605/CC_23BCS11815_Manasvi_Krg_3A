#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; 


int prims(int V, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(V, false);

    pq.push({0, 0}); 
    int totalWeight = 0;

    while (!pq.empty()) {
        pii temp = pq.top();
        pq.pop();

        int wt = temp.first;
        int node = temp.second;

        if (visited[node]) continue;

        visited[node] = true;
        totalWeight += wt;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (!visited[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return totalWeight;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    cout << "MST Total Weight: " << prims(V, adj);

    return 0;
}