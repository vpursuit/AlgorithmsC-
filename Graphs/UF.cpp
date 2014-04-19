//
//  UF.cpp
//
//  Union find
//  Algorithms Fourth Edition; Robert Sedgewick, Kevin Wayne
//
//  Created by Peter Trebing on 17.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include "UF.h"


/*  UF(int N);
 
 void join(int p, int q); //add connection between p and q
 int find(int p); // component identified for p (0...N)
 bool connected(int p, int q); // return true if p and q belong to the same component
 int count(); // numb

*/

UF::UF(unsigned N){
    id = std::vector<unsigned>(N);
    for (unsigned i = 0; i <N; i++) {
        id[i] = i;
    }
    rank = std::vector<short>(N, 0);
    ucount = 0;
}

/*
 if (p < 0 || p >= id.length) throw new IndexOutOfBoundsException();
 while (p != id[p]) {
 id[p] = id[id[p]];    // path compression by halving
 p = id[p];
 }
 return p;
*/

unsigned UF::find(unsigned p) {
    while (p != id[p]) {
        id[p] = id[id[p]];    // path compression by halving
        p = id[p];
    }
    return p;
}

bool UF::connected(unsigned p, unsigned q){
    return find(p) == find(q);
}

unsigned UF::count(){
    return ucount;
}

void UF::join(unsigned p, unsigned q){
    int i = find(p);
    int j = find(q);
    if (i == j) return;
    
    // make root of smaller rank point to root of larger rank
    if      (rank[i] < rank[j]) id[i] = j;
    else if (rank[i] > rank[j]) id[j] = i;
    else {
        id[j] = i;
        rank[i]++;
    }
    ucount--;
}



