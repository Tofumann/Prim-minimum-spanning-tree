// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<random>
#include<queue>


#include"CalculateAverageDis.h"
#define INF 999999
using namespace std;


int main() {
    Graph g("sampledata.txt");
    g.prim(g);
    //Graph g(50);

    /*week 2 task*/
    /*
    int num_of_node = 50; 
    float density = 0.2;
    int num_of_graph = 2;
    CalculateAverageDis c;
    //need 1-2 minites to run the result
    float result = c.calculate_average_distance(num_of_node, density, num_of_graph);
    cout << "50 nodes,20%density,2 graph's average distance is" << result << endl;
    density = 0.4;
    result = c.calculate_average_distance(num_of_node, density, num_of_graph);
    cout << "50 nodes,40%density,2 graph's average distance is" << result << endl;
    return 0;
    */

  
    
    //test  class pass
    //Graph g(50);
    //ShortestPath p(g);
    //PriorityQueue pq();

    //test add edge pass
    //Graph g2=c.create_random_graph(num_of_node, density);
    //Graph g2(50);
    //g2.add(g2, 1, 4, 3);
    //g2.add(g2, 4, 5, 1);
    //g2.add(g2, 1, 5, 5);
    //ShortestPath s2(g2);
    //int re = g2.V(g2);//pass
    //cout<<re;
    //cout << **g2.C(g2);
    //g2.add(g2, 1, 2);
    /*
    for (int i = 0; i < re; i++) {
        for (int j = 0; j < re; j++) {
            cout << g2.C(g2)[i][j] << " ";
        }
    }*/
    //cout << g2.E(g2);
    //cout << g2.get_edge_value(g2,1, 5);

    //test PriorityQueue pass
    /*
    PriorityQueue pq2;
    pair<int, float> pair1(1, 1.0);
    pair<int, float> pair2(2, 6.0);
    pair<int, float> pair3(23, 2.0);
    pair<int, float> pair4(4, 4.0);
    pq2.insert(pq2, pair1);
    pq2.insert(pq2, pair2);
    pq2.insert(pq2, pair3);
    pq2.insert(pq2, pair4);
    cout << pq2.size(pq2);
    
    pq2.chgPriority(pq2, 1, 10);
    
    if (pq2.contains(pq2, pair3)) {
        cout << "succ";
    }
    else {
        cout << "fail";
    }
    
    pair4 = pq2.top(pq2);
    pq2.minPriority(pq2);
    cout << pair4.first <<" " << pair4.second<<endl;
    pair4 = pq2.top(pq2);
    pq2.minPriority(pq2);
    cout << pair4.first << " " << pair4.second << endl;
    pair4 = pq2.top(pq2);
    pq2.minPriority(pq2);
    cout << pair4.first << " " << pair4.second << endl;
    pair4 = pq2.top(pq2);
    //cout << pq2.size(pq2);
    pq2.minPriority(pq2);
    cout << pair4.first << " " << pair4.second << endl;
    cout << pq2.size(pq2);
    
    */
    //vector<int> vec=s2.path(1,4);
    //vector<int> vec = g2.neighbors(g2, 1);
    //float vec_size = s2.path_size(1, 5);
    //cout << vec_size;
    //vector<int> v2 = s2.vertices();
    //for_each(vec.cbegin(), vec.cend(), [](const int& val)->void {cout << val << endl; });
    //for_each(v2.cbegin(), v2.cend(), [](const int& val)->void {cout << val << endl; });


    

    


}