#include <iostream>
#include <vector>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, a, b, c;
    cin >> t >> a >> b >> c;
    if ((a + b + c) % 3) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    //1e5
    if (t == 1) {
        vector<pair<int, int>> ans;
        while (true) {
            if (c < b) swap(b, c);
            if (c < a) swap(c, a);
            if (a > b) swap(a, b);
            if (a == c) break;
            ans.emplace_back(make_pair(a, c));
            a++;
            c--;
        }
        cout << ans.size() << '\n';
        for (auto pair: ans) {
            cout << pair.first << " " << pair.second << '\n';
        }
        return 0;
    }
    //1e9
    int res = 0;
    while (true) {
        if (c < b) swap(b, c);
        if (c < a) swap(c, a);
        if (a > b) swap(a, b);
        if (a == c) break;
        if (c - b == b - a) {
            res += c - b;
            break;
        }
        if (c - b > 0 && b - a > 0) {
            int min_dist = min(b - a, c - b);
            a += min_dist;
            c -= min_dist;
            res += min_dist;
        } else {
            if (c == b) {
                int distance = b - a;
                if (b - a < 3) {
                    a++, c--, res++;
                } else {
                    int dst_3 = distance / 3;
                    b -= dst_3;
                    c -= dst_3;
                    a += 2 * dst_3;
                    res += 2 * dst_3;
                }
            } else {
                int distance = c - b;
                if (c - b < 3) {
                    b++, c--, res++;
                } else {
                    int dst_3 = distance / 3;
                    c -= 2 * dst_3;
                    a += dst_3;
                    b += dst_3;
                    res += 2 * dst_3;
                }
            }
        }
    }
    cout << res << '\n';
    return 0;
}