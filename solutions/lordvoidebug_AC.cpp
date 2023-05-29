#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <numeric>

#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define len(a) (int) (a).size()
#define forn(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define int long long
using namespace std;

void solve();

mt19937 rnd(2007);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    swap(rng, rnd);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}


int get(int a, int b, int c){
    vector<int> vals = {a, b, c};
    sort(all(vals)); int res = (vals[0] + vals[1] + vals[2]) / 3;
    vals[0] -= res;
    vals[1] -= res;
    vals[2] -= res;
    return max(max(abs(vals[0]),  abs(vals[1])), abs(vals[2]));
}

void solve() {
    int t; cin >> t;
    int a, b, c; cin >> a >> b >> c;
    if ((a + b + c) % 3 != 0){
        cout << "No" << endl;
        cout << endl;;
        return;
    }
    cout << "Yes" << endl;
    int ans = get(a, b, c);
    cout << ans << endl;
    if (t == 0) return;
    vector<int> vals = {a, b, c};
    while (ans != 0) {
        forn (i, 3){
            forn (j, 3) {
                vals[i]++;
                vals[j]--;
                if (get(vals[0], vals[1], vals[2]) + 1 == ans) {

                    vals[i]--;
                    vals[j]++;
                    cout << vals[i] << ' ' << vals[j] << endl;
                    ans--;

                    vals[i]++;
                    vals[j]--;
                    goto out;


                }
                vals[i]--;
                vals[j]++;
            }
        }
        out:;
    }


}