#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <string>


#include "graph.h"


using namespace GP_GRAPH;

int main() {




    std::vector<std::pair<int,int>> edges = {{1,2},{2,3},{1,4},{1,5},{4,5},{3,2},{3,5},{5,6},{1,6},{5,1}};
    std::vector<int> vertices = {1,2,3,4,5,6};

    Graph g(vertices,edges);

    g.printAdjList();








}
