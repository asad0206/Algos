#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> graph, int current, vector<bool> &visited)
{
    visited[current] = true;
    cout << current << " ";
    for (int i = 0; i < graph[current].size(); i++)
    {
        int next = graph[current][i];
        if (!visited[next])
        {
            dfs(graph, next, visited);
        }
    }
}

int main()
{
    int num_vertices, num_edges, start;
    cout << "Enter the number of vertices in the graph: ";
    cin >> num_vertices;
    cout << "Enter the number of edges in the graph: ";
    cin >> num_edges;
    vector<vector<int>> graph(num_vertices);
    cout << "Enter the edges in the graph:" << endl;
    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        cout << "Edge " << i << "\n";
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << "Enter the starting vertex for DFS: ";
    cin >> start;
    vector<bool> visited(num_vertices, false);
    cout << "DFS traversal starting from vertex " << start << ": ";
    dfs(graph, start, visited);
    cout << endl;
    return 0;
}
