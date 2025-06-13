#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

// Helper functions to print vectors
void print_vector_ll(const std::vector<long long>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

void print_vector_int(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    std::string mode = argv[1];
    
    int n;
    long long k;
    std::vector<long long> s;
    std::vector<int> p;

    if (mode == "random") {
        n = std::stoi(argv[2]);
        long long k_max = std::stoll(argv[3]);
        int s_type = std::stoi(argv[4]);
        int p_max = std::stoi(argv[5]);

        int p_min = 1;
        bool no_infinite = false;
        bool k_equals_total_stock = false;

        for (int i = 6; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "--no-infinite") no_infinite = true;
            if (arg == "--k-equals-total-stock") k_equals_total_stock = true;
            if (arg.rfind("--p-min=", 0) == 0) p_min = std::stoi(arg.substr(8));
        }
        if (k_equals_total_stock) no_infinite = true;
        
        s.resize(n);
        p.resize(n);
        long long total_stock = 0;
        bool has_infinite = false;

        if (s_type == 1) { // All infinite
            for (int i = 0; i < n; ++i) s[i] = -1;
            has_infinite = true;
        } else if (s_type == 2) { // Small S
            for (int i = 0; i < n; ++i) {
                if (!no_infinite && rnd.next(10) == 0) {
                    s[i] = -1; has_infinite = true;
                } else {
                    s[i] = rnd.next(0, 100); total_stock += s[i];
                }
            }
        } else { // Full S (type 0 or 3)
             for (int i = 0; i < n; ++i) {
                if (!no_infinite && rnd.next(10) < 2) {
                    s[i] = -1; has_infinite = true;
                } else {
                    s[i] = rnd.next(s_type == 0 ? 0LL : 1LL, 1000000000LL);
                    if (!has_infinite) total_stock += s[i];
                }
            }
        }

        if (k_equals_total_stock) {
            k = total_stock;
        } else {
            long long k_upper_bound = has_infinite ? k_max : total_stock;
            if (k_upper_bound == 0) k_upper_bound = 1;
            k = rnd.next(1LL, k_upper_bound);
        }
        if (k == 0) k = 1;

        for (int i = 0; i < n; ++i) p[i] = rnd.next(p_min, p_max);

    } else if (mode == "rev_sorted") {
        n = std::stoi(argv[2]);
        k = std::stoll(argv[3]);
        int p_max = std::stoi(argv[4]);
        s.assign(n, 1);
        
        // --- THIS IS THE FIX ---
        p.resize(n);
        for (int i = 0; i < n; ++i) {
            p[i] = rnd.next(1, p_max);
        }
        std::sort(p.rbegin(), p.rend()); // Sort descending

    } else if (mode == "killer_st4") {
        n = 10;
        k = std::stoll(argv[2]);
        s = {-1, 100, 100, 100, 100, 100, 100, 100, 100, 100};
        p = {5, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    } else if (mode == "inf_expensive") {
        n = std::stoi(argv[2]);
        k = std::stoll(argv[3]);
        s.assign(n, 100); s.back() = -1;
        p.assign(n, 10); p.back() = 1000;
    } else if (mode == "long_long") {
        n = 2;
        k = 100000000000000LL;
        s = {50000000000000LL, 50000000000000LL};
        p = {10000, 10000};
    } else {
        ensuref(false, "Unknown generator mode: %s", mode.c_str());
    }

    std::cout << n << " " << k << std::endl;
    print_vector_ll(s);
    print_vector_int(p);

    return 0;
}