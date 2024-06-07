#pragma once
#include"Graph.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<random>
#include<iterator>
#include<fstream>


using namespace std;



#define INF 999999



Graph::Graph() {
    int node_number = 50;
    this->con_matrix = new float* [node_number];
    for (int i = 0; i < node_number; i++) {
        this->con_matrix[i] = new float[node_number];
        for (int j = 0; j < node_number; j++) {
            //initialize con_matrix to INF(999999) means that not connective
            this->con_matrix[i][j] = INF;
        }
    }
    this->vertex_num = node_number;
    this->edge_num = 0;
}
Graph::Graph(int node_number) {
    this->con_matrix = new float* [node_number];
    for (int i = 0; i < node_number; i++) {
        this->con_matrix[i] = new float[node_number];
        for (int j = 0; j < node_number; j++) {

            this->con_matrix[i][j] = INF;
        }
    }
    this->vertex_num = node_number;
    this->edge_num = 0;
}

/*
Graph::~Graph() {
    for (int i = 0; i < vertex_num; i++) {
        delete[] this->con_matrix[i];
    }
    delete[] this->con_matrix;

    //this->node_maps.clear();
}
*/
int Graph::V(Graph G) {
    return this->vertex_num;
}
int Graph::E(Graph G) {
    return this->edge_num;
}

float** Graph::C(Graph G) {
    return this->con_matrix;
}
bool Graph::adjacent(Graph G, const int x, const int y) {
    if (this->con_matrix[x][y] == INF)
        return false;
    else
        return true;
}

vector<int>Graph::neighbors(Graph G, const int x) {
    vector<int> neigh_vector;
    for (int i = 0; i < this->vertex_num; i++) {
        if (this->con_matrix[x][i] != INF) {
            neigh_vector.push_back(i);
        }
    }
    return neigh_vector;
}

void Graph::add(Graph G, const int x, const int y,const float value) {
    //create a random distance between min and max
    if (this->con_matrix[x][y] == INF) {
        this->con_matrix[x][y] = value;
        this->con_matrix[y][x] = value;
        this->edge_num++;
    }





}

void Graph::delete_edge(Graph G, const int x, const int y) {
    if (this->con_matrix[x][y] != INF) {
        this->con_matrix[x][y] = INF;
        this->con_matrix[y][x] = INF;
        this->edge_num--;
    }
}

char Graph::get_node_value(Graph G, const int x) {
    return this->node_maps[x];
}

void Graph::set_node_value(Graph G, int x, char a) {
    this->node_maps[x] = a;
}

float Graph::get_edge_value(Graph G, const int x, const int y) {
    for (int i = 0; i < V(G); i++) {
        for (int j = 0; j < V(G); j++) {
            if (x == i && y == j) {
                return this->con_matrix[x][y];
            }
        }
    }
    return INF;
}

void Graph::set_edge_value(Graph G, const int x, const int y, float v) {
    this->con_matrix[x][y] = v;
    this->con_matrix[y][x] = v;

}


Graph::Graph(const char filename[]) {
    ifstream input_file(filename);
    istream_iterator<int> start(input_file), end;
    vector<int> stats(start, end);
    
    
    int node_number =stats[0];
    
    this->con_matrix = new float* [node_number];
    for (int i = 0; i < node_number; i++) {
        this->con_matrix[i] = new float[node_number];
        for (int j = 0; j < node_number; j++) {

            this->con_matrix[i][j] = INF;
        }
    }
    this->vertex_num = node_number;
    this->edge_num = 0;


    
    for (int i = 1; i < size(stats)-1; i += 3) {

        this->con_matrix[stats[i]][stats[i+1]] = stats[i+2];
        this->con_matrix[stats[i+1]][stats[i]] = stats[i + 2];
        this->edge_num++;


    }
    
}


void Graph::prim(Graph G) {
    int node_num = this->vertex_num;
    float* cost = new float[node_num];
    bool *v_set = new bool[node_num];
    int sum_cost=0;
    for (int i = 0; i < node_num; i++) {
        cost[i] = INF;
        v_set[i] = false;

    }
    cost[0] = 0;
    v_set[0] = true;
    cout << "the MST's edges are:" << endl;
    for (int i = 1; i < node_num; i++) {
        if (cost[i] > this->con_matrix[0][i]) {
            cost[i] = this-> con_matrix[0][i];
        }
    }
    for (int i = 1; i < node_num; i++) {
        float temp_cost = INF;
        int temp_node = -1;
        int temp_parent = -1;
        for (int j = 1; j < node_num; j++) {
            if (!v_set[j] && cost[j] < temp_cost) {
                temp_cost = cost[j];
                temp_node = j;
                
            }
        }

        if (temp_node == -1) {
            sum_cost = INF;
            return;
        }
        v_set[temp_node] = true;
        sum_cost += cost[temp_node];
        for (int j = 0; j < node_num; j++) {
            if (v_set[j]&&(cost[temp_node] == this->con_matrix[temp_node][j])) {
                temp_parent = j;
            }
        }
        cout <<temp_parent<<" to "<< temp_node << " value is:" << cost[temp_node] << endl;
        for (int j = 1; j < node_num; j++) {
            if (cost[j] > this->con_matrix[temp_node][j]) {
                cost[j] = this->con_matrix[temp_node][j];
            }
        }
    }
    cout <<"the MST's cost sum is:"<< sum_cost << endl;


}
