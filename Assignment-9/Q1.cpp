#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> runBFS(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> order;
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return order;
}

void linkNodes(vector<vector<int>>& graph, int x, int y) {
    graph[x].push_back(y);
    graph[y].push_back(x);
}

int main() {
    int size = 5;
    vector<vector<int>> graph(size);

    linkNodes(graph, 1, 2);
    linkNodes(graph, 1, 0);
    linkNodes(graph, 2, 0);
    linkNodes(graph, 2, 3);
    linkNodes(graph, 2, 4);

    vector<int> result = runBFS(graph);

    for (int val : result) {
        cout << val << " ";
    }
}
