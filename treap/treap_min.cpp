#include <bits/stdc++.h>
using namespace std;
#define LLMIN LONG_LONG_MIN
#define LLMAX LONG_LONG_MAX
#define IMIN INT_MIN
#define IMAX INT_MAX
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(auto i=(a); i<(b); i++)
#define dec(i,n,a) for(auto i=(n); i>=(a); i--)
#define nl '\n'
#define sz(s) s.size()
#define len(s) s.length()
#define inp(a) for(auto& i: a) cin >> i
#define prt(a) for(auto& i: a) cout << i << ' '
#define _ auto
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define inc int t_; cin >> t_; while(t_--)
typedef int64_t ll;
typedef uint64_t ull;
typedef vector<bool> vb;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef pair<int32_t,int32_t> pii;
typedef pair<ll,ll> pll;
typedef vector<int32_t> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int32_t>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<string>> vvs;
//#define _DEBUG


struct segtree {
    struct node {
        int x;        
    };
    const node nnul = {INT_MAX/2};

    node min(node a, node b) {
        if (a.x < b.x) return a;
        else return b;
    }

    vector<node> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size*=2;
        tree.assign(2*size - 1, nnul);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = {v};
            return;
        } 

        int mid = (lx + rx) / 2;

        if (i < mid) {
            set(i, v, 2*x + 1, lx, mid);
        } else {
            set(i, v, 2*x + 2, mid, rx);
        }

        tree[x] = min(tree[2*x + 1],tree[2*x + 2]);
    }
    node mn(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return nnul;
        }
        if (lx >= l && rx <= r) {
            return tree[x];
        }
        int mid = (lx + rx) / 2;

        node m1 = mn(l, r, 2*x + 1, lx, mid);
        node m2 = mn(l, r, 2*x + 2, mid, rx);
        return min(m1,m2);
    }

    int mn(int l, int r) {
        return mn(l, r, 0, 0, size).x;
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vi a(n); inp(a);
    segtree tree;
    tree.init(n);
    for(int i = 0; i < n; ++i) {
        tree.set(i,a[i]);
    }
    while(m--) {
        char ch; cin >> ch;

        if (ch == '1') {
            int i, v; cin >> i >> v;
            tree.set(i,v);
        } else if (ch == '2') {
            int l, r; cin >> l >> r;
            cout << tree.mn(l, r) << nl;
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