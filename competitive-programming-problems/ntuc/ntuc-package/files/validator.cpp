#include "testlib.h"
#include <vector>
#include <numeric>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // Read N and K
    int n = inf.readInt(1, 100000, "N");
    inf.readSpace();
    long long k = inf.readLong(1LL, 100000000000000LL, "K"); // K >= 1
    inf.readEoln();

    // Read S array and P array
    std::vector<long long> s = inf.readLongs(n);
    inf.readEoln();
    std::vector<int> p = inf.readInts(n, 1, 10000, "P"); // P >= 1
    inf.readEoln();

    inf.readEof();

    long long total_stock = 0;
    bool infinite_supply_exists = false;
    for (long long stock_val : s) {
        // S[i] can be -1 (infinite) or >= 0 (finite stock, including zero for Subtask 4)
        ensuref(stock_val == -1LL || stock_val >= 0LL,
                "S[i] must be -1 or non-negative. Got %lld", stock_val);

        if (stock_val == -1) {
            infinite_supply_exists = true;
        } else {
            total_stock += stock_val;
        }
    }

    if (!infinite_supply_exists) {
        ensuref(k <= total_stock, "K (%lld) cannot be greater than the total finite stock (%lld)", k, total_stock);
    }

    return 0;
}
