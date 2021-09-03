#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int a[maxn][maxn], f[maxn][maxn];

int down(int i ) {
    return i & (i + 1);
}

int up(int i ) {
    return i | (i + 1);
}

int prefix_sum (int i , int j) { // [0..i] x [0..j]
    int sum = 0;
    for(int x = i; x >= 0; x = down(x) - 1) {
        for (int y = j; y >= 0; y = down(y) - 1) {
            sum += f[x][y];
        }
    }
    return sum;
}

void update(int i, int j, int t) { // a[i][j] += t
    a[i][j] += t;
    for(int x = i; x < maxn; x = up(x)) {
        for(int y = j; y < maxn; y = up(y)) {
            f[x][y] += t;
        }
    }
}

int main() {
    cout << prefix_sum(10, 10) << '\n';
    update(2,2, 10);   
    cout << prefix_sum(10, 10) << '\n';
    update(3,2, 10);   
    cout << prefix_sum(10, 10) << '\n';
    update(5,5, 1);  
    cout << prefix_sum(2, 2) << '\n';
    cout << prefix_sum(3, 2) << '\n';
    cout << prefix_sum(10, 10) << '\n';
    return 0;
}