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

const int max_n = 1000000; //10^6
const int max_q = 10000; //10^4
//q queries
//qlogn
main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int n = max_n;
    int q = max_q;
    cout << n << " " << q + 1 << '\n';
    for(int i = 0; i < q; ){
        int left = q - i; //number of queries we have left
        int can = left - 1ll; //number of changes we can make at most?
        if(can == 0){
            int a = rnd.next(1ll, n);
            cout << 2 << " " << a << '\n';
            break;
        }
        int change = rnd.next(1ll, min(n, can)); //number of changes we can make
        change--;
        int nxt = rnd.next(1ll, n); //what we want to change to
        int strt = rnd.next(1ll, n - change + 1);
        for(int j = 0; j < change; j++){
            cout << "1 " << strt + j << " " << nxt << '\n';
        }
        nxt = rnd.next(1ll, n);
        cout << "1 " << strt << " " << nxt << '\n';
        cout << "2 " << nxt << '\n';
        i += change + 1;
    }
    int a = rnd.next(1ll, n);
    cout << 2 << " " << a << '\n';
}