#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<int> *adjlist;

public:
    Graph(int n): n(n), adjlist(new vector<int>[n+1]) {}
    void addEdge(int u, int v) { adjlist[u].push_back(v), adjlist[v].push_back(u); }

    bool validateColors(int u, int m, vector<int> colors);
    void graphColor(int u, int m, vector<int> colors);
};

// check colors of neighbors of node u
bool Graph::validateColors(int u, int m, vector<int> colors) {
    for(int neighbor: adjlist[u])   if(colors[u] == colors[neighbor])   return false;
    return true;
}

// Backtracking approach. O(n*m^n) time, O(n) space
void Graph::graphColor(int u, int m, vector<int> colors) {
    // if reached the last node print colors
    if(u == n+1) {
        for(int i = 1; i <= n; i++)     cout << colors[i] << " "; cout << endl;
        return;
    }

    // try coloring node u with color c, 1 ≤ c ≤ m
    for(int c = 1; c <= m; c++) {
        colors[u] = c;
        // check neighbors for color validity and don't recur further along this branch if found invalid, otherwise recur and color next node
        if(validateColors(u, m, colors))    graphColor(u+1, m, colors);
    }
}

int main() {
    int n = 4;
    Graph g(n);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int m = 3;
    vector<int> colors(n+1);
    g.graphColor(1, m, colors);
    return 0;
}

/*

Above graph can be represented as:

    1---2
    | \ |   --> When m = 3 colors, all possible ways of coloring it are:
    |  \|       [1 2 3 2], [1 3 2 3], [2 1 3 1], [2 3 1 3], [3 1 2 1], [3 2 1 2]
    4---3

It takes m^n time to generate all possible color combinations for graph with n nodes and m colors and a linear scan
to check if all neighbors of a given node have different colors. Above program is optimized by pruning the recursion tree
using backtracking as at each node we check for valid colors and don't recur futher along that branch if a color placement results in violation.

*/
