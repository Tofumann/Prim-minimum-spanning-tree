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


class CalculateAverageDis{
public:

    Graph create_random_graph(int num_of_vertices, float densities);
    float calculate_average_distance(int num_of_vertices, float densities, int num_of_graph);


};