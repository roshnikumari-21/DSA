// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 1000;

// struct E { int u, v, w; };
// long long best;

// void sumOfVisibleCells(int n, int k, int a[][MAXN]) {
//     long long tot = 0;
//     for (int i = 0; i < n; ++i)
//         for (int j = 0; j < n; ++j)
//             tot += a[i][j];

//     vector<E> e;
//     for (int i = 0; i < n; ++i)
//         for (int j = 0; j < n; ++j) {
//             int id = i * n + j;
//             if (j + 1 < n) e.push_back({id, id + 1, a[i][j] + a[i][j + 1]});
//             if (i + 1 < n) e.push_back({id, id + n, a[i][j] + a[i + 1][j]});
//         }

//     int m = e.size();
//     int M = min(m, max(1000, 2000 * k));
//     nth_element(e.begin(), e.begin() + M, e.end(), [](const E& x, const E& y) {
//         return x.w > y.w;
//     });
//     e.resize(M);
//     sort(e.begin(), e.end(), [](const E& x, const E& y) {
//         return x.w > y.w;
//     });

//     vector<long long> ps(M + 1);
//     for (int i = M - 1; i >= 0; --i)
//         ps[i] = ps[i + 1] + e[i].w;

//     vector<int> used;
//     best = 0;

//     function<void(int, int, long long)> dfs = [&](int i, int t, long long s) {
//         if (t == k) {
//             best = max(best, s);
//             return;
//         }
//         if (i >= M || M - i < k - t) return;
//         if (s + ps[i] < best) return;

//         auto ed = e[i];
//         bool ok = true;
//         for (int x : used)
//             if (x == ed.u || x == ed.v) {
//                 ok = false;
//                 break;
//             }
//         if (ok) {
//             used.push_back(ed.u);
//             used.push_back(ed.v);
//             dfs(i + 1, t + 1, s + ed.w);
//             used.pop_back();
//             used.pop_back();
//         }
//         dfs(i + 1, t, s);
//     };

//     dfs(0, 0, 0);
//     cout << (tot - best) << "\n";
// }


// int main () {
//     int n, k;
//     cin >> n >> k;
//     int arr[MAXN][MAXN];
//     for (int i = 0; i < n; ++i)
//         for (int j = 0; j < n; ++j)
//             cin >> arr[i][j];

//     sumOfVisibleCells(n, k, arr);
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

struct E { int u, v, w; };
long long best;

void sumOfVisibleCells(int n, int k, int a[][MAXN]) {
    long long tot = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            tot += a[i][j];

    vector<E> e;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int id = i * n + j;
            if (j + 1 < n) e.push_back({id, id + 1, a[i][j] + a[i][j + 1]});
            if (i + 1 < n) e.push_back({id, id + n, a[i][j] + a[i + 1][j]});
        }

    int m = e.size();
    int M = min(m, 2000); // Reduce M further to 2000 or smaller
    nth_element(e.begin(), e.begin() + M, e.end(), [](const E& x, const E& y) {
        return x.w > y.w;
    });
    e.resize(M);
    sort(e.begin(), e.end(), [](const E& x, const E& y) {
        return x.w > y.w;
    });

    vector<long long> ps(M + 1);
    for (int i = M - 1; i >= 0; --i)
        ps[i] = ps[i + 1] + e[i].w;

    bitset<MAXN * MAXN> used;
    best = 0;

    function<void(int, int, long long)> dfs = [&](int i, int t, long long s) {
        if (t == k) {
            best = max(best, s);
            return;
        }
        if (i >= M || M - i < k - t) return;
        if (s + ps[i] < best) return;

        auto ed = e[i];
        if (!used[ed.u] && !used[ed.v]) {
            used[ed.u] = used[ed.v] = 1;
            dfs(i + 1, t + 1, s + ed.w);
            used[ed.u] = used[ed.v] = 0;
        }
        dfs(i + 1, t, s);
    };

    dfs(0, 0, 0);
    cout << (tot - best) << "\n";
}

int main () {
    int n, k;
    cin >> n >> k;
    int arr[MAXN][MAXN];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    sumOfVisibleCells(n, k, arr);
    return 0;
}
