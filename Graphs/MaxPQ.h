//
//  MaxPQ.h
//  Homework1
//
//  Created by Peter Trebing on 17.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include <vector>

#ifndef Homework1_MaxPQ_h
#define Homework1_MaxPQ_h

template <class Key> class MaxPQ {
    
public:
    
	MaxPQ(){
		_init();
	}
    
	MaxPQ(std::vector<Key> a){
		pq = vector<Key>(a.size());
		_init();
		for(auto v: a) {
			insert(v);
		}
	}
	
	void insert(Key v) {
		pq.push_back(v);
		swim(get_size());
	}
    
	Key max(){
		// element 0 of the vector is not used to simplify arithmetic
		return pq[1];
	}
    
	Key del_max(){
		// element 0 of the vector is not used to simplify arithmetic
		Key max = pq[1];
		exch(1, get_size());
		pq.pop_back();
		sink(1);
		return max;
	}
    
	bool is_emtpty(){
		return get_size()==0;
	}
    
	int size(){
		return get_size();
	}
    
private:
    
	std::vector<Key> pq;
    
	// element 0 of the vector is not used to simplify arithmetic
	void _init() {
		pq.push_back(Key());
	}
    
	inline int get_size() {
		return pq.size() - 1;
	}
    
	inline bool less(int i, int j) {
		return pq[i] < pq[j];
	}
    
	inline void exch(int i, int j) {
		Key tmp = pq[i];
		pq[i] = pq[j];
		pq[j] = tmp;
	}
    
	void swim(int k){
		while(k>1 && less(k/2, k)){
			exch(k/2, k);
			k = k/2;
		}
	}
    
	void sink(int k){
		while(2*k <= get_size()) {
			int j = 2*k;
			if (j < get_size() && less(j, j+1)) j++;
			if (!less(k, j)) break;
			exch(k, j);
			k = j;
		}
	}
    
};

#endif
