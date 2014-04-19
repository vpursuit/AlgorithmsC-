//
//  ShortestPath.h
//  Homework2
//
//  Created by Peter Trebing on 02.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#ifndef __Homework1__ShortestPath__
#define __Homework1__ShortestPath__

#include <iostream>
#include <vector>
#include <stack>
#include "PriorityQueue.h"
#include "Graph.h"

using namespace std;

#endif /* defined(__Homework1__ShortestPath__) */


/*
 vertices(List): list of vertices in G(V,E).
 path(u, w): find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w.
 path_size(u, w): return the path cost associated with the shortest path.
 
 */

class ShortestPath {
    
public:
    ShortestPath(Graph *g, int u, int w):graph(g), u(u), w(w), is_initialized(false) {
        _shortest_path();
    };
    
    vector<int> get_path();
    double path_size();
    
private:
    
    void _shortest_path();
    
    Graph *graph;
    int u, w;
    
    vector<double> dist;
    vector<bool> visited;
    vector<int> previous;

    vector<int> shortestPath;
    double pSize;
    bool is_initialized;
    
    PriorityQueue pq;
    
};