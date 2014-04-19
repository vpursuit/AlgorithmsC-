//
//  Graph.cpp
//  Homework1
//
//  Created by Peter Trebing on 02.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include "Graph.h"
#include <random>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Graph *Graph::createFromStream(istream& in){
    
    Graph *result = nullptr;
    
    // containing the actual read line
    string line;
    
    // readline number of vertices from first line
    getline(in, line);
    istringstream iss(line);
    int vertex_number = 0;
    iss >> vertex_number;
    
    // if number of vertices gt 0 try to read vertex triples (i,j,cost)
    if (vertex_number > 0) {
        
        result = new Graph(vertex_number);
        int key, other, cost;
        
        while (getline(in, line))
        {
            istringstream iss(line);
            if ((iss >> key) && (iss >> other)) {
                result->add(key, other);
                // if cost is given, read and set edge value
                if ( iss >> cost) {
                    result->set_edge_value(key, other, static_cast<double>(cost));
                }
            }
            
        }
    }
    return result;
    
}

Graph *Graph::createFromFile(string file_name) {
    
    ifstream infile(file_name, ifstream::in);
    
    if ( (infile.rdstate() & ifstream::failbit ) != 0 ) {
        cerr << "Error opening " << file_name << endl;
        return nullptr;
    }

    return Graph::createFromStream(infile);
    
}

Graph *Graph::createRandomGraph(int size, double density, double minCost, double maxCost) {
    
    Graph *result = new Graph(size);
    
    // construct a trivial random generator engine from a time-based seed:
    unsigned int seed = static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<double> unif(0.0, 1.0);
    uniform_real_distribution<double> range(minCost, maxCost);
    default_random_engine generator (seed);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double r = unif(generator);
            if (i != j && r < density) {
                //add edgein both directions to create an undirected graph
                result->add(i, j);
                result->set_edge_value(i, j, range(generator));
                result->add(j, i);
                result->set_edge_value(j, i, range(generator));
            }
        }
    }
    cout << endl;
    
    return result;
}

unsigned long Graph::V(){
    return adjacences.size();
}

/*
 * E (G): returns the number of edges in the graph
 */
unsigned long Graph::E(){
    unsigned long result = 0;
    for (unsigned int i = 0; i < adjacences.size(); i++) {
        result += adjacences[i].size();
    }
    return result;
}

/*
 * adjacent (G, x, y): tests whether there is an edge from node x to node y.
 */
bool Graph::adjacent(int x, int y){
    bool result = false;
    if (x < adjacences.size()) {
        set<int> neighbourgs = adjacences[x];
        result = (adjacences[x].find(y) != neighbourgs.end());
    }
    return result;
}

/*
 * neighbors (G, x): lists all nodes y such that there is an edge from x to y.
 */
vector<int> Graph::neighbourgs(int x){
    vector<int> result = vector<int>();
    set<int> neighbourgs = adjacences[x];
    for(set<int>::iterator it = neighbourgs.begin(); it != neighbourgs.end(); it++){
        result.push_back(*it);
    }
    return result;
}

/*
 * add (G, x, y): adds to G the edge from x to y, if it is not there.
 */
void Graph::add(int x, int y){
    adjacences[x].insert(y);
}

/*
 * delete (G, x, y): removes the edge from x to y, if it is there.
 */
void Graph::remove(int x, int y){
    adjacences[x].erase(y);
}

/*
 * get_node_value (G, x): returns the value associated with the node x.
 */
double Graph::get_node_value(int x){
    return nodeValues[x];
}

/*
 * set_node_value( G, x, a): sets the value associated with the node x to a.
 */
void Graph::set_node_value(int x, double a){
    nodeValues[x] = a;
}

/*
 * get_edge_value( G, x, y): returns the value associated to the edge (x,y).
 */
double Graph::get_edge_value(int x, int y){
    return edgeValues[make_pair(x, y)];
}

/*
 * set_edge_value (G, x, y, v): sets the value associated to the edge (x,y) to v.
 */
void Graph::set_edge_value(int x, int y, double v){
    edgeValues[make_pair(x, y)] = v;
}