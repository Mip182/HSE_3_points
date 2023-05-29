#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

long long type;
long long a, b, c;

pair<bool, long long> readAnswer(InStream &in) {
    string s = lowerCase(in.readString("[a-zA-Z]{2,3}"));
    
    if (s != "yes" && s != "no") {
        in.quitf(_pe, "Answer isn't either Yes or No");
    }
    if (s == "no") {
        return {0, 0};
    } else if (s != "yes") {
        in.quitf(_wa, "Wrong yes/no string");
    }

    long long ans = in.readLong();

    if (type == 0) {
        return {true, ans};
    }

    vector<long long> now = {a, b, c};

    for (int i = 0; i < ans; i++) {
        long long x = in.readLong();
        long long y = in.readLong();

        vector<bool> used(3);

        for (int j = 0; j < 3; j++) {
            if (used[j])
                continue;
            if (now[j] == x) {
                used[j] = true;
                now[j]++;
                break;
            }
        }

        if (accumulate(used.begin(), used.end(), 0) != 1) {
            in.quitf(_wa, "Left point doesn't exist");
        }

        for (int j = 0; j < 3; j++) {
            if (used[j])
                continue;
            if (now[j] == y) {
                used[j] = true;
                now[j]--;
                break;
            }
        }

        if (accumulate(used.begin(), used.end(), 0) != 2) {
            in.quitf(_wa, "Right point doesn't exist");
        }

    }
    if (now[0] != now[1] || now[0] != now[2]) {
        in.quitf(_wa, "Points aren't in the same place");
    }
    return {true, ans};
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    type = inf.readInt();

    a = inf.readLong();
    b = inf.readLong();
    c = inf.readLong();

    auto A = readAnswer(ans);
    auto B = readAnswer(ouf);

    long long jans = A.second;
    long long pans = B.second;
    
    if (type == 0) {
        if (A != B) {
            quitf(_wa, "Participant answer is different from jury");
        }
    } else {
        if (A.first < B.first) {
            quitf(_fail, "Participant found better answer that jury");
        } else if (A.first > B.first) {
            quitf(_wa, "Jury found better answer than participant");
        }
    
        if (jans < pans) {
            quitf(_wa, "Jury found better answer than participant");
        } else if (jans > pans) {
            quitf(_fail, "Participant found better answer that jury");
        }
    }

    quitf(_ok, "%lld", pans);
}
