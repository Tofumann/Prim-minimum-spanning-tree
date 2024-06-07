#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<random>
#include<queue>
using namespace std;

class PriorityQueue {
public:
    //PriorityQueue();
    //~PriorityQueue();
    void chgPriority(PriorityQueue PQ, int loc, float priority);
    void minPriority(PriorityQueue PQ);
    bool contains(PriorityQueue PQ, pair<int, float> queue_element);
    void insert(PriorityQueue PQ, pair<int, float> queue_element);
    pair<int, float> top(PriorityQueue PQ);
    int size(PriorityQueue PQ);
    float getPriority(PriorityQueue PQ, int loc);

private:
    map<int, float> q;
};

