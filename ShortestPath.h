#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<random>
#include<queue>
#include"PriorityQueue.h"
#include"Graph.h"

using namespace std;

class ShortestPath {
public:
    ShortestPath( Graph & G);
    //~ShortestPath();
    vector<int>vertices();
    vector<int>path(int u, int w);
    float path_size(int u, int w);

private:
     Graph&  graph;
};