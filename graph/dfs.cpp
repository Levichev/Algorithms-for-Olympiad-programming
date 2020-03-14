#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int n;

vector<bool> used;

void dfs(int v){
    used[v] = true;
    for(auto i = g[v].begin(); i != g[v].end(); ++i){
        if (!used[*i])
            dfs(*i);
    }
}

int main(){
    cin >> n;
    used.resize(n);
}