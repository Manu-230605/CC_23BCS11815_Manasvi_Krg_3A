#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<pair<int,long long>> adj[100005];
long long dista[100005];
int parent[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int u,v;
        long long w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++){
        dista[i]=INF;
        parent[i]=-1;
    }

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    dista[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();

        long long d=cur.first;
        int u=cur.second;

        if(d>dista[u]) continue;

        for(auto edge:adj[u]){
            int v=edge.first;
            long long w=edge.second;

            if(dista[v] > dista[u] + w){
                dista[v] = dista[u] + w;
                parent[v] = u;
                pq.push({dista[v], v});
            }
        }
    }

    if(dista[n]==INF){
        cout << -1;
        return 0;
    }

    vector<int> path;
    for(int v=n; v!=-1; v=parent[v])
        path.push_back(v);

    reverse(path.begin(),path.end());

    for(int x:path)
        cout<<x<<" ";

    return 0;
}