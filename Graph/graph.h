//
// Created by Khalid Khan on 12/5/23.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <set>

namespace GP_GRAPH{

    // enum for color
    // A node can be white, gray or black
    enum class Color{
        WHITE,
        GRAY,
        BLACK
    };



    // Node Data Structure
    struct Node{
        int vertex;
        Node* next{nullptr};
        Color color{Color::WHITE};
        int distance{0};
        Node* parent{nullptr};
    };

    // class Linked List to work with adjacency List

    class LinkedList {
    public:
        // Default Constructor
        LinkedList();
        //Destructor
        ~LinkedList();

        void addUniqueNode(Node* v);
        void printList();



    private:
        Node* head;
        Node* tail;
        int size;
    };

    // Class Graph
    class Graph {
    public:

        // Graph Constructors
        //Deafult Constructor
        Graph();

        //Constructor with edges
        Graph(std::vector<std::pair<int, int>> edges);

        //Construcotr with vertices and edges
        Graph(std::vector<int> vertexList, std::vector<std::pair<int, int>> edgeList);


        // Internal Graph Member Functions
        ~Graph();
        void addEdge(int v1, int v2);
        void addNode(int v);
        void updateAdjList();

         // Getters
         void printAdjList();


         // Algorithms
         // BFS

         void BFS(int s);



    private:
        std::set<Node> vertices;
        std::vector<std::pair<int, int>> edges;

        // Adjacency List
        // Using a linked list helps easy insertion and deletion
        // also helps with destroying because Linked List has a destructor
        std::vector<LinkedList> adjList;



    };




}

#endif //GRAPH_GRAPH_H
