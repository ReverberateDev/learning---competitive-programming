//#include "testlib.h"
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int max_n = 300'000; //3*10^5
const int max_q = 300'000; //3*10^5
//q queries
//qlogn
main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int q = opt<int>("q");
    int chanceForQuery = opt<int>("queryChance");
    int numOfColours = opt<int>("numOfColours");
    
    cout << n << " " << q << '\n';
    
    vector<int> col;
    for (int i = 0; i < numOfColours; i++){
		col.push_back(rnd.next(1, n));
	}
    
    for(int i = 0; i < q; i++){
        if (rnd.next(1, 100) <= chanceForQuery){
			//query, 10% chance
			cout << "2 " << rnd.next(1, (int)n) << '\n';
		}
		else{
			//update
			int colsel = rnd.next(0, (int)col.size() - 1);
			int colour = col[colsel];
			cout << "1 " << rnd.next(1, (int)n) << ' ' << colour << '\n';;
		}
    }
}
