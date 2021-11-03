#include <bits/stdc++.h>
#include <numeric>
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
#define     sz(s)               ((int)(s.size()))
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


struct BigInt {
    vi lnum;
    int remainder = 0;
    const ll base = 1000*1000*1000;

    friend std::ostream& operator<< (std::ostream &out, const BigInt &x) {
        const vi& a = x.lnum;
        if (a.empty()) {
            out << 0;
        } else {
            out << a.back();
        }
        for (int i=(int)a.size()-2; i>=0; --i) {
            ll x = a[i];
            vi res(9);
            for(int j = 0; j < 9; ++j) {
                res.pb(x%10);
                x%=10;
            }
            for(int j = 8; j >= 0; --j) {
                out <<  res[j];
            }
        }
        return out;
    }
    friend std::istream& operator>> (std::istream &in, BigInt &x) {
        vi& a = x.lnum;
        string s; in >> s;
        for (int i=(int)s.length(); i>0; i-=9)
            if (i < 9)
                a.push_back (atoi (s.substr (0, i).c_str()));
            else
                a.push_back (atoi (s.substr (i-9, 9).c_str()));

        while (a.size() > 1 && a.back() == 0) // удаление лидирующих нулей
	        a.pop_back();
        
        return in;
    }
    // Результат сохраняется в x
    friend BigInt operator+=(BigInt& x, const BigInt& y) {
        int base = x.base;
        vi& a = x.lnum;
        const vi& b = y.lnum;
        int carry = 0;
        for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
            if (i == a.size())
                a.push_back (0);
            a[i] += carry + (i < b.size() ? b[i] : 0);
            carry = a[i] >= base;
            if (carry)  a[i] -= base;
        }
        return x;
    }
    friend BigInt operator+(const BigInt& x, const BigInt& y) {
        int base = x.base;
        vi a = x.lnum;
        const vi& b = y.lnum;
        int carry = 0;
        for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
            if (i == a.size())
                a.push_back (0);
            a[i] += carry + (i < b.size() ? b[i] : 0);
            carry = a[i] >= base;
            if (carry)  a[i] -= base;
        }
        return {a};
    }
    //Число x >= y 
    //Результат сохраняется в x
    friend BigInt operator-=(BigInt& x, const BigInt&y) {
        int base = x.base;
        vi& a = x.lnum;
        const vi& b = y.lnum;
        int carry = 0;
        for (size_t i=0; i<b.size() || carry; ++i) {
            a[i] -= carry + (i < b.size() ? b[i] : 0);
            carry = a[i] < 0;
            if (carry)  a[i] += base;
        }
        while (a.size() > 1 && a.back() == 0)
            a.pop_back();
        return x;
    }
    friend BigInt operator-(const BigInt& x, const BigInt&y) {
        int base = x.base;
        vi a = x.lnum;
        const vi& b = y.lnum;
        int carry = 0;
        for (size_t i=0; i<b.size() || carry; ++i) {
            a[i] -= carry + (i < b.size() ? b[i] : 0);
            carry = a[i] < 0;
            if (carry)  a[i] += base;
        }
        while (a.size() > 1 && a.back() == 0)
            a.pop_back();
        return {a};
    }
    friend BigInt operator*(const BigInt& x, const BigInt&y) {
        int base = x.base;
        const vi &a = x.lnum;
        const vi &b = y.lnum;

        BigInt z;
        vi &c = z.lnum;
        c.resize(a.size()+b.size());
        for (ll i=0; i<a.size(); ++i)
            for (ll j=0, carry=0; j<(ll)b.size() || carry; ++j) {
                ll cur = c[i+j] + a[i] * 1ll * ((j < (ll)b.size()) ? b[j] : 0) + carry;
                c[i+j] = int (cur % base);
                carry = int (cur / base);
            }
        while (c.size() > 1 && c.back() == 0)
            c.pop_back();

        return z;
    }
    //Делит длинное x на короткое y (y < base), частное сохраняет в x, остаток в carry:
    friend BigInt operator/=(BigInt& x, int y) {
        int carry = 0;
        int base = x.base;
        int b = y;
        vi &a = x.lnum;
        for (int i=(int)a.size()-1; i>=0; --i) {
            long long cur = a[i] + carry * 1ll * base;
            a[i] = int (cur / b);
            carry = int (cur % b);
        }
        while (a.size() > 1 && a.back() == 0)
            a.pop_back();
        x.remainder = carry;
        return x;
    }
    friend BigInt operator/(BigInt& x, int y) {
        int carry = 0;
        int base = x.base;
        int b = y;
        vi a = x.lnum;
        for (int i=(int)a.size()-1; i>=0; --i) {
            long long cur = a[i] + carry * 1ll * base;
            a[i] = int (cur / b);
            carry = int (cur % b);
        }
        while (a.size() > 1 && a.back() == 0)
            a.pop_back();
        return {a,carry};
    }
 
};

void solve() {
    BigInt a, b; cin >> a >> b;
    int x = 100;
    cout << a * b << nl;
    cout << (a / x) << nl;
    cout << (a / x).remainder << nl;
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