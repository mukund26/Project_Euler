#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <sstream>
using namespace std;

typedef pair<int, int> ii;

vector<vector<int>> readFile() {
  fstream file("matrix.txt");
  vector<vector<int>> matrix;
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    vector<int> row;
    string num;
    while (getline(ss, num, ',')) {
      row.push_back(stoi(num));
    }
    matrix.push_back(row);
  }
  return matrix;
}

int main() {

  vector<vector<int>> matrix = readFile();

  // vector<vector<int>> matrix = {
  //   {131, 673, 234, 103, 18},
  //   {201, 96, 342, 965, 150},
  //   {630, 803, 746, 422, 111},
  //   {537, 699, 497, 121, 956},
  //   {805, 732, 524, 37, 331}
  // };

  priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> q;

  int n = matrix.size();
  vector<vector<int>> min_cost(n, vector<int>(n, numeric_limits<int>::max()));

  for (int i = 0; i < n; i++) {
    q.push({matrix[i][0], {i, 0}});
  }

  int dir[3][2] = {{0, 1},{1, 0}, {-1, 0}};

  int ans = INT_MAX;

  while (!q.empty()) {
    pair<int, ii> p = q.top();
    q.pop();

    int cost = p.first;
    int x = p.second.first;
    int y = p.second.second;

    if (y == n - 1) {
      ans = cost;
      break;
    }

    for (auto &d: dir) {
      int nx = x + d[0];
      int ny = y + d[1];

      if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
        int new_cost = cost + matrix[nx][ny];
        if (new_cost < min_cost[nx][ny]) {
          min_cost[nx][ny] = new_cost;
          q.push({new_cost, {nx, ny}});
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}