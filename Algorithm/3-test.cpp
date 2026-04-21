#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int findParent(int v, vector<int>& parent) {
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    vector<Edge> mst;

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cost += e.w;
            mst.push_back(e);
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << cost << endl;
    for (auto e : mst)
        cout << e.u << " " << e.v << " " << e.w << endl;

    return 0;
}