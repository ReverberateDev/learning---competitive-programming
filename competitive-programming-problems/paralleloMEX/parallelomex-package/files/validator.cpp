#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 200000, "n");
    inf.readSpace();
    long long k = inf.readLong(0LL, 1000000000LL, "k");
    inf.readEoln();

    for (int i = 0; i < n; ++i) {
        inf.readLong(1LL, 1000000000LL, "v[i]");
        if (i < n - 1) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    inf.readEof();

    return 0;
}