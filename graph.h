#ifndef GRAPH_H
#define GRAPH_H


class Graph
{
private:
    struct Node
    {
        int weight;
        bool isCheck;
        int connectNodeIndex;
    };

    Node *nodes_;
    int **arrayAdjac;

    int getMinNodeIndex(Node *nodes);
public:
    explicit Graph();
    int *findWay_deycstra(int startNode, int endNode, int &resultSize);
    void setGraph(int **adjacencyArray, int size);
};

#endif // GRAPH_H
