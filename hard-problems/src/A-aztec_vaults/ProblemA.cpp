#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
  int numRows = grid.size();
  int numCols = grid[0].size();
  
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (grid[i][j] != (i + 1)) {
        return false;
      }
    }
  }
  
  return true;
}

bool verifyInput(const vector<vector<int>>& grid, int r, int c) {
  unordered_map<int, int> counts;
    for (const auto& row : grid) {
        for (int num : row) {
            counts[num]++;
        }
    }
    for (int i = 1; i <= r; i++) {
        if (counts[i] != c) {
            return false;
        }
    }
  
  return true;
}

void Vault(int x, int y, vector<vector<int>> &grid, int r, int c, int maxMoves, int moves, int &minMoves) {
  if (moves > maxMoves || moves >= minMoves){
    return;
  }

  if (moves <= maxMoves && isSolved(grid)){
    if (moves < minMoves)
      minMoves = moves;
    return;
  }

  for(int i = 0; i < (int) grid.size()-1; i++){
    for (int j = 0; j < (int) grid[0].size()-1; j++){
      
      // rotate right
      glRotateRight(i, j, grid);
      Vault(i, j, grid, r, c, maxMoves, moves+1, minMoves);
      
      // undo rotation
      glRotateLeft(i, j, grid);
      
      // rotate left
      glRotateLeft(i, j, grid);
      Vault(i, j, grid, r, c, maxMoves, moves+1, minMoves);

      // rotate left again
      glRotateLeft(i, j, grid);
      Vault(i, j, grid, r, c, maxMoves, moves+2, minMoves);

      // undo rotations
      glRotateLeft(i, j, grid);
      glRotateLeft(i, j, grid);
    }
  }
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
    if (!verifyInput(grid, r, c)) {
      cout << "the treasure is lost!" << endl;
      continue;
    }

    int minMoves = m + 1;
    Vault(0, 0, grid, r, c, m, 0, minMoves);
    
    if (minMoves <= m)
      cout << minMoves << endl;
    else 
      cout << "the treasure is lost!" << endl;
  }
  return 0;
}

