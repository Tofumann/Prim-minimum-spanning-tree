#pragma once
#include<iostream>
#include"PriorityQueue.h"
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<random>
#include<queue>
using namespace std;
#define INF 999999
bool cmp(const pair<int, float> left, const pair<int, float> right) {
    return left.second < right.second;
}
/*
typedef struct Node
{
    int index;
    float min_dist;
}Node;
*/

/*
PriorityQueue::PriorityQueue() {
    map<int, float> qcopy;
    this->q = qcopy;
}

PriorityQueue::~PriorityQueue() {
    //this->q.clear();
}
*/
void PriorityQueue::chgPriority(PriorityQueue PQ, int loc, float priority) {
    this->q[loc] = priority;
}

void PriorityQueue::minPriority(PriorityQueue PQ) {
    /*float min = INF;
    
    for (map<int, float>::iterator it = this->q.begin(); it != this->q.end(); ++it) {
        if (it->second < min ) {
            min = it->second;
        }
    }
    for (map<int, float>::iterator it = this->q.begin(); it != this->q.end(); ++it) {
        if (it->second == min ) {
            this->q.erase(it);
        }
    }
    */
    if (this->size(PQ) > 0) {
        auto it = min_element(this->q.begin(), this->q.end(), cmp);
        this->q.erase(it);
    }


}

bool PriorityQueue::contains(PriorityQueue PQ, pair<int, float> queue_element) {
    for (auto it = this->q.begin(); it != this->q.end(); ++it) {
        if (it->first == queue_element.first) {
            return true;
        }
    }
    return false;
}


void PriorityQueue::insert(PriorityQueue PQ, pair<int, float> queue_element) {
    
    //this->q.insert(queue_element);
    this->q[queue_element.first] = queue_element.second;
}


pair<int, float> PriorityQueue::top(PriorityQueue PQ) {
    //float min = INF;
    pair<int, float> ans(0, INF);
    /*
    for (map<int, float>::iterator it = this->q.begin(); it != this->q.end(); ++it) {
        if (it->second < min) {
            min = it->second;
        }
    }

    for (map<int, float>::iterator it = this->q.begin(); it != this->q.end(); ++it) {
        if (it->second == min) {
            
            ans.first = it->first;
            ans.second = it->second;
            
        }
    }

    
*/
    if (this->size(PQ) > 0) {
        auto it = min_element(this->q.begin(), this->q.end(), cmp);
        ans.first = it->first;
        ans.second = it->second;
        //ans = *it;
    }

    return ans;
}

int PriorityQueue::size(PriorityQueue PQ) {
    return this->q.size();
}


float PriorityQueue::getPriority(PriorityQueue PQ, int loc) {
    return this->q[loc];
}