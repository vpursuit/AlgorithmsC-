
//
//  ShortestPath.cpp
//  Homework2
//
//  Created by Peter Trebing on 02.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include <limits>
#include "ShortestPath.h"

using namespace std;

double ShortestPath::path_size(){
    
    if (!is_initialized) {
        
        is_initialized = true;
        pSize = numeric_limits<double>::infinity();
        
        auto prev = -1;
        for (auto act: shortestPath) {
            if (prev > -1) {
                pSize += graph->get_edge_value(prev, act);
            } else {
                pSize = 0.0;
            }
            prev = act;
        }
      
    }
    return pSize;
    
}

vector<int> ShortestPath::get_path(){
    return shortestPath;
}

void ShortestPath::_shortest_path() {
    
    // default result: empty path (no path)
    shortestPath = vector<int>();
    dist = vector<double>(graph->V(), numeric_limits<double>::infinity());
    visited = vector<bool>(graph->V(), false);
    previous = vector<int>(graph->V(), -1);
        
    // start with node u
    dist[u] = 0.0;
    pq.insert(u, 0.0);
    
    while (pq.size() > 0) {
        
        unsigned int q = pq.top();
        
        if (q != w) { // path not yet found
            
            pq.pop(); // remove from queue
            visited[q] = true;
            
            vector<int> qNeighbours = graph->neighbourgs(q);
            for (int i = 0; i < qNeighbours.size(); i++) {
                
                int v = qNeighbours[i];
                
                if (!visited[v]) {
                    double alt = dist[q] + graph->get_edge_value(q, v);
                    if (alt < dist[v]) {
                        dist[v] = alt;
                        previous[v] = q;
                        pq.insert(v, alt);
                    }
                    
                }
            }
            
        } else {
            // path found: insert in reverse order into a vector
            int actNode = q;
            while (actNode > -1) {
                shortestPath.insert(shortestPath.begin(), actNode);
                actNode = previous[actNode];
            }
            break;
        }
        
    }
    
}