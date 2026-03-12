#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void dijkstra(int V, vector<pair<int,int>> adj[], int src) {
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, INF);

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for(int i = 0; i < V; i++) {
        cout << i << " \t " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<pair<int,int>> adj[V];

    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({0, 7});
    adj[3].push_back({2, 6});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    dijkstra(V, adj, 0);

    return 0;
}