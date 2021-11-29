#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int N = 3*1e5+1;
long long fact[N];
long long inv[N];
long long invfact[N];

// С из n по k за О(1)
long long C(int n, int k) {
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = (i == 1) ? 1 : mod - mod / i * inv[mod % i] % mod;
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = invfact[i - 1] * inv[i] % mod;
    }

    // cout << C(10, 3) << endl;
    
    return 0;
} 
