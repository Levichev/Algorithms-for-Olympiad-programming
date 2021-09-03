#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int n;

vector<bool> used;
vector<int> dist;

int main() {
    n = 5;//cin >> n;
    used.resize(n);
    dist.resize(n, -1);
    g.resize(n);
    g[0] = {2,3};
    g[1] = {2};
    g[2] = {0, 1};
    g[3] = {0};
    g[4] = {};

    queue<int> q;
    q.push(0); // starting vertex
    dist[q.front()] = 0;
    while(!q.empty()) {
        int v = q.front();
        used[v] = true;
        q.pop();
        for(const auto&u : g[v]) {
            if (!used[u]) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    for(auto&x : dist) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}