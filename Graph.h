#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<random>

using namespace std;

class Graph {
public:
    //default node_number=50
    Graph();
    Graph(int node_number);
    //~Graph();
    Graph(const char filename[]);
    int V(Graph G);
    int E(Graph G);
    float** C(Graph G);
    bool adjacent(Graph G, const int x, const int y);
    vector<int> neighbors(Graph G, const int x);
    void add(Graph G, const int x, const int y,const float value);
    /*
    Rename the function delete to delete_edge.Because that delete is a identifier,
    and if override the dele ,the first parameter must be void*,
    and our function's first parameter is Graph.
    */
    void delete_edge(Graph G, const int x, const int y);
    char get_node_value(Graph G, const int x);
    void set_node_value(Graph G, int x, char a);
    float get_edge_value(Graph G, const int x, const int y);
    void set_edge_value(Graph G, const int x, const int y, float v);
    void prim(Graph G);

private:
    //choose connectivity matrices to represent 
    float** con_matrix;

    int vertex_num;
    int edge_num;
    //vector<char> node_values;
    //maps the int to symbol
    std::map<int, char> node_maps;


};