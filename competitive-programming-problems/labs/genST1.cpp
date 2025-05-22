#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Optimized membership checks using unordered_set
bool in_set(int k, unordered_set<int>& s) {
    return s.find(k) != s.end();
}

bool in_set_string(string k, unordered_set<string>& s) {
    return s.find(k) != s.end();
}

// Generate random integer not in a given set
int random_integer_not(int min_value, int max_value, unordered_set<int>& s) {
    int attempts = 0, max_attempts = 1000;
    int curr = rnd.next(min_value, max_value);
    while (in_set(curr, s) && attempts++ < max_attempts) {
        curr = rnd.next(min_value, max_value);
    }
    if (attempts >= max_attempts) {
        throw runtime_error("Too many attempts to generate unique integer");
    }
    return curr;
}

// Generate a random array
vector<int> random_array(int size, int min_value, int max_value) {
    vector<int> res(size);
    for (auto& i : res) i = rnd.next(min_value, max_value);
    return res;
}

// Generate random string
string random_string(int max_size) {
    int size = rnd.next(1ll, max_size);
    string s;
    while (size--) {
        s += (char)('a' + rnd.next(0, 22));  // Characters 'a' to 'w'
    }
    return s;
}

// Generate random string not in a given set
string random_string_not(int max_size, unordered_set<string>& s) {
    int attempts = 0, max_attempts = 1000;
    string curr = random_string(max_size);
    while (in_set_string(curr, s) && attempts++ < max_attempts) {
        curr = random_string(max_size);
    }
    if (attempts >= max_attempts) {
        throw runtime_error("Too many attempts to generate unique string");
    }
    return curr;
}

// Generate a random integer from a set
int random_integer_in(unordered_set<int>& s) {
    auto it = s.begin();
    advance(it, rnd.next(0ll, (int)s.size() - 1));
    return *it;
}

const int max_q = 100000;
const int max_slen = 10;
const int max_i = 100000;
const int max_j = 100000;

main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int q = rnd.next(1ll, max_q);
    cout << q + 1 << '\n';

    unordered_set<string> string_save;
    unordered_set<int> integer_save;

    integer_save.insert(69); // Prepopulate the set with a starting integer

    for (int i = 0; i < q; i++) {
        int t = rnd.next(1ll, 2ll);
        cout << t << " ";
        if (t == 1) {
            string s = random_string_not(max_slen, string_save);
            string_save.insert(s);
            int i = rnd.next(1ll, max_i);
            integer_save.insert(i);
            cout << s << " " << i << '\n';
        } else {
            int j = random_integer_in(integer_save);
            cout << j << '\n';
        }
    }
    cout << "2 ";
    int j = random_integer_in(integer_save);
    cout << j << '\n';
}
