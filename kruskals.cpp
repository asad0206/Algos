#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int source, dest, weight;
};

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int vertex, vector<int> &parent)
{
    if (parent[vertex] == vertex)
    {
        return vertex;
    }
    return findParent(parent[vertex], parent);
}

void unionSets(int x, int y, vector<int> &parent)
{
    int parentX = findParent(x, parent);
    int parentY = findParent(y, parent);
    parent[parentX] = parentY;
}

vector<Edge> kruskal(vector<Edge> edges, int numVertices)
{
    vector<Edge> result;
    vector<int> parent(numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end(), compareEdges);

    for (int i = 0; i < edges.size(); i++)
    {
        int source = edges[i].source;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
        int parentSource = findParent(source, parent);
        int parentDest = findParent(dest, parent);
        if (parentSource != parentDest)
        {
            result.push_back(edges[i]);
            unionSets(source, dest, parent);
        }
    }
    return result;
}

int main()
{
    int numVertices, numEdges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;
    vector<Edge> edges(numEdges);
    cout << "Enter the edges in the graph:" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        cout << "Edge " << i << "\n";
        cin >> edges[i].source >> edges[i].dest >> edges[i].weight;
    }
    vector<Edge> mst = kruskal(edges, numVertices);
    cout << "The MST is:" << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].source << " " << mst[i].dest << " " << mst[i].weight << endl;
    }
    return 0;
}
