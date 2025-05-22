#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

string randString(){
	string s = "";
	int len = rnd.next(1, 10);
	for (int j = 0; j < len; j++){
		s.push_back( 'a' + rnd.next(0, 25) );
	}
	return s;
}

main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int q = opt<int>("q");
    int trainerCnt = opt<int>("trainerCnt");
    int canReuseNames = opt<int>("canReuseNames");
    int chanceQuery = opt<int>("chanceQuery");
    int labsUsed = opt<int>("labsUsed");
    
    cout << q << '\n';

	vector<string> names;
	vector<int> labs;
	
	unordered_set<string> usedNames;
	
	for (int i = 0; i < trainerCnt; i++){
		
		string s;
		do {
			s = randString();
		} while (usedNames.count(s));
		
		names.push_back(s);
		usedNames.insert(s);
	}
	
	for (int i = 0; i < labsUsed; i++){
		labs.push_back( rnd.next(1, 100'000) );
	}
	
	unordered_set<int> usedIndices;
	int trainersMoved = 0;
    for (int i = 0; i < q; i++) {
		
		int chance = rnd.next(1, 100);
        int t = 1;
		if (chance <= chanceQuery){
			t = 2;
		}
		
        cout << t << " ";
        if (t == 1 && (trainersMoved < (int)names.size() || canReuseNames) ) {
			
			int lab = labs[ rnd.next(0, (int)labs.size() - 1) ];
			
			int trainerIndex = -1;
			do {
				trainerIndex = rnd.next(0, (int)names.size() - 1);
			} while ( (!canReuseNames) && usedIndices.count(trainerIndex) > 0 );
			
            cout << names[trainerIndex] << " " << lab << '\n';
            
            usedIndices.insert(trainerIndex);
            trainersMoved++;
        } else {
            
			int lab = labs[ rnd.next(0, (int)labs.size() - 1) ];
            cout << lab << '\n';
        }
    }
}
