#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

struct Node
{
  int cost, x, y;
  bool operator>(const Node &other) const
  {
    return cost > other.cost;
  }
};

int dijkstra_min_path(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  vector<vector<int>> min_cost(n, vector<int>(n, numeric_limits<int>::max()));
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  min_cost[0][0] = matrix[0][0];
  pq.push({matrix[0][0], 0, 0});

  int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  while (!pq.empty())
  {
    Node node = pq.top();
    pq.pop();
    int cost = node.cost, x = node.x, y = node.y;

    if (x == n - 1 && y == n - 1)
      return cost;

    for (auto &dir : directions)
    {
      int nx = x + dir[0], ny = y + dir[1];
      if (nx >= 0 && nx < n && ny >= 0 && ny < n)
      {
        int new_cost = cost + matrix[nx][ny];
        if (new_cost < min_cost[nx][ny])
        {
          min_cost[nx][ny] = new_cost;
          pq.push({new_cost, nx, ny});
        }
      }
    }
  }
  return -1;
}

vector<vector<int>> parse_matrix(const string &filename)
{
  ifstream file(filename);
  vector<vector<int>> matrix;
  string line;
  while (getline(file, line))
  {
    stringstream ss(line);
    vector<int> row;
    string num;
    while (getline(ss, num, ','))
    {
      row.push_back(stoi(num));
    }
    matrix.push_back(row);
  }
  return matrix;
}

int main()
{
  vector<vector<int>> matrix = parse_matrix("matrix.txt");
  cout << "Minimal path sum: " << dijkstra_min_path(matrix) << endl;
  return 0;
}
