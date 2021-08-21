#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")
using namespace std;
#define     INF                 INT_MAX
#define     INFLL               LONG_LONG_MAX
#define     F                   first
#define     S                   second
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     rep(i,a,b)          for(auto i=(a); i<(b); i++)
#define     dec(i,n,a)          for(auto i=(n); i>=(a); i--)
#define     each(a,x)           for (auto& a: x)
#define     nl                  '\n'
#define     sz(s)               ((int)(s.size())
#define     inp(a)              for(int i_=0;i_<a.size();i_++)cin>>a[i_] 
#define     prt(a)              for(int i_=0;i_<a.size();i_++)cout << a[i_] << ' '
#define     _                   auto
#define     Yes                 cout << "Yes" << nl
#define     No                  cout << "No" << nl
#define     YES                 cout << "YES" << nl
#define     NO                  cout << "NO" << nl
#define     inc                 int t_; cin >> t_; while(t_--)
#define     vec                 vector
//typedef     __int128_t          ll128;
typedef     long long           ll;
typedef     string              str;
typedef     long double         ld;
typedef     uint64_t            ull;
typedef     vec<bool>           vb;
typedef     map<int,int>        mii;
typedef     pair<int,int>       pii;
typedef     pair<ll,ll>         pll;
typedef     vec<int>            vi;
typedef     vec<ll>             vll;
typedef     vec<str>            vs;
typedef     vec<vec<int>>       vvi;
typedef     vec<vec<ll>>        vvll;
typedef     vec<vec<str>>       vvs;
//#define _DEBUG

struct segtree {
    vll tree;
    ll size;
    void init(ll n) {
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size -1, 0);
    }

    void build(vll &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                tree[x] = a[lx];
            }
        } else {
            ll m = (lx + rx)/2;
            build(a, 2*x+1, lx, m);
            build(a, 2*x+2, m, rx);
            tree[x] = tree[2*x + 1] + tree[2*x + 2];
        }
    }

    void build(vll &a) {
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        ll m = (lx + rx)/2;
        if (i < m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }
        tree[x] = tree[2*x + 1] + tree[2*x + 2];
    }

    void set(ll i, ll v) {  
        set(i, v, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if (lx >= r || l >= rx) {
            return 0;
        }
        if (l <= lx && rx <= r) {
            return tree[x];
        }
        ll m = (lx + rx)/2;

        ll s1 = sum(l, r, 2*x + 1, lx, m);
        ll s2 = sum(l, r, 2*x + 2, m, rx);
        return s1 + s2;
    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, size);
    }

};



void solve() {
    ll n, m; cin >> n >> m;

    vll a(n); inp(a);
    segtree st;
    st.build(a);
    while(m--) {
        ll c; cin >> c;

        if (c == 1) {
            ll i, v; cin >> i >> v;
            st.set(i, v);
        } else {
            ll l, r; cin >> l >> r;
            cout << st.sum(l, r) << nl;

        }
    }
    

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}