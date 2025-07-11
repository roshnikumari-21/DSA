#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, unordered_set<int>& ban, int& cnt) {
    if (ban.count(u)) return;
    vis[u] = true;
    cnt++;
    for (int v : g[u]) {
        if (!vis[v] && !ban.count(v)) {
            dfs(v, g, vis, ban, cnt);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int x;
    cin >> x;
    unordered_set<int> ban;
    for (int i = 0; i < x; ++i) {
        int b;
        cin >> b;
        ban.insert(b);
    }

    vector<bool> vis(n, false);
    int cnt = 0;
    if (!ban.count(0)) dfs(0, g, vis, ban, cnt);
    cout << cnt << endl;
    return 0;
}
