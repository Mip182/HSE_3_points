#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long t;
    cin >> t;
    long long a, b, c;
    cin >> a >> b >> c;
    vector<long long> d;
    d.push_back(a);
    d.push_back(b);
    d.push_back(c);
    sort(d.begin(), d.end());
    vector<pair<long long, long long>> ans;
    while (d[0] < d[1]) {
        if (d[0] + d[2] == d[1] * 2) {
            cout << "YES" << '\n';
            for (long long g = 0; g < d[1] - d[0]; g++) {
                ans.push_back({d[0] + g, d[2] - g});
            }
            cout << ans.size() << '\n';
            if (t == 1) {
                for (auto v : ans) {
                    cout << v.first << ' ' << v.second << '\n';
                }
            }
            return 0;
        }
        ans.push_back({d[0], d[1]});
        d[0]++;
        d[1]--;
    }
    while (d[1] < d[2]) {
        if (d[0] + d[2] == d[1] * 2) {
            cout << "YES" << '\n';
            for (long long g = 0; g < d[1] - d[0]; g++) {
                ans.push_back({d[0] + g, d[2] - g});
            }
            cout << ans.size() << '\n';
            if (t == 1) {
                for (auto v : ans) {
                    cout << v.first << ' ' << v.second << '\n';
                }
            }
            return 0;
        }
        ans.push_back({d[1], d[2]});
        d[1]++;
        d[2]--;
    }
    cout << "NO";
}