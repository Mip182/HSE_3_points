#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int type = inf.readInt(0, 1, "type");
    inf.readEoln();
    if (type == 0) {
        int a = inf.readInt(-1e9, 1e9, "a");
        inf.readSpace();
        int b = inf.readInt(-1e9, 1e9, "b");
        inf.readSpace();
        int c = inf.readInt(-1e9, 1e9, "c");
    } else {
        int a = inf.readInt(-1e5, 1e5, "a");
        inf.readSpace();
        int b = inf.readInt(-1e5, 1e5, "b");
        inf.readSpace();
        int c = inf.readInt(-1e5, 1e5, "c");
    }
    inf.readEoln();
    inf.readEof();
}