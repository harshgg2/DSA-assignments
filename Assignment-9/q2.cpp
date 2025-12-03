#include <iostream>
#include <vector>
using namespace std;

void explore(int node, const vector<vector<int>> &g, vector<int> &seen, vector<int> &path) {
    seen[node] = 1;
    path.push_back(node);

    for (int nxt : g[node]) {
        if (!seen[nxt]) {
            explore(nxt, g, seen, path);
        }
    }
}

vector<int> dfsStart(const vector<vector<int>> &g, int startNode) {
    vector<int> seen(g.size(), 0);
    vector<int> path;
    explore(startNode, g, seen, path);
    return path;
}

void linkNodes(vector<vector<int>> &g, int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
}

int main() {
    int vertices = 5;
    vector<vector<int>> graph(vertices);

    linkNodes(graph, 1, 2);
    linkNodes(graph, 1, 0);
    linkNodes(graph, 2, 0);
    linkNodes(graph, 2, 3);
    linkNodes(graph, 2, 4);

    vector<int> result = dfsStart(graph, 0);

    for (int v : result) {
        cout << v << " ";
    }
}
