#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adjlist;
    vector<int> path;

public:
    Graph(int n ): n(n) { adjlist.resize(n+1); }
    void addEdge(int u, int v) { adjlist[u].push_back(v); }

    void eulerianPath(int src);
    void dfs(int src);
};

void Graph::eulerianPath(int src) {
    dfs(src);
    for(int x: path)    cout << x << ' '; cout << endl;
}

void Graph::dfs(int curr) {
    while(!adjlist[curr].empty()) {
        int next = adjlist[curr].front();
        adjlist[curr].erase(adjlist[curr].begin());
        dfs(next);
    }
    path.insert(path.begin(), curr);
}

int main() {
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 5);
    g.addEdge(4, 3);
    g.addEdge(5, 2);
    g.addEdge(5, 4);
    
    g.eulerianPath(1);
    return 0;
}
