#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;
int a[maxn], f[maxn];

int down(int i ) {
    return i & (i + 1);
}

int up(int i ) {
    return i | (i + 1);
}

int prefix_sum (int i ) { // [0..i]
    int sum = 0;
    while(i >= 0) {
        sum += f[i]; // [down(i) - 1]
        i = down(i) - 1;
    }
    return sum;
}

void update(int j, int x) { // a[j] += x
    a[j] += x;
    while(j < maxn) {
        f[j] += x;
        j = up(j);
    }
}

int main() {
    cout << prefix_sum(5) << '\n';
    update(0, 2);
    cout << prefix_sum(5) << '\n';
    update(1, 4);
    cout << prefix_sum(5) << '\n';
    update(0, -1);
    cout << prefix_sum(5) << '\n';
    update(10, 3);
    cout << prefix_sum(5) << '\n';
    
    return 0;
}