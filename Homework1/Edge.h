//
//  Edge.h
//  Homework1
//
//  Created by Peter Trebing on 17.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#ifndef __Homework1__Edge__
#define __Homework1__Edge__

#include <iostream>

#endif /* defined(__Homework1__Edge__) */

class Edge {
    
public:
	Edge(int v = 0, int w = 0, double cost = 0.0):v(v), w(w), cost(cost) {};
    
	int either();
	int other(int vertex);
	double weight();
    
	bool operator < (const Edge& other);
    
private:
	int v, w;
	double cost;
};