#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int n;

vector<bool> used;

void dfs(int v){
    used[v] = true;
    for(const auto&u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main(){
    cin >> n;
    used.resize(n);
}