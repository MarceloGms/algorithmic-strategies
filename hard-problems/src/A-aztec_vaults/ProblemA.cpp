#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<map>
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

int lastThree(queue<int>& q) {
  if (q.size() < 3)
    return 2;

  int first = q.front();
  q.pop();
  if (first == 0) {
    while (!q.empty()) {
      if (q.front() != 0)
        return 2;
      q.pop();
    }
    for (int i = 0; i < 3; i++)
      q.push(0);
    return 0;
  } else if (first == 1) {
    while (!q.empty()) {
      if (q.front() != 1)
        return 2;
      q.pop();
    }
    for (int i = 0; i < 3; i++)
      q.push(1);
    return 1;
  } else return 2;
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

bool verifyInputMoves(const vector<vector<int>>& grid, int r, int c, int moves) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] < i - moves + 1 || grid[i][j] > i + moves + 1) {
        return false;
      }
    }
  }
  return true;
}

void Vault(int x, int y, vector<vector<int>> &grid, int r, int c, int maxMoves, int moves, int &minMoves, 
                                                                    map<pair<int, int>, queue<int>> &history) {
  if (moves > maxMoves || moves >= minMoves){
    return;
  }

  if (moves <= maxMoves && isSolved(grid)){
    if (moves < minMoves)
      minMoves = moves;
    return;
  }

  /* if (verifyInputMoves(grid, r, c, maxMoves - moves) == false){
    return;
  } */

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
      // int key = x * c + y;
      auto h = history.find({i,j});
      // 0 -> left, 1 -> right
      int last = lastThree(h->second);
      if (h == history.end() || h->second.empty() ||  h->second.back() != 0) {
        if (last != 1) {
          // rotate right
          glRotateRight(i, j, grid);
          Vault(i, j, grid, r, c, maxMoves, moves+1, minMoves, history);
          
          // undo rotation
          glRotateLeft(i, j, grid);
          if (h == history.end()) 
            history[{i,j}] = queue<int>();

          history[{i,j}].push(1);
          if (history[{i,j}].size() > 3)
            history[{i,j}].pop();
        }
      }
      
      if (h == history.end() || h->second.empty() || h->second.back() != 1) {
        if (last != 0) {
          // rotate left
          glRotateLeft(i, j, grid);
          Vault(i, j, grid, r, c, maxMoves, moves+1, minMoves, history);

          // undo rotation
          glRotateRight(i, j, grid);
          if (h == history.end())
            history[{i,j}] = queue<int>();

          history[{i,j}].push(0);
          if (history[{i,j}].size() > 3)
            history[{i,j}].pop();
        }
      }
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

    // 0 -> left, 1 -> right
    map<pair<int, int>, queue<int>> history;
    int minMoves = m + 1;
    Vault(0, 0, grid, r, c, m, 0, minMoves, history);
    
    if (minMoves <= m)
      cout << minMoves << endl;
    else 
      cout << "the treasure is lost!" << endl;
  }
  return 0;
}