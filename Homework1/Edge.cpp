//
//  Edge.cpp
//  Homework1
//
//  Created by Peter Trebing on 17.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include "Edge.h"


int Edge::either(){
	return v;
}

int Edge::other(int vertex){
	if (vertex== v) {
		return w;
	} else {
		return v;
	}
}

double Edge::weight(){
	return cost;
}

bool Edge::operator< (const Edge& other) {
	return this->cost < other.cost;
};