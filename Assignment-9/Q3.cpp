#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rankv[rx] < rankv[ry])
                parent[rx] = ry;
            else if (rankv[ry] < rankv[rx])
                parent[ry] = rx;
            else {
                parent[ry] = rx;
                rankv[rx]++;
            }
        }
    }
};

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int kruskal() {
        vector<tuple<int,int,int>> edges; 
        for (int u = 0; u < V; u++) {
            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;
                if (u < v) edges.push_back({w, u, v});
            }
        }

        sort(edges.begin(), edges.end());
        DSU dsu(V);

        int mst_cost = 0;
        cout << "Kruskal MST edges:\n";

        for (auto &e : edges) {
            int w, u, v;
            tie(w, u, v) = e;
            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                mst_cost += w;
                cout << u << " - " << v << " (" << w << ")\n";
            }
        }
        return mst_cost;
    }

    int prim(int start = 0) {
        vector<bool> visited(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start});

        int mst_cost = 0;
        cout << "\nPrim MST edges:\n";

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;
            mst_cost += w;

            if (w != 0)
                cout << "Pick node " << u << " with weight " << w << "\n";

            for (auto &p : adj[u]) {
                int v = p.first, wt = p.second;
                if (!visited[v]) pq.push({wt, v});
            }
        }
        return mst_cost;
    }
};

int main() {
    Graph g(5);
    
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    cout << "\nTotal cost (Kruskal): " << g.kruskal() << "\n";
    cout << "\nTotal cost (Prim): "   << g.prim()     << "\n";

    return 0;
}
