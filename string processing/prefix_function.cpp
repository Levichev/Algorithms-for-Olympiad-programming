#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> a(n);

    for(int i = 1; i < n; ++i){
        int j = a[i-1];
        while(j > 0 && s[i] != s[j])
            j = a[j-1];
        if (s[i] == s[j]) ++j;
        a[i] = j;
    }
    return a;
}

int main(){
    string s; cin >> s;

    vector<int> a = prefix_function(s);

    for(int i = 0; i < a.size(); ++i)
        cout << a[i];

    return 0;
}