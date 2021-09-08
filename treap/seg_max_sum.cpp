#include <bits/stdc++.h>
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

struct Node{
    ll seg, suf, pref, sum;
};
const Node nodeMin({-INF,-INF,-INF,-INF}); 

Node recount(const Node &a, const Node &b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suf = max(b.suf, b.sum + a.suf);
    res.seg = max({a.seg, b.seg, a.suf + b.pref, a.pref, b.suf});
    return res;
};

struct Segtree {
    ll size = 0;
    vector<Node> tree;

    void init(ll n) {
        size = 1;
        while(size < n)
            size <<= 1;
        tree.assign(2*size-1, nodeMin);
    }

    void build(const vll& a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                tree[x] = {a[lx], a[lx], a[lx], a[lx]};
            }
        } else {
            ll m = (lx+rx)/2;
            build(a, 2*x+1, lx, m);
            build(a, 2*x+2, m, rx);
            tree[x] = recount(tree[2*x+1], tree[2*x+2]);
        }
    }

    void build (const vll& a) {
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx-lx == 1) {
            tree[x] = {v,v,v,v};
            return;
        }
        ll m = (rx+lx)/2;

        if (i < m) {
            set(i, v, 2*x+1,lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }

        tree[x] = recount(tree[2*x+1], tree[2*x+2]);
    }

    void set(ll i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll max_seg_sum () {
        return max(0LL,tree[0].seg);
    }

};

void solve() {
    ll n, m; cin >> n >> m;
    vll a(n); inp(a);

    Segtree segtree;
    segtree.build(a);

    cout << segtree.max_seg_sum() << nl;
    for(int t = 0; t < m; ++t) {
        ll i, v; cin >> i >> v;
        segtree.set(i, v);
        cout << segtree.max_seg_sum() << nl;
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