#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void glRotateRight(int x, int y, vector<vector<int>> &matrix) {
  swap(matrix[x][y], matrix[x][y+1]);
  swap(matrix[x][y], matrix[x+1][y+1]);
  swap(matrix[x][y], matrix[x+1][y]);
}

void glRotateLeft(int x, int y, vector<vector<int>> &matrix) {
  swap(matrix[x][y], matrix[x+1][y]);
  swap(matrix[x][y], matrix[x+1][y+1]);
  swap(matrix[x][y], matrix[x][y+1]);
}

bool isSolved(const vector<vector<int>>& grid) {
  int target = 1;
  for (const auto& row : grid) {
    for (int cell : row) {
      if (cell != target) {
        return false;
      }
      target = (target % grid[0].size()) + 1;
    }
  }
  return true;
}

int Vault(int x, int y, vector<vector<int>> &grid, int r, int c, int m, string last) {
  int nMoves = 0;
  if (m > 0) {
    if (last != "R") {
      glRotateLeft(x, y, grid);
      nMoves++;
      last = "L";
    }
    else if (last != "L") {
      glRotateRight(x, y, grid);
      nMoves++;
      last = "R";
    }
    for (int i = 0; i < r-1; i++) {
      for (int j = 0; j < c-1; j++) {
        Vault(x, y, grid, r, c, m-1, last);
        Vault(x+1, y, grid, r, c, m-1, last);
        Vault(x+1, y+1, grid, r, c, m-1, last);
        Vault(x, y+1, grid, r, c, m-1, last);
      }
    }
  }
  return nMoves;
}

int main() {
  int n;
  cin >> n;
  // cout << n << endl;
  vector<vector<int>> grid;
  vector<int> row;
  for (int i = 0; i < n; i++) {
    grid = {};
    int r, c, m;
    cin >> r >> c >> m;
    if (r < 2 || r > 5 || c < 2 || c > 5 || r > c || m < 1 || m > 7)
      return 1;
    // cout << r << " " << c << " " << m << endl;
    for (int j = 0; j < r; j++) {
      row = {};
      for (int k = 0; k < c; k++) {
        int value;
        cin >> value;
        row.push_back(value);
      }
      grid.push_back(row);
    }
    for (const auto& innerVec : grid) {
      for (int element : innerVec) {
        cout << element << " ";
      }
      cout << endl;
    }
    int result = Vault(0, 0, grid, r, c, m, "");
    if (result <= m && isSolved(grid))
      cout << result << endl;
    else 
      cout << "the treasure is lost!" << endl;
  }
  return 0;
}