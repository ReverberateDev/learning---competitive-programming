#include "testlib.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Data structure for an O(1) randomized set
struct RandomizedSet {
    std::vector<long long> elements;
    std::unordered_map<long long, int> val_to_index;

    bool add(long long val) {
        if (val_to_index.count(val)) return false;
        elements.push_back(val);
        val_to_index[val] = elements.size() - 1;
        return true;
    }

    bool remove(long long val) {
        if (!val_to_index.count(val)) return false;
        int index_to_remove = val_to_index[val];
        long long last_val = elements.back();
        
        // The swap-and-pop trick
        elements[index_to_remove] = last_val;
        val_to_index[last_val] = index_to_remove;
        
        elements.pop_back();
        val_to_index.erase(val);
        return true;
    }

    long long getRandom() {
        int rand_index = rnd.next(0, (int)elements.size() - 1);
        return elements[rand_index];
    }
    
    bool empty() {
        return elements.empty();
    }
};

// Global state for the generator
std::unordered_map<long long, int> internal_counts;
RandomizedSet ones_set;  // Set of types with count == 1
RandomizedSet twos_set;  // Set of types with count == 2

// Optimized update function
void update_internal_count(long long type) {
    int old_count = internal_counts.count(type) ? internal_counts[type] : 0;
    
    if (old_count == 1) ones_set.remove(type);
    if (old_count == 2) twos_set.remove(type);

    internal_counts[type]++;
    int new_count = internal_counts[type];

    if (new_count == 1) ones_set.add(type);
    if (new_count == 2) twos_set.add(type);
}


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n");
    int q = opt<int>("q");
    long long min_val = opt<long long>("min_val", 1);
    long long max_val = opt<long long>("max_val");
    
    double p_create_pair = opt<double>("p_create", 0.5);
    double p_destroy_pair = opt<double>("p_destroy", 0.4);

    std::cout << n << " " << q << std::endl;

    // Generate Initial Array
    for (int i = 0; i < n; ++i) {
        long long type = rnd.next(min_val, max_val);
        std::cout << type << (i == n - 1 ? "" : " ");
        update_internal_count(type);
    }
    std::cout << std::endl;

    // Generate Q Queries
    for (int i = 0; i < q; ++i) {
        if (rnd.next() < 0.5) { // 50% chance for a Type 2 query
            std::cout << 2 << std::endl;
            continue;
        }
        
        std::cout << 1 << " ";
        
        double choice = rnd.next();
        long long item_to_add;

        if (choice < p_create_pair && !ones_set.empty()) {
            item_to_add = ones_set.getRandom();
        } else if (choice < p_create_pair + p_destroy_pair && !twos_set.empty()) {
            item_to_add = twos_set.getRandom();
        } else {
            // Fallback to a new random item
            item_to_add = rnd.next(min_val, max_val);
        }
        
        std::cout << item_to_add << std::endl;
        update_internal_count(item_to_add);
    }

    return 0;
}

/*
gen --n=1 --q=1 --max_val=10 > $
gen --n=2 --q=50 --max_val=1 --p_create=1.0 > $
gen --n=1000 --q=1000 --max_val=100 > $
gen --n=500 --q=500 --max_val=1e9 --p_create=0.6 --p_destroy=0.3 > $
gen --n=2000 --q=2000 --max_val=1e9 --p_create=0.5 --p_destroy=0.4 > $
gen --n=2000 --q=2000 --max_val=1e9 --p_create=0.4 --p_destroy=0.5 > $
gen --n=200000 --q=200000 --max_val=1000000 --p_create=0.5 --p_destroy=0.4 > $
gen --n=200000 --q=200000 --min_val=999900 --max_val=1000000 --p_create=0.6 --p_destroy=0.3 > $
gen --n=200000 --q=1000 --max_val=1000000 > $
gen --n=1000 --q=200000 --max_val=1000000 --p_create=0.5 --p_destroy=0.4 > $
gen --n=200000 --q=200000 --min_val=1000001 --max_val=2000000 --p_create=0.5 --p_destroy=0.4 > $
gen --n=200000 --q=200000 --max_val=1000000000 --p_create=0.6 --p_destroy=0.3 > $
gen --n=200000 --q=200000 --max_val=1000000000 --p_create=0.5 --p_destroy=0.5 > $
gen --n=200000 --q=200000 --min_val=900000000 --max_val=1000000000 > $
*/