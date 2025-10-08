#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 700005;

int n; ll m;
ll w[N];
vector<int> G[N];

pair<ll, ll> dfs(int u) {

    if (G[u].empty()) {
        return {1, w[u]};
    }

    ll sum_min_kept = 0;
    vector<ll> extras;
    int deg = (int) G[u].size();

    for (int v : G[u]) {
        auto [mk_v, c_v] = dfs(v);
        sum_min_kept += mk_v;
        extras.push_back(c_v - 1);
    }

    ll base = w[u] + deg;
    ll capacity = m - base;

    sort(extras.begin(), extras.end());
    ll cum = 0, count = 0;
    for (ll ex : extras) {
        if (cum + ex <= capacity) {
            cum += ex;
            count++;
        } else break;
    }

    ll min_kept = 1 + sum_min_kept - count;
    ll c_final = base + cum;
    return {min_kept, c_final};
}

namespace valid {
    bool dfs(int u) {
        for(const int& v : G[u]) {
            bool res = dfs(v);    
            if(res == 0) return 0;
        }
        ll complex = w[u] + G[u].size();
        if(complex > m) {
            return 0;
        }

        return 1;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        G[p].push_back(i + 1);
    }

    if(valid::dfs(1) == 0) {
        cout << 0 << "\n";
        return 0;
    }
    auto [min_kept_root, _] = dfs(1);
    ll ans = n - min_kept_root;
    cout << ans << "\n";

    return 0;
}
