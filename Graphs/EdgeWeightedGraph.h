//
//  EdgeWeightedGraph.h
//  Homework1
//
//  Created by Peter Trebing on 17.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#ifndef __Homework1__EdgeWeightedGraph__
#define __Homework1__EdgeWeightedGraph__

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <forward_list>
#include "Edge.h"

using namespace std;

class EdgeWeightedGraph {
    
public:
    
    static EdgeWeightedGraph *createFromStream(istream& in);
    static EdgeWeightedGraph *createFromFile(string file_name);
    
	EdgeWeightedGraph(int V); // create empty graph with V vertices
        
	void addEdge(Edge e); // add weighted edge
    
	iterator<forward_iterator_tag, Edge> adj(int v); //edges incident to v
    
	iterator<forward_iterator_tag, Edge> edges(); // all edges in the graph
    
	int V(); // number of vertices
    
	int E(); // number of edges
    
private:
    
	vector<forward_list<Edge>> adjacences;
	int edge_no;
    
};

#endif /* defined(__Homework1__EdgeWeightedGraph__) */
