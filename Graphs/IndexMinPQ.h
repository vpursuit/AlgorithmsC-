//
//  IndexMinPQ.h
//  Homework1
//
//  Created by Peter Trebing on 17.11.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include <vector>
#include <array>
#include <assert.h>

#ifndef Homework1_IndexMinPQ_h
#define Homework1_IndexMinPQ_h

template <class Key> class IndexMinPQ {
    
public:
    
	IndexMinPQ(int nMax){
		NMAX = nMax;
		N = 0;
		keys = vector<Key>(NMAX+1);
		pq = vector<int>(NMAX+1, -1);
		qp = vector<int>(NMAX+1, -1);
	}
	
	bool contains(int i) {
		assert(i>=0 && i<NMAX);
		return qp[i] != -1;
	}
    
	void insert(int i, Key v) {
		assert(i>=0 && i<NMAX);
		N++;
		qp[i] = N;
		pq[N] = i;
		keys[i] = v;
		swim(N);
	}
    
	int min_index(){
		assert(N>0);
		return pq[1];
	}
    
	Key min_key(){
		assert(N>0);
		return keys[pq[1]];
	}
    
	int del_min(){
		assert(N>0);
		int min = pq[1];
		exch(1, N--);
		sink(1);
		qp[min] = -1;
		keys[pq[N+1]] = NULL;
		pq[N+1] = -1;
		return min;
	}
    
	Key key_of(int i) {
		assert(i>=0 && i<NMAX && contains(i));
		return keys[i];
	}
    
	void change_key(int i, Key key) {
		assert(i>=0 && i<NMAX && contains(i));
		keys[i] = key;
		swim(qp[i]);
		sink(qp[i]);
	}
    
	void decrease_key(int i, Key key) {
		assert(i>=0 && i<NMAX && contains(i) && keys[i]>=key);
		keys[i] = key;
		swim(qp[i]);
	}
    
	void increase_key(int i, Key key) {
		assert(i>=0 && i<NMAX && contains(i) && keys[i]<=key);
		keys[i] = key;
		sink(qp[i]);
	}
    
	void del(int i) {
		assert(i>=0 && i<NMAX && contains(i));
		int index = qp[i];
		exch(index, N--);
		swim(index);
		sink(index);
		keys[i] = NULL;
		qp[i] = -1;
	}
    
	bool is_emtpty(){
		return N == 0;
	}
    
	int size(){
		return N;
	}
    
private:
	int NMAX;
	int N;
	std::vector<int> pq;
	std::vector<int> qp;
	std::vector<Key> keys;
    
	inline bool greater(int i, int j) {
		return !(keys[pq[i]] < keys[pq[j]]);
	}
    
	inline void exch(int i, int j) {
		int tmp = pq[i];
		pq[i] = pq[j];
		pq[j] = tmp;
		qp[pq[i]] = i;
		qp[pq[j]] = j;
	}
    
	void swim(int k){
		while(k>1 && greater(k/2, k)){
			exch(k, k/2);
			k = k/2;
		}
	}
    
	void sink(int k){
		while(2*k <= N) {
			int j = 2*k;
			if (j < N && greater(j, j+1)) j++;
			if (!greater(k, j)) break;
			exch(k, j);
			k = j;
		}
	}
    
};


#endif
