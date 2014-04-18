//
//  MST.h
//  Homework1
//
//  Created by Peter Trebing on 10.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#ifndef __Homework1__MST__
#define __Homework1__MST__

#include <iostream>
#include <vector>
#include "Graph.h"
#include "PriorityQueue.h"

using namespace std;

#endif /* defined(__Homework1__MST__) */


class MST {
    
public:
    
    MST(Graph *g):graph(g) {
        _mst();
    };
    
    vector<int> get_mst();
    
private:
    
    void _mst();
    
    Graph *graph;
    vector<bool> visited;
    vector<int> mst;
    PriorityQueue pq;
    
};