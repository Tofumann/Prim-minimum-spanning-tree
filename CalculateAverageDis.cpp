#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<random>
#include<queue>

#include"ShortestPath.h"
#include"CalculateAverageDis.h"
using namespace std;

#define INF 999999
#define MAX_DISTANCE 10.0
#define MIN_DISTANCE 1.0
//max_distance and min_distance already added to macro define and add function
// so just need 2 input
Graph CalculateAverageDis::create_random_graph(int num_of_vertices, float densities) {
    Graph g(num_of_vertices);
    std::uniform_real_distribution<float> possible_gen(0, 1);
    std::default_random_engine e_possible(time(0));
    std::uniform_real_distribution<float> distance_gen(MIN_DISTANCE, MAX_DISTANCE);
    std::default_random_engine e_value(time(0));
    for (int i = 0; i < num_of_vertices; i++) {
        for (int j = 0; j < num_of_vertices; j++) {

            if (possible_gen(e_possible) <= densities) {
                g.add(g, i, j,distance_gen(e_value));
            }
        }
    }
    return g;
}


float CalculateAverageDis::calculate_average_distance(int num_of_vertices, float densities, int num_of_graph) {
    float sum = 0.0;
    //in case some graph u to w has no valid path
    int valid_num = 0;
    for (int i = 0; i < num_of_graph; i++) {
        Graph g = create_random_graph(num_of_vertices, densities);
        ShortestPath p = ShortestPath(g);
        for (int j = 1; j < num_of_vertices; j++) {
            float one_path = p.path_size(0, j);
            if (one_path < INF) {
                sum += one_path;
                valid_num++;
            }
        }
    }
    float ave_dis = sum / valid_num;
    return ave_dis;

}