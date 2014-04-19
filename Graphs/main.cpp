//
//  main.cpp
//  Homework2
//
//  Created by Peter Trebing on 27.10.13.
//  Copyright (c) 2013 Peter Trebing. All rights reserved.
//

#include <iostream>
#include "ShortestPath.h"
#include <string>       // std::string
#include <sstream>      // std::istringstream
#include <unistd.h>
#include <math.h>


using namespace std;

void experiment(int size, double density, double minCost, double maxCost){
    
    cout << "Graph size: " << size << " density: " << density << " minCost: " << minCost << " maxCost: " << maxCost;
    
    Graph* g = Graph::createRandomGraph(size, density, minCost, maxCost);
    
    double average = 0.0;
    int samples = 1;
    for (int i = 1; i < size; i++) {
        
        ShortestPath sp(g, 0, i);
        double cost = sp.path_size();
        
        // count sample only if path found (cost < inf)
        if (cost < numeric_limits<double>::infinity()) {
            average += cost;
            samples++;
        }
        
    }
    
    average = average/(double)(samples);
    cout << "Resulting average path cost: " << average << " (samples: " << samples << ")" << endl << endl;
    
}


string getcwd()
{
    char result[ 1024 ];
    return string( getcwd( result, sizeof( result ) ) );
}


int main(int argc, const char * argv[])
{
    
    string sentence, words[10];
    int pos = 0, old_pos = 0, nwords, i = 0;
    sentence = "Eskimos have 23 ways to ";
    sentence += "describe snow";
    while (pos < sentence.size()) {
        pos = sentence.find(' ', old_pos);
        words[i++].assign(sentence, old_pos, pos - old_pos);
        cout << words[i - 1] << endl; //print words
        old_pos = pos + 1;
    }
    nwords = i;
    sentence = "C++ programmers ";
    for (i = 1; i < nwords -1; ++i)
        sentence += words[i] + ' ';
    sentence += "windows";
    cout << sentence << endl;
    
    
    //cout << "Current working directory is: " << getcwd() << endl;

    Graph *g = Graph::createFromFile("/Users/keeper/Documents/hidrive/coursera/C++ForCProgrammers/AlgorithmsCPlusPlus/GraphTests/test_graph0.txt");
 
    cout << "Read graph from file, size: " << g->V() << endl;
    
    ShortestPath sp(g, 0, 19);
    vector<int> path = sp.get_path();
    cout << "Shortest path: " << endl;
    for (auto act: path) {
        cout << act << ", ";
    }
    cout << endl;
    cout << "Costs: " << sp.path_size() << endl;
    
    experiment(50, 0.2, 1.0, 10.0);
    experiment(50, 0.4, 1.0, 10.0);
    
    return 0;
}

