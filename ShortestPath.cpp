#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<random>
#include<queue>
#include"ShortestPath.h"

using namespace std;
#define INF 999999



ShortestPath::ShortestPath( Graph & G):graph(G) {
}
/*
ShortestPath::~ShortestPath() {

}
*/
vector<int>ShortestPath::vertices() {
    vector<int> neigh_vector;
    for (int i = 0; i < this->graph.V(this->graph); i++) {
        for (int j = 0; j < this->graph.V(this->graph); j++) {
            if (this->graph.C(this->graph)[i][j] != INF) {
                if (!(find(neigh_vector.begin(), neigh_vector.end(), i) != neigh_vector.end()))
                    neigh_vector.push_back(i);
            }

        }

    }
    return neigh_vector;

}



vector<int>ShortestPath::path(int u, int w) {
    vector<int> vertices_vector = vertices();
    vector<int> my_path;

    map<int, int>pre;
    map<int, bool>visited;
    map<int, float>dis;

    PriorityQueue p;
    int to_add_node;
    pair<int, float> last_node, temp;

    for (auto v : vertices_vector) {
        pre[v] = -1;
        dis[v] = INF;
    }
    dis[u] = 0.0;
    p.insert(p, pair<int, float>(u, 0.0));
    while (p.size(p) > 0) {
        temp = p.top(p);

        p.minPriority(p);
        
        if (visited[temp.first]) {
            continue;
        }
        visited[temp.first] = true;
        vector<int>nei = this->graph.neighbors(graph, temp.first);
        
        for (auto v : nei) {
            if ((visited[v] == false) && (dis[v] >dis[temp.first] + graph.get_edge_value(graph, v, temp.first))) {
                dis[v] = dis[temp.first] + graph.get_edge_value(graph, v, temp.first);
                pre[v] = temp.first;
                p.insert(p, pair<int, float>(v, dis[v]));
                /*
                if (p.contains(p, pair<int, float>(v, dis[v]))) {
                    
                    p.chgPriority(p, v, dis[v]);

                    
                }
                else {
                    //origin place

                }*/
            }
        }
        if (temp.first == w) {
            to_add_node = w;
            while (to_add_node != u) {
                my_path.insert(my_path.begin(), to_add_node);
                to_add_node = pre[to_add_node];
            }
            my_path.insert(my_path.begin(), u);
            return my_path;
        }
    }
}

float ShortestPath::path_size(int u, int w) {
    vector<int> shortest_path = path(u, w);
    float sum = 0;
    for (int i = 0; i < shortest_path.size()-1; i++) {
        sum += graph.get_edge_value(graph, shortest_path[i], shortest_path[i + 1]);
    }
    return sum;
}

