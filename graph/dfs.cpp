#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int n;

vector<bool> used;
vector<int> color;

void dfs(int v){
    used[v] = true;
    for(const auto&u : g[v]) {
        if (!used[u]) {
            color[u] = color[v];
            dfs(u);
        }
    }
}

int main(){
    n = 5;//cin >> n;
    used.resize(n);
    color.resize(n, -1);
    g.resize(n);
    g[0] = {2};
    g[1] = {2};
    g[2] = {0, 1};
    g[3] = {4};
    g[4] = {3};

    for(int v = 0; v < n; ++v) {
        if (color[v] == -1) {
            color[v] = v;
            dfs(v);
        }
    }
    for(auto&col: color) {
        cout << col << ' ';
    }
    cout << '\n';
}