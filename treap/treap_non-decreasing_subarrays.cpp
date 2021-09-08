//how many non-decreasing subarrays are contained on the segment
//https://codeforces.com/contest/1567/problem/E
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
 
struct Node {
    ll cntSuf = 0, cntPref = 0;
    ll numSuf = 0, numPref = 0;
    ll ans = 0;
    bool full = false;
};

ll numberOfPairs(ll x) {
    return x*(x+1)/2;
}


struct Treap {
    vec<Node> tree;
    const Node ZERO = {0,0,0,0,0,false};
    ll size;



    void init(int n) {
        size = 1;
        while(size < n) {
            size <<= 1;
        }
        tree.assign(2*size - 1, ZERO);
        // for(int i = 0, x = 0; i < 2*size-1; i++, --x) {
            // a[i] = {0,0,x,x,0,false};
        // }
    }
    
    Node combine (const Node& a, const Node& b) {
        Node res;

        res.cntPref = a.cntPref;
        res.numPref = a.numPref;
        if (a.full && a.numSuf <= b.numPref) {
            res.cntPref += b.cntPref;            
        }
        res.cntSuf = b.cntSuf;
        res.numSuf = b.numSuf;
        if (b.full && a.numSuf <= b.numPref) 
            res.cntSuf += a.cntSuf;
        
        res.full = (a.full && b.full && (a.numSuf <= b.numPref));
        ll diff = 0;
        if (a.numSuf <= b.numPref) {
            diff = numberOfPairs(a.cntSuf + b.cntPref) - numberOfPairs(a.cntSuf) - numberOfPairs(b.cntPref);
        }
        res.ans = a.ans + b.ans + diff;

        return res;
    }

    Node combine2 (const Node& a, const Node& b) {
        Node res;

        res.cntPref = a.cntPref + (a.full?(a.numSuf <= b.numPref?(a.numSuf > 0?a.cntPref:0):0):0);
        res.numPref = a.numPref;
        res.cntSuf = b.cntSuf + (b.full?(a.numSuf <= b.numPref?(b.numPref > 0?a.cntSuf:0):0):0);
        res.numSuf = b.numSuf;
        res.full = (a.full && b.full && (a.numSuf <= b.numPref));
        ll diff = 0;
        if (a.numSuf <= b.numPref) {
            diff = numberOfPairs(a.cntSuf+b.cntPref) - (numberOfPairs(a.cntSuf) + numberOfPairs(b.cntPref)); 
        }
        res.ans = a.ans + b.ans + diff;

        return res;
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx-lx == 1) {
            tree[x] = {1,1,v,v, 1, true};
            return;
        }
        int mx = (lx+rx)/2;

        if (i < mx) {
            set(i, v, 2*x+1, lx, mx);
        } else {
            set(i, v, 2*x+2, mx, rx);
        }

        tree[x] = combine(tree[2*x+1], tree[2*x+2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    Node get(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return ZERO;
        } 
        if (lx >= l && rx <= r) {
            return tree[x];
        }
        int mx = (lx+rx)/2;
        Node a = get(l, r, 2*x+1, lx, mx);
        Node b = get(l, r, 2*x+2, mx, rx);

        return combine(a,b);    
    }   

    Node get(int l, int r) {
        return get(l, r, 0 , 0, size);
    }

};


void solve() {
    ll n, q; cin >> n >> q;

    vll a(n); inp(a);

    Treap treap;
    treap.init(n);
    for(int i = 0; i < n; ++i) {
        treap.set(i, a[i]);
    }

    while(q--) {
        int ch; cin >> ch;

        if (ch == 1) {
            ll x, y; cin >> x >> y;
            x--;
            treap.set(x, y);
        } else {
            ll l , r; cin >> l >> r;
            l--;
            cout << treap.get(l, r).ans << nl;
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