#include "graph.h"
#include "iostream"
#include <vector>

using namespace std;

Graph::Graph()
{

}


void Graph::setGraph(int **adjacencyArray, int size)
{
    arrayAdjac = new int*[size];
    nodes_ = new Node[size];

    for(int i = 0; i < size; i++)
    {
        Node node;
        node.weight = INT_MAX;
        node.isCheck = false;
        node.connectNodeIndex = INT_MAX;

        nodes_[i] = node;
        arrayAdjac[i] = new int[size];

        for(int j = 0; j < size; j++)
            arrayAdjac[i][j] = adjacencyArray[i][j];
    }
}

int *Graph::findWay_deycstra(int startNode, int endNode, int &resultSize)
{
    Node nodes[6];

    for(int i = 0; i < 6; i++)
    {
        Node node;
        node.weight = nodes_[i].weight;
        node.isCheck = nodes_[i].isCheck;
        node.connectNodeIndex = nodes_[i].connectNodeIndex;

        nodes[i] = node;
    }

    nodes[startNode].weight = 0;


    for(;;) //перебираем все узлы
    {
        int currentIndex = getMinNodeIndex(nodes); //находим узел с мин весом, который еще не смотрели

        if(currentIndex != endNode)
        {
            for(int i = 0; i < 6; i++) // перебираем все дуги для текущего узла
                if(arrayAdjac[currentIndex][i] > 0)
                {
                    int newWeight = nodes[currentIndex].weight + arrayAdjac[currentIndex][i];

                    if (newWeight < nodes[i].weight)
                    {
                        nodes[i].weight = newWeight;
                        nodes[i].connectNodeIndex = currentIndex;
                    }
                }

            nodes[currentIndex].isCheck = true;
        }
        else
            break;
    }


    int index = endNode;
    vector<int> res;

    auto it = res.begin();
    while (index != startNode)
    {
        it = res.insert(it, index);
        index = nodes[index].connectNodeIndex;
    }
    it = res.insert(it, startNode);

    resultSize = res.size();
    return &res[0];
}


int Graph::getMinNodeIndex(Node *nodes)
{
    int minWeight = INT_MAX;
    int minIndex = INT_MAX;

    for(int i = 0; i < 6; i++)
        if(!nodes[i].isCheck && nodes[i].weight < minWeight)
        {
            minWeight = nodes[i].weight;
            minIndex = i;
        }

    return minIndex;
}
