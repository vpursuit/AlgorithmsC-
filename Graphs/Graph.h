//
//  Graph.h
//  Homework2
//
//  Created by Peter Trebing on 02.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#ifndef __Homework1__Graph__
#define __Homework1__Graph__

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

#endif /* defined(__Homework1__Graph__) */

class Graph {
    
public:
    
    static Graph *createFromStream(istream& in);
    static Graph *createFromFile(string file_name);
    static Graph *createRandomGraph(int size, double density, double minCost, double maxCost);
    
    Graph(int size = 50):adjacences(size), nodeValues(), edgeValues() {}
    
    /*
     * V (G): returns the number of vertices in the graph
     */
    unsigned long V();
    
    /*
     * E (G): returns the number of edges in the graph
     */
    unsigned long E();
    
    /*
     * adjacent (G, x, y): tests whether there is an edge from node x to node y.
     */
    bool adjacent(int x, int y);
    
    /*
     * neighbors (G, x): lists all nodes y such that there is an edge from x to y.
     */
    vector<int> neighbourgs(int x);
    
    /*
     * add (G, x, y): adds to G the edge from x to y, if it is not there.
     */
    void add(int x, int y);
    
    /*
     * delete (G, x, y): removes the edge from x to y, if it is there.
     */
    void remove(int x, int y);
    
    /*
     * get_node_value (G, x): returns the value associated with the node x.
     */
    double get_node_value(int x);
    
    /*
     * set_node_value( G, x, a): sets the value associated with the node x to a.
     */
    void set_node_value(int x, double a);
    
    /*
     * get_edge_value( G, x, y): returns the value associated to the edge (x,y).
     */
    double get_edge_value(int x, int y);
    
    /*
     * set_edge_value (G, x, y, v): sets the value associated to the edge (x,y) to v.
     */
    void set_edge_value(int x, int y, double v);
    
    
private:
    map<int, double> nodeValues;
    map<pair<int,int>, double> edgeValues;
    
    // follow adjacent list implementation
    vector<set<int>> adjacences;
    
};