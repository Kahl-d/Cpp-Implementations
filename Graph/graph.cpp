//
// Created by Khalid Khan on 12/5/23.
//

// TODO: Implement the following:
//Declare a class Graph                                                                             [X] DONE
//Adopt the adjacency list representation                                                           [X] DONE
//Represent each adjacency list as a “raw pointer”-based singly linked list                         [X] DONE
//Include and implement the big-3
//Member functions to construct a graph such as adding vertices and edges                           [X] DONE
//Implement the BFS algorithm on Slide 7
//Print out the BFS-tree from a given source vertex
//Print the shortest path from s to v by implement the recursive algorithm on Slide 10


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
#include <set>

#include "graph.h"

namespace GP_GRAPH{

//    ---------------------------------------------------------------------------------
//    ------------------NODE STRUCT IMPLEMENTATION ------------------------------------
//    ---------------------------------------------------------------------------------

// Overloeaded == operator for Node Struct

    bool operator==(const Node& n1, const Node& n2){
        return n1.vertex == n2.vertex;

    }

    // Overloaded < operator for Node Struct
    bool operator<(const Node& n1, const Node& n2) {
        return n1.vertex < n2.vertex;
    }

    // Overloading Assignment Operator for Node Struct


//    ---------------------------------------------------------------------------------
//    ------------------LINKED LIST IMPLEMENTATION ------------------------------------
//    ---------------------------------------------------------------------------------

    // Default Constructor
    LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0){}


    // Destructor
    LinkedList::~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }



//    ---------------------------------------------------------------------------------
//    ------------------ SPECIAL FUNCTION ---------------------------------------------
//    ------------------  addUniqueNode -----------------------------------------------
//    ---------------------------------------------------------------------------------

    // -- used to add a node to the linked list
    // --- come handy with the adjacency list

    void LinkedList::addUniqueNode(Node* v){
      // if the list is empty

        if(head == nullptr){
            head = v;
            tail = v;
            size++;
            return;
        }

// if the list is not empty
        bool found = false;
        Node* temp = head;
        while(temp != nullptr){
            if(temp->vertex == v->vertex){
                found = true;
                break;
            }
            temp = temp->next;
        }

        if(!found){
            tail->next = v;
            tail = v;
            size++;
        }




    }



    // printList Function
    // -- used to print the linked list
    // --- used in printing the adjacency list

    void LinkedList::printList(){
        Node* temp = head;
        while(temp != nullptr){
            std::cout << temp->vertex << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

//    ---------------------------------------------------------------------------------
//    ---------------------------------------------------------------------------------
//    ------------------ GRAPH CLASS IMPLEMENTATION -----------------------------------
//    ---------------------------------------------------------------------------------
//    ---------------------------------------------------------------------------------



    //Default Constructor
    Graph::Graph(){
        // empty vertices vector
        vertices = std::set<Node>();
        // empty edges vector
        edges = std::vector<std::pair<int, int>>();
        // empty adjacency list
        adjList = std::vector<LinkedList>();


    }

    // Graph Constructor
    // given = EDGES

    Graph::Graph(std::vector<std::pair<int, int>> edgeList) {

        for (int i = 0; i < edgeList.size(); i++) {
            Node v1;
            v1.vertex = edgeList[i].first;
            Node v2;
            v2.vertex = edgeList[i].second;

            vertices.insert(v1);
            vertices.insert(v2);

        }

       edges.resize(edgeList.size());
       for (int i = 0; i < edgeList.size(); i++) {
           edges[i].first = edgeList[i].first;
           edges[i].second = edgeList[i].second;

       }




        updateAdjList();

    }



    // Graph Constructor
    // given = VERTICES and EDGES
    // given as LISTS

    Graph::Graph(std::vector<int> vertexList, std::vector<std::pair<int, int>> edgeList){

        edges.resize(edgeList.size());
        for (int i = 0; i < edgeList.size(); i++) {
            edges[i].first = edgeList[i].first;
            edges[i].second = edgeList[i].second;

        }

        for( int vertex: vertexList){
            Node v;
            v.vertex = vertex;
            vertices.insert(v);
        }

        updateAdjList();
    }



    //addEdge member Function

    void Graph::addEdge(int v1, int v2){
        // make a pair given two vertices
        Node v1Node;
        v1Node.vertex = v1;
        Node v2Node;
        v2Node.vertex = v2;

        std::pair<int, int> edge = std::make_pair(v1, v2);
        edges.push_back(edge);

        vertices.insert(v1Node);
        vertices.insert(v2Node);
        updateAdjList();
    }


    //addNode Function

    void Graph::addNode(int v){
       Node newNode;
         newNode.vertex = v;
         vertices.insert(newNode);
    }


//    ---------------------------------------------------------------------------------
//    ------------------ UPDATE ADJACENCY LIST IMPLEMENTATION -------------------------
//    ---------------------------------------------------------------------------------

//    - updates on every new edge added to the graph

    // updateing Adjacency List of a graph Object
    // - useful when adding new edges to a graph
    // -- or when creating a graph from a list of edges
    // --- serves as a function to get the adjacency list of a graph

    void Graph::updateAdjList() {
        // Clearing the adjacency list
        adjList.clear();

        // Creating a linked list for each vertex
        for (const Node& v : vertices) {
            LinkedList newList;
            adjList.push_back(newList);
        }

        // Adding nodes to the adjacency list
        for (const auto& edge : edges) {
            auto v1Iter = vertices.find(Node{edge.first});
            auto v2Iter = vertices.find(Node{edge.second});

            if (v1Iter != vertices.end()) {
                const Node& v1 = *v1Iter;
                adjList[v1.vertex - 1].addUniqueNode(const_cast<Node*>(&v1));
            }

            if (v2Iter != vertices.end()) {
                const Node& v2 = *v2Iter;
                adjList[v2.vertex - 1].addUniqueNode(const_cast<Node*>(&v2));
            }
        }
    }



    // Print Adjacency List Function

    void Graph::printAdjList(){
        for(int i = 0; i < adjList.size(); i++){
            std::cout << i + 1 << " : ";
            adjList[i].printList();
        }
    }


    // Destructor
    Graph::~Graph(){

    }



    // ---------------------------------------------------------------------------------
    // ------------------ BFS IMPLEMENTATION --------------------------------------------
    // ---------------------------------------------------------------------------------

    // BFS Algorithm
    // - takes a source vertex as an argument
    // -- prints the BFS tree from the source vertex

    void Graph::BFS(int s){

    }






}// namespace GP_GRAPH










#endif //GRAPH_H