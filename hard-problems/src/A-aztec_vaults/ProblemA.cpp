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

bool isSorted(const vector<int>& row, int r) {
  for (int i = 0; i < (int) row.size(); ++i) {
    if (row[i] != r + 1) {
      return false;
    }
  }
  return true;
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

void Vault(vector<vector<int>> &grid, int r, int c, int maxMoves, int moves, int &minMoves) {
  if (moves > maxMoves || moves >= minMoves){
    return;
  }

  if (moves <= maxMoves && isSolved(grid)){
    if (moves < minMoves)
      minMoves = moves;
    return;
  }

  int lines_sorted = 0;
  for (int t = r-1; t >= 0; t--){
    if (isSorted(grid[t], t) && lines_sorted == r-1-t){
      lines_sorted++;
    }
  }
  r = r - lines_sorted;
  lines_sorted = 0;
  int done = 0;

  for(int i = 0; i < r-1; i++){
    if (done == 0){
      for (int t = 0; t < r-1; t++){
        done = 1;
        if (isSorted(grid[t], t) && lines_sorted == t){
          lines_sorted++;
        }
      }
      i = lines_sorted;
    }
    for (int j = 0; j < c-1; j++){
      if (grid[i][j] < i - (maxMoves-moves) + 1 || grid[i][j] > i + (maxMoves-moves) + 1) {
        return;
      }
      glRotateRight(i, j, grid);
      Vault(grid, r, c, maxMoves, moves+1, minMoves);

      glRotateRight(i, j, grid);
      Vault(grid, r, c, maxMoves, moves+2, minMoves);

      glRotateRight(i, j, grid);
      Vault(grid, r, c, maxMoves, moves+1, minMoves);
      glRotateRight(i, j, grid);
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid;
  vector<int> row;

  for (int i = 0; i < n; i++) {
    grid = {};
    int r, c, m;
    cin >> r >> c >> m;
    if (r < 2 || r > 5 || c < 2 || c > 5 || r > c || m < 1 || m > 7)
      return 1;
    
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
    Vault(grid, r, c, m, 0, minMoves);
    
    if (minMoves <= m)
      cout << minMoves << endl;
    else 
      cout << "the treasure is lost!" << endl;
  }
  return 0;
}