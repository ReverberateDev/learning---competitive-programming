//#include "testlib.h"
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
    int curr = rnd.next(min_value, max_value);
    while (in_set(curr, s)) {
        curr = rnd.next(min_value, max_value);
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
    string curr = random_string(max_size);
    while (in_set_string(curr, s)) {
        curr = random_string(max_size);
    }
    return curr;
}

// Generate a random integer from a set
int random_integer_in(unordered_set<int>& s) {
    auto it = s.begin();
    advance(it, rnd.next(0ll, (int)s.size() - 1));
    return *it;
}

string random_string_in(unordered_set<string>& s){
    auto it = s.begin();
    advance(it, rnd.next(0ll, (int)s.size() - 1));
    return *it;
}

const int max_n = 10000;
const int max_q = 10000;

main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1ll, max_n);
    int q = rnd.next(1ll, max_q);
    cout << n << " " << q + 1 << '\n';
    for(int i = 0; i < q; i++){
        int t = rnd.next(2ll, 2ll);
        if(t == 1){
            int a = rnd.next(1ll, n);
            int b = rnd.next(1ll, n);
            cout << t << " " << a << " " << b << '\n';
        }
        else{
            int a = rnd.next(1ll, n);
            cout << t << " " << a << '\n';
        }
    }
    int a = rnd.next(1ll, n);
    cout << 2 << " " << a << '\n';
}