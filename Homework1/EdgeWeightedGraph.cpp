//
//  EdgeWeightedGraph.cpp
//  Homework1
//
//  Created by Peter Trebing on 17.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <assert.h>

#include "EdgeWeightedGraph.h"

class edge_iterator: public iterator<forward_iterator_tag, Edge> {
    
public:
    
	edge_iterator(vector<forward_list<Edge>> adjacences, int v = 0) {
		offset = v;
		adj = adjacences;
		actAdj = adj.begin()+offset;
		actEdge = (*actAdj).begin();
        
	};
    
	Edge& operator*() {
		return *actEdge;
	}
    
	const edge_iterator& operator++() {
		if (actEdge != (*actAdj).end()) {
			actEdge++;
		} else {
			if ((offset == 0) && (actAdj != adj.end())) {
				actAdj++;
			}
		}
		return *this;
	}
    
	bool operator!=(const edge_iterator& other) const {
		return (this->actEdge == other.actEdge);
	}
    
private:
    
	vector<forward_list<Edge>> adj;
	forward_list<Edge> edges;
    
	forward_list<Edge>::iterator actEdge;
	vector<forward_list<Edge>>::iterator actAdj;
    
	int offset;
    
};

EdgeWeightedGraph::EdgeWeightedGraph(int V){
    assert(V > 0);
    edge_no = 0;
    adjacences = vector<forward_list<Edge>>(V, forward_list<Edge>());
};

EdgeWeightedGraph *EdgeWeightedGraph::createFromFile(string file_name) {
    
    ifstream infile(file_name, ifstream::in);
    
    if ( (infile.rdstate() & ifstream::failbit ) != 0 ) {
        cerr << "Error opening " << file_name << endl;
        return nullptr;
    }
    
    return EdgeWeightedGraph::createFromStream(infile);
    
}

EdgeWeightedGraph *EdgeWeightedGraph::createFromStream(istream& in){
    
    EdgeWeightedGraph *result = nullptr;
    
    // containing the actual read line
    string line;
    
    // readline number of vertices from first line
    getline(in, line);
    istringstream iss(line);
    int vertex_number = 0;
    iss >> vertex_number;
    
    // if number of vertices gt 0 try to read vertex triples (i,j,cost)
    if (vertex_number > 0) {
        
        result = new EdgeWeightedGraph(vertex_number);
        int key, other, cost;
        
        while (getline(in, line))
        {
            istringstream iss(line);
            if ((iss >> key) && (iss >> other) && (iss >> cost)) {
                result->addEdge(Edge(key, other, cost));
            }
            
        }
    }
    return result;
    
}

void EdgeWeightedGraph::addEdge(Edge e){
	edge_no++;
	int v = e.either();
	int w = e.other(v);
	adjacences[v].push_front(e);
	adjacences[w].push_front(e);
}

int EdgeWeightedGraph::E(){
	return edge_no;
}


int EdgeWeightedGraph::V(){
	return adjacences.size();
}

iterator<forward_iterator_tag, Edge>EdgeWeightedGraph::adj(int v) {
	return edge_iterator(adjacences, v);
}

iterator<forward_iterator_tag, Edge> EdgeWeightedGraph::edges(){
	return edge_iterator(adjacences);
}