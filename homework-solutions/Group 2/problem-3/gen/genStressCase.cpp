#include "../testlib.h"
#include <bits/stdc++.h>
using namespace std;

void genStressCase() {
    int n = 12;
    vector<pair<int,int>> edges;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

    int m = rnd.next(n*(n-1)/4, n*(n-1)/2);
    while ((int)edges.size() < m) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);
        if (u == v || adj[u][v]) continue;
        adj[u][v] = adj[v][u] = 1;
        edges.push_back({u,v});
    }

    cout << n << " " << m << "\n";
    for (auto [u,v] : edges)
        cout << u << " " << v << "\n";
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int type = atoi(argv[1]);
    int seed = atoi(argv[2]);
    rnd.setSeed(seed);
    genStressCase();
}
