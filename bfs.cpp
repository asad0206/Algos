#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>> graph, int start, int num_vertices)
{
    vector<bool> visited(num_vertices, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
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
    cout << "Enter the starting vertex for BFS: ";
    cin >> start;
    cout << "BFS traversal starting from vertex " << start << ": ";
    bfs(graph, start, num_vertices);
    cout << endl;
    return 0;
}
