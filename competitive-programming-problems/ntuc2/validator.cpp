#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // Read and validate N and Q
    int n = inf.readInt(1, 200000, "N");
    inf.readSpace();
    int q = inf.readInt(1, 200000, "Q");
    inf.readEoln();

    // Read and validate the initial array T
    inf.readInts(n, 1, 1000000000, "T");
    inf.readEoln();

    // Read and validate Q queries
    for (int i = 0; i < q; ++i) {
        int type = inf.readInt(1, 2, "query_type");
        if (type == 1) {
            inf.readSpace();
            inf.readInt(1, 1000000000, "A");
        }
        inf.readEoln();
    }

    // Ensure there is no extra content at the end of the file
    inf.readEof();

    return 0;
}