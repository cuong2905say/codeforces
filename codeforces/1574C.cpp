/*
    author : cuong2905say
    created : 02-09-2023  17:38:47  UTC: +7
*/
#include <bits/stdc++.h>
#define all(A) (A).begin(), (A).end()

using namespace std;
using ll = long long;
using ull = unsigned long long;

template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> A) {
    os << "{ " << A.first << ", " << A.second << " }";
    return os;
}
template <class T1, class T2, class T3>
ostream& operator<<(ostream& os, tuple<T1, T2, T3> A) {
    os << "{ " << get<0>(A) << ", " << get<1>(A) << ", " << get<2>(A) << " }";
    return os;
}

template <class it>
void _print(it begin, it end) {
    for (it i = begin; i != end; i++) {
        cout << *i << " ";
    }
}

void _verbose() {
}

int MOD = 1e9 + 7;
int verbose = -1;
int all_cases = -1;
void precalc() {
}
void solve(bool v = false, int all_case = -1) {
    int n;
    cin >> n;
    ll A[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A, A + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        ll res = 0;
        auto it = lower_bound(A, A + n, x);
        if (it == A) {
            res = max(0ll, y - (sum - *it));
        } else if (it == A + n) {
            it = A + n - 1;
            res = (x - *it + max(0ll, y - (sum - *it)));
        } else {
            auto it2 = --it;
            it++;
            res = min(x - *it2 + max(y - (sum - *it2), 0ll), max(y - (sum - *it), 0ll));
        }
        cout << res << endl;
    }
    if (!v && all_case == all_cases) {
        return;
    }
    if (v && all_case == all_cases) {
        _verbose();
    }
}

void reset() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    precalc();
    for (int i = 0; i < t; i++) {
#ifndef ONLINE_JUDGE
        cout << "case " << i + 1 << ": ";
#endif
        if (verbose == i + 1) {
            solve(true, t);
        } else {
            solve(false, t);
        }
        reset();
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
#ifndef ONLINE_JUDGE
    chrono::duration<double> time_span = chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout << "time use: " << time_span.count() << endl;
#endif

    return 0;
}
